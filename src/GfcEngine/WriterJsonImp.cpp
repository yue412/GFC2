#include "WriterJsonImp.h"
#include <Windows.h>
#include <sstream>
#include <time.h>
#include <io.h>
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\EnumType.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\JsonSerializerUtils.h"
#include "GfcEngine\Container.h"
#include "Common.h"
#include <iomanip>
#include <algorithm>

#include "rapidjson/document.h"


GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_OBJECT(CWriterJsonImp, L"json", 0)

CWriterJsonImp::CWriterJsonImp(void):m_pJsonStream(0),m_pDocument(NULL), m_pRootDocument(NULL)
{
}


CWriterJsonImp::~CWriterJsonImp(void)
{
    close();
}

bool CWriterJsonImp::open( const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion, const std::wstring& sStandardVersion)
{
    std::string sFile = UnicodeToACP(sFileName);
	if (-1 != _access(sFile.c_str(), 0))
	{
		remove(sFile.c_str());
	}
    m_pJsonStream = new std::fstream(sFileName,std::ios::out | std::ios::app);

    m_pDocument = new rapidjson::Document();
    m_pRootDocument = new JsonWrapper(m_pDocument);

    m_pRootDocument->AddEmptySubObject("header");
    JsonWrapper json = (*m_pRootDocument)["header"];
    writeHead(json, sFileName, sProductCode, sVersion, sStandardVersion);

    std::string d = m_pRootDocument->ToString();

    m_pRootDocument->AddEmptySubArray("data");

    return true;
}

void CWriterJsonImp::close()
{
    if (m_pJsonStream)
    {
        std::string data = m_pRootDocument->ToString();
        *m_pJsonStream << data;

        m_pJsonStream->flush();
		m_pJsonStream->close();
        delete m_pJsonStream;
        m_pJsonStream = NULL;
    }

    if(m_pDocument){
        delete m_pDocument;
        m_pDocument = NULL;
    }
    if(m_pRootDocument){
        delete m_pRootDocument;
        m_pRootDocument = NULL;
    }
}

void CWriterJsonImp::doWriteEntity(EntityRef nId, CEntity * pEntity)
{
    if (m_pJsonStream)
    {
        assert(pEntity->ref() != -1);
        JsonWrapper data = (*m_pRootDocument)["data"];
        JsonWrapper obj(data.GetAllocator(), rapidjson::kObjectType);

        CJsonSerializerUtils::writeEntity(obj, pEntity, m_nCodePage);

        data.Add(obj);
//        return pEntity->ref();
    }
}

void CWriterJsonImp::writeHead(JsonWrapper& rootJson, const std::wstring& sFileName,const std::wstring& sProductCode, const std::wstring& sVersion, const std::wstring& sStandardVersion)
{
    rootJson.Add("FILE_SCHEMA", toString(sVersion));
}

std::string CWriterJsonImp::toString(const std::wstring & str)
{
    return WStringToMBString(str, m_nCodePage);
}

GFCENGINE_NAMESPACE_END