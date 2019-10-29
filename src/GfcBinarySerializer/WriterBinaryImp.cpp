#include "WriterBinaryImp.h"
#include "glodon/objectbuf/EntitySchema.h"
#include <google/protobuf/wire_format_lite.h>
//#include <google/protobuf/wire_format_lite_inl.h>
#include "glodon/objectbuf/EntityBinarySerializer.h"
#include "tinyxml.h"

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) glodon::objectbuf::WriterImp* CreateWriterImp(TiXmlElement* pNode)
{
    return new glodon::objectbuf::WriterBinaryImp;
}

__declspec(dllexport) void FreeWriterImp(glodon::objectbuf::WriterImp* pImp)
{
    delete pImp;
}

#ifdef __cplusplus
}
#endif

namespace glodon {
namespace objectbuf {

WriterBinaryImp::WriterBinaryImp(void): m_pFileStream(NULL), m_pZeroCopyStream(NULL), m_pCodedOutputStream(NULL)
{
}


WriterBinaryImp::~WriterBinaryImp(void)
{
    close();
}

bool WriterBinaryImp::open( const string& sFileName, const string& sProductCode )
{
    if (m_pFileStream)
    {
        close();
    }
    m_pFileStream = new std::fstream(sFileName, std::ios::out | std::ios::binary | std::ios::trunc);
    m_pZeroCopyStream = new google::protobuf::io::OstreamOutputStream(m_pFileStream);
    m_pCodedOutputStream = new google::protobuf::io::CodedOutputStream(m_pZeroCopyStream);
    return true;
}

void WriterBinaryImp::close()
{
    delete m_pCodedOutputStream;
    m_pCodedOutputStream = NULL;
    delete m_pZeroCopyStream;
    m_pZeroCopyStream = NULL;
    if (m_pFileStream)
    {
        m_pFileStream->close();
    }
    delete m_pFileStream;
    m_pFileStream = NULL;
    m_oTypeMap.clear();
    m_nCount = 0;
}

glodon::objectbuf::EntityRef WriterBinaryImp::writeEntity( Entity* pEntity )
{
    if (m_pCodedOutputStream)
    {
         auto oItr = m_oTypeMap.find(pEntity->typeId());
         if (oItr == m_oTypeMap.end())
         {
            EntitySchema* pSchema = pEntity->createSchema();
            writeSchema(pSchema);
            //delete pSchema;

//             std::vector<glodon::objectbuf::EntitySchema*> oSchemaList;
//             pEntity->getValueTypeSchemas(oSchemaList);
//             for (auto itr = oSchemaList.begin(); itr != oSchemaList.end(); ++itr)
//             {
//                 writeSchema(*itr);
//                 delete *itr;
//             }
//             oSchemaList.clear();
        }
        string sName = pEntity->entityName();
        EntityBinarySerializer* pSerializer = (EntityBinarySerializer*) EntityBinarySerializer::GetFactory()->Create(sName + "B");
        assert(pSerializer);
        if (pSerializer)
        {
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEntity->typeId(), m_pCodedOutputStream);
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(m_nCount, m_pCodedOutputStream);
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pSerializer->byteSize(pEntity), m_pCodedOutputStream);
            pSerializer->serialize(m_pCodedOutputStream, pEntity);
            delete pSerializer;
            return m_nCount++;
        }
    }
    return -1;
}

void WriterBinaryImp::writeSchema( EntitySchema* pSchema )
{
    if (!pSchema)
    {
        return;
    }
    auto oItr = m_oTypeMap.find(pSchema->getId());
    if (oItr == m_oTypeMap.end())
    {
        // ÏÈÐ´¸¸
        writeSchema(pSchema->getParent());
        // 
        EntityBinarySerializer* pSerializer = (EntityBinarySerializer*) EntityBinarySerializer::GetFactory()->Create("EntitySchemaB");
        assert(pSerializer);
        if (pSerializer)
        {
            m_oTypeMap.insert(std::make_pair(pSchema->getId(), true));
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pSchema->typeId(), m_pCodedOutputStream);
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(m_nCount, m_pCodedOutputStream);
            ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pSerializer->byteSize(pSchema), m_pCodedOutputStream);
            pSerializer->serialize(m_pCodedOutputStream, pSchema);
            delete pSerializer;
            m_nCount++;
        }
    }
}

}
}