#include "glodon/objectbuf/Reader.h"
#include <assert.h>
#include <fstream>
#include "glodon/objectbuf/Document.h"
#include "ReaderImp.h"
//#include "ReaderTextImp.h"
//#include "ReaderBinaryImp.h"

namespace glodon {
namespace objectbuf {

Reader::Reader(/*RegSchemaInfoProc pProc, */FieldCacheProc pInitProc, FieldCacheProc pFreeProc)
{
    //assert(pProc);
    assert(pInitProc);
    assert(pFreeProc);
//     if (pProc)
//     {
//         // 初始化工厂
//         pProc(this);
//     }
    if (pInitProc)
        pInitProc();

    m_pFreeProc = pFreeProc;
}


Reader::~Reader(void)
{
    clear();

    if (m_pFreeProc)
        m_pFreeProc();
}

void Reader::clear()
{
//     for (auto itr = m_oSchemaInfoMap.begin(); itr != m_oSchemaInfoMap.end(); ++itr)
//     {
//         delete itr->second.first;
//         delete itr->second.second;
//     }
//     m_oSchemaInfoMap.clear();
}

bool Reader::read( const string& sFileName, Document* pDoc )
{
    //
    ////glodon::objectbuf::Entity::setDocument(pDoc);
    //ReaderImp* pImp = NULL;
    //if (isBinaryFile(sFileName))
    //{
    //    // binary
    //    pImp = new ReaderBinaryImp(/*&m_oSchemaInfoMap*/);
    //}
    //else
    //{
    //    // text
    //    pImp = new ReaderTextImp(/*&m_oSchemaInfoMap*/);
    //}
    //bool bSucc = pImp->read(sFileName, pDoc,errors);
    //pDoc->linkSchemaByParent();
    //return bSucc;
    return false;
}

string Reader::getProjectId(const string& sFileName)
{
	//ReaderTextImp* pImp = new ReaderTextImp();
	//return pImp->projectId(sFileName);
    return "";
}


std::vector<std::string> Reader::log()
{
	return errors;
}

std::string Reader::version()
{
	return std::string();
}

bool Reader::isBinaryFile( const string &sFileName )
{
    char sHead[8];
    std::fstream in(sFileName, std::ios::in | std::ios::binary);
    in.get(sHead, 8);
    sHead[7] = 0;
    in.close();
    return strcmp(sHead, "HEADER;") != 0;
}

}
}
