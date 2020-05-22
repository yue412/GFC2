#include "GfcEngine/Reader.h"
#include <assert.h>
#include <fstream>
#include "GfcEngine/Document.h"
#include "ReaderImp.h"
#include "SerializerManager.h"
//#include "ReaderTextImp.h"
//#include "ReaderBinaryImp.h"

GFCENGINE_NAMESPACE_BEGIN

Reader::Reader()
{
}


Reader::~Reader(void)
{
}

bool Reader::read(const string& sFileName, Document* pDoc)
{
    //gfc2::engine::Entity::setDocument(pDoc);
    m_pSerializerManager = SerializerManager::getInstance();
    for (int i = 0; i < m_pSerializerManager->getCount(); i++)
    {
        ReaderImp* pImp = m_pSerializerManager->getReaderImp(i);
        if (pImp->preRead(sFileName))
        {
            bool bSucc = pImp->read(sFileName, pDoc, m_oErrors);
            pDoc->linkSchemaByParent();
            return bSucc;
        }
    }
    return false;
}

//bool Reader::isBinaryFile(const string &sFileName)
//{
//    char sHead[8];
//    std::fstream in(sFileName, std::ios::in | std::ios::binary);
//    in.get(sHead, 8);
//    sHead[7] = 0;
//    in.close();
//    return strcmp(sHead, "HEADER;") != 0;
//}

GFCENGINE_NAMESPACE_END