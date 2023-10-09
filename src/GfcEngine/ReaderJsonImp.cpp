#include "ReaderJsonImp.h"
#include "FileMap.h"
#include "GfcSchema/Model.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/EnumType.h"
#include "Common.h"
#include "GfcEngine/Entity.h"
#include "GfcEngine/PropValue.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/GfcEngineUtils.h"
#include "GfcEngine/JsonSerializerUtils.h"
#include <fstream>
#include <stack>
#include <algorithm>

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_OBJECT(CReaderJsonImp, L"json", 0)

CReaderJsonImp::CReaderJsonImp(/*SchemaInfoMap* pSchemaInfoMap*/): m_pDocument(NULL), m_pRootDocument(NULL)
{
}


CReaderJsonImp::~CReaderJsonImp(void)
{
    if(m_pDocument){
        delete m_pDocument;
        m_pDocument = NULL;
    }
    if(m_pRootDocument){
        delete m_pRootDocument;
        m_pRootDocument = NULL;
    }
}

bool CReaderJsonImp::preRead(const std::wstring& sFileName)
{
    char sHead[2];
#if (defined _WIN32 || defined _WIN64)
    std::fstream in(sFileName, std::ios::in | std::ios::binary);
#else
    auto sFile = UnicodeToUtf8(sFileName);
    std::fstream in(sFile, std::ios::in | std::ios::binary);
#endif
    in.get(sHead, 2);
    sHead[1] = 0;
    in.close();
    return strcmp(sHead, "{") == 0;
}


bool CReaderJsonImp::open(const std::wstring& sFileName){
    assert(schema());
    if (schema() == nullptr)
        return false;
    
    initRootDocument(sFileName);
    initUpgrader(); // schema match
    return true;
}

JsonWrapper* CReaderJsonImp::getRootDocument(){
   
    return m_pRootDocument;
}

bool CReaderJsonImp::initRootDocument(const std::wstring& sFileName){
    assert(!m_pRootDocument);
	
	//std::ifstream in(sFileName);
    auto sFile = UnicodeToUtf8(sFileName);
    std::ifstream in(sFile);
	std::istreambuf_iterator<char> beg(in), end;
	std::string content(beg, end);

    m_pDocument = new rapidjson::Document();
    m_pRootDocument = new JsonWrapper(m_pDocument);
    bool ret = m_pRootDocument->Parse(content);
	assert(ret);
    return ret;
}

std::wstring CReaderJsonImp::readFileVersion()
{
    JsonWrapper* pRootDocument = getRootDocument();
    assert(pRootDocument);
    if(!pRootDocument){
        return L"";
    }

    JsonWrapper header(pRootDocument->GetAllocator());
    if(pRootDocument->Get("header", header)){
        std::string sResult;
        if (header.Get("FILE_SCHEMA", sResult))
        {
            std::replace(sResult.begin(), sResult.end(), L'.', L'X');
            return Utf8ToUnicode(sResult);
        }
    }

    return L"";
}

std::wstring CReaderJsonImp::readStandardVersion()
{
    return L"";
}

std::wstring CReaderJsonImp::readProductCode()
{
    return L"";
}

void CReaderJsonImp::read(CDocument* pDoc){
    assert(pDoc);
    JsonWrapper* pRootDocument = getRootDocument();
    assert(pRootDocument);
    if(!pRootDocument){
        return;
    }

    JsonWrapper data(pRootDocument->GetAllocator());
    bool ret = pRootDocument->Get("data", data);
    if(!ret || !data.IsArray()){
        assert(false);
        return;
    }

    int len = data.GetArraySize();
    for (int i = 0; i < len; i++)
    {
        JsonWrapper json(data.GetAllocator());

        data.Get(i, json);
        CJsonSerializerUtils::parseEntity(m_bUseStaticClass ? NULL : schema(), pDoc, json);
    }
}

GFCENGINE_NAMESPACE_END