#include "ReaderBinaryImp.h"
#include <fstream>
#include <sstream>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/wire_format_lite.h>
//#include <google/protobuf/wire_format_lite_inl.h>
#include "glodon/objectbuf/EntitySchema.h"
#include "glodon/objectbuf/Document.h"
#include "FieldCacheInitializer.h"
#include "glodon/framework/OBObjectFactory.h"
#include "glodon/objectbuf/EntityBinarySerializer.h"
#include "EntitySchemaBinarySerializer.h"

namespace glodon {
namespace objectbuf {

ReaderBinaryImp::ReaderBinaryImp(/*SchemaInfoMap* pSchemaInfoMap*/)/*: ReaderImp(pSchemaInfoMap)*/
{
}


ReaderBinaryImp::~ReaderBinaryImp(void)
{
}

bool ReaderBinaryImp::read( const string& sFileName, Document* pDoc,std::vector<std::string>& errors )
{
    m_oFactoryList.clear();
    std::fstream in(sFileName, std::ios::in | std::ios::binary);
    {
        google::protobuf::io::IstreamInputStream zero_copy_input(&in);
        google::protobuf::io::CodedInputStream input(&zero_copy_input);
        while(true/*!input.ExpectAtEnd()*/)
        {
            google::protobuf::int32 nTypeId = input.ReadTag();
            google::protobuf::int32 nSize = 0;
            google::protobuf::int32 nId = 0;

            if (nTypeId == 0) // 流读完了
                break;
            //             if (!google::protobuf::internal::WireFormatLite::ReadPrimitive<
            //                 google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(&input, &nTypeId))
            //                 return false;

            if (!google::protobuf::internal::WireFormatLite::ReadPrimitive<
                google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(&input, &nId))
                return false;

            if (!google::protobuf::internal::WireFormatLite::ReadPrimitive<
                google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(&input, &nSize))
                return false;

            bool bResult = false;
            google::protobuf::io::CodedInputStream::Limit nLimit = input.PushLimit(nSize);
            if (nTypeId == 1)
            {
                EntitySchema oSchema;
                EntitySchemaBinarySerializer oSchemaSerializer;
                bResult = oSchemaSerializer.parse(&input, &oSchema);
                if (bResult)
                {
                    //auto oItr = m_pSchemaInfoMap->find(oSchema.getName());
                    FieldCacheInitializer* pInitializer = (FieldCacheInitializer*)FieldCacheInitializer::GetFactory()->Create(oSchema.getName());
                    auto pFactory = Entity::GetFactory()->FindCreateHelper(oSchema.getName());
                    //if (oItr != m_pSchemaInfoMap->end())
                    {
                        // 该schema有对应的工厂
                        //if (oItr->second.first)
                        if (pFactory != NULL && pFactory->GetFunPtr() != NULL)
                        {
                            // 判断有没有初始化
                            auto oItr1 = m_oFactoryList.find(oSchema.getId());
                            if (oItr1 == m_oFactoryList.end())
                            {
                                m_oFactoryList.insert(std::make_pair(oSchema.getId(), pFactory->GetFunPtr()));
                            }
                        }
                        // 是否需要初始化字段id
                        if (pInitializer/*oItr->second.second*/)
                        {
                            // 初始化字段Id
                            int nCount = oSchema.getAttribNamesCount();
                            std::map<string, int> oFieldIdMap;
                            for (int i = 0; i < nCount; ++i)
                            {
								stringstream sstream;
								sstream<<oSchema.getName()<<"::"<<oSchema.getAttribNames(i);
								oFieldIdMap.insert(std::make_pair(sstream.str(),oSchema.getAttribIds(i)));
//                                 oFieldIdMap.insert(std::make_pair(string("%1::%2").arg(oSchema.getName()).arg(oSchema.getAttribNames(i)), 
//                                     oSchema.getAttribIds(i)));
                            }
                            //FieldCacheInitializer* pInitializer = oItr->second.second;
                            pInitializer->init(oFieldIdMap);
                            delete pInitializer;
                        }
                    }    
                }
            }
            else
            {
                auto oItr = m_oFactoryList.find(nTypeId);
                if (oItr == m_oFactoryList.end())
                    continue;
                Entity* pEntity = (Entity*)oItr->second();//oItr->second->create();
				pEntity->setDocument(pDoc);
                string sName = pEntity->entityName();
                EntityBinarySerializer* pSerializer = (EntityBinarySerializer*)EntityBinarySerializer::GetFactory()->Create(sName + "B");
                if (pEntity && pSerializer)
                {
                    bResult = pSerializer->parse(&input, pEntity);
                    delete pSerializer;
                    if (bResult)
                    {
                        if (!pDoc->getNeedAddEntityFunc() || pDoc->getNeedAddEntityFunc()(pDoc, nId, pEntity))
                        {
                            pDoc->add(nId, pEntity);
                        }
                        else
                        {
                            delete pEntity;
                        }
                    }
                }
                else
                {
                    bResult = false;
                }
            }
            input.PopLimit(nLimit);
            if (!bResult)
            {
                return false;
            }
        }
        if (pDoc->getAfterReadDocFunc())
        {
            pDoc->getAfterReadDocFunc()(pDoc);
        }
    }
    return true;
}


}
}