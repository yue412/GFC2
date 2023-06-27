#include "WriterTextImp.h"
#if (defined _WIN32 || defined _WIN64)
#include <Windows.h>
#include <io.h>
#else
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#endif
#include <sstream>
#include <time.h>
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/EnumType.h"
#include "GfcEngine/PropValue.h"
#include "Common.h"
#include <iomanip>
#include <algorithm>

std::string getUserName()
{
#if (defined _WIN32 || defined _WIN64)
    unsigned long size = 0;
    std::string sName;
    GetUserName(NULL, &size);
    wchar_t *name = new wchar_t[size];
    if (GetUserName(name, &size))
    {
        unsigned long dwNum = WideCharToMultiByte(CP_OEMCP, NULL, name, -1, NULL, 0, NULL, false);
        char *psText;
        psText = new char[dwNum];
        WideCharToMultiByte(CP_OEMCP, NULL, name, -1, psText, dwNum, NULL, FALSE);
        sName = psText;
        delete[]psText;
    }
    delete[] name;
    return sName;
#else
    uid_t userid;
    struct passwd* pwd;
    userid = getuid();
    pwd = getpwuid(userid);
    return pwd->pw_name;
#endif
}

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_OBJECT(CWriterTextImp, L"express", 0)

CWriterTextImp::CWriterTextImp(void):m_pTextStream(0)
{
    m_nCount = 1;
}


CWriterTextImp::~CWriterTextImp(void)
{
    close();
}

bool CWriterTextImp::open( const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion, const std::wstring& sStandardVersion)
{
#if (defined _WIN32 || defined _WIN64)
    if (-1 != _waccess(sFileName.c_str(), 0))
    {
        _wremove(sFileName.c_str());
    }
    m_pTextStream = new std::fstream(sFileName, std::ios::out | std::ios::app);
#else
    std::string sFile = UnicodeToUtf8(sFileName);
    if (-1 != access(sFile.c_str(), 0))
    {
        //删除文件
        remove(sFile.c_str());
    }
    m_pTextStream = new std::fstream(sFile, std::ios::out | std::ios::app);
#endif
    writeHead(sFileName, sProductCode, sVersion, sStandardVersion);
    *m_pTextStream << "DATA;" << std::endl;
    return true;
}

void CWriterTextImp::close()
{
    if (m_pTextStream)
    {
        *m_pTextStream << "ENDSEC;" << std::endl;
        m_pTextStream->flush();
		m_pTextStream->close();
        delete m_pTextStream;
        m_pTextStream = NULL;
    }
    m_nCount = 0;
}

void CWriterTextImp::doWriteEntity(EntityRef nId, CEntity * pEntity)
{
    if (m_pTextStream)
    {
        CWriterTextUtils::writeEntity(*m_pTextStream, pEntity, nId, m_nCodePage, m_bUppercase);
        *m_pTextStream << std::endl;
    }
}

void CWriterTextImp::writeHead( const std::wstring& sFileName,const std::wstring& sProductCode, const std::wstring& sVersion, const std::wstring& sStandardVersion)
{
	time_t current;
	time(&current);
	char charTime[64];
	strftime(charTime, sizeof(charTime), "%Y-%m-%d %H:%M:%S",localtime(&current) );

    std::stringstream stream;
	stream<< "HEADER;" << std::endl;
	stream<<"FILE_DESCRIPTION(('"<< toString(sStandardVersion.empty() ? sVersion : sStandardVersion) <<"'),'" << m_nCodePage << "');"<< std::endl;
	stream<<"FILE_NAME('"<< toString(sFileName)<<"','"<<charTime<<"',('"<<getUserName()<<"'),('Glodon'),'objectbuf','"<< toString(sProductCode)<<"','');"<< std::endl;
	stream<<"FILE_SCHEMA(('"<< toString(sVersion) <<"'));"<< std::endl;
	*m_pTextStream<<stream.str();
    *m_pTextStream << "ENDSEC;" << std::endl;
}

std::string CWriterTextImp::toString(const std::wstring & str)
{
    return WStringToMBString(str, m_nCodePage);
}

void CWriterTextUtils::writeEntity(std::iostream & out, CEntity * pEntity, EntityRef nRef, unsigned int nCodePage, bool bUppercase)
{
    auto sEntityName = bUppercase ? UpperString(pEntity->entityName()) : pEntity->entityName();
    std::string sName = WStringToMBString(sEntityName, nCodePage);
    out << "#" << nRef << "=" << sName << "(";
    if (pEntity->getPropCount() > 0)
    {
        for (int i = 0; i < pEntity->getPropCount() - 1; i++)
        {
            auto pProp = pEntity->getProps(i);
            writeProperty(out, pProp, nCodePage);
            out << ",";
        }
        writeProperty(out, pEntity->getProps(pEntity->getPropCount() - 1), nCodePage);
    }
    out << ");";
}

void CWriterTextUtils::writeValue(std::iostream & out, gfc::schema::CTypeObject * pType, CPropValue * pValue, unsigned int nCodePage)
{
    auto nType = pType->getDataType();
    switch (nType)
    {
    case gfc::schema::EDT_BOOLEAN:
        out << (pValue->asBoolean() ? ".T." : ".F.");
        break;
    case gfc::schema::EDT_INTEGER:
        out << pValue->asInteger();
        break;
    case gfc::schema::EDT_DOUBLE:
        out << std::setprecision(15) << pValue->asDouble();
        break;
    case gfc::schema::EDT_STRING:
        out << "'" << transString(WStringToMBString(pValue->asString(), nCodePage)).c_str() << "'";
        break;
    case gfc::schema::EDT_ENUM:
    {
        auto pEnumType = dynamic_cast<gfc::schema::CEnumType*>(pType->getBaseType());
        std::string str = "$";
        if (pEnumType && pEnumType->getEnumCount() > 0)
        {
            auto n = pValue->asInteger() % pEnumType->getEnumCount();
            if (n < 0)
                n += pEnumType->getEnumCount();
            str = "." + WStringToMBString(pEnumType->getEnum(n), nCodePage) + ".";
        }
        out << str.c_str();
    }
    break;
    case gfc::schema::EDT_ENTITY:
        out << "#" << pValue->asEntityRef();
        break;
    default:
        break;
    }
}

void CWriterTextUtils::writeProperty(std::iostream & out, CProperty * pProp, unsigned int nCodePage)
{
    auto pSchema = pProp->schema();
    auto pType = pSchema->getType();
    if (pSchema->getRepeatFlag())
    {

        auto pValue = pProp->value();
        if (pValue->getCount() == 0)
        {
            out << "$";
        }
        else
        {
            out << "(";
            for (int j = 0; j < pValue->getCount() - 1; ++j)
            {
                writeValue(out, pType, pValue->getItems(j), nCodePage);
                out << ",";
            }
            writeValue(out, pType, pValue->getItems(pValue->getCount() - 1), nCodePage);
            out << ")";
        }
    }
    else
    {
        if (pProp->value()->isNull())
            out << "$";
        else
            writeValue(out, pType, pProp->value(), nCodePage);
    }

}

GFCENGINE_NAMESPACE_END