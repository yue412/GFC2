#include "WriterTextImp.h"
#include <Windows.h>
#include <sstream>
#include <time.h>
#include <io.h>
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\EnumType.h"
#include "GfcEngine\PropValue.h"
#include "Common.h"
#include <iomanip>
#include <algorithm>

std::string getUserName()
{
     DWORD size=0;
     std::string sName;
     GetUserName(NULL,&size);
    wchar_t *name=new wchar_t[size];
    if(GetUserName(name,&size))
    {
		DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,name,-1,NULL,0,NULL,false);
		char *psText;
		psText = new char[dwNum];
		WideCharToMultiByte (CP_OEMCP,NULL,name,-1,psText,dwNum,NULL,FALSE);
		sName = psText;
		delete []psText;
    }
    delete [] name;
    return sName;
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

bool CWriterTextImp::open( const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion)
{
    std::string sFile = toString(sFileName);
	if (-1 != _access(sFile.c_str(), 0))
	{
		//É¾³ýÎÄ¼þ
		remove(sFile.c_str());
	}

    m_pTextStream = new std::fstream(sFileName,std::ios::out | std::ios::app);
    writeHead(sFileName, sProductCode, sVersion);
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

EntityRef CWriterTextImp::writeEntity( CEntity* pEntity )
{
    if (m_pTextStream)
    {
        CWriterTextUtils::writeEntity(*m_pTextStream, pEntity, m_nCount);
        *m_pTextStream << std::endl;
        return m_nCount++;
    }
    return -1;
}

void CWriterTextImp::writeHead( const std::wstring& sFileName,const std::wstring& sProductCode, const std::wstring& sVersion)
{
	time_t current;
	time(&current);
	char charTime[64];
	strftime(charTime, sizeof(charTime), "%Y-%m-%d %H:%M:%S",localtime(&current) );

    std::stringstream stream;
	stream<< "HEADER;" << std::endl;
	stream<<"FILE_DESCRIPTION(('"<< toString(sVersion) <<"'),'');"<< std::endl;
	stream<<"FILE_NAME('"<< toString(sFileName)<<"','"<<charTime<<"',('"<<getUserName()<<"'),('Glodon'),'objectbuf','"<< toString(sProductCode)<<"','');"<< std::endl;
	stream<<"FILE_SCHEMA(('"<< toString(sVersion) <<"'));"<< std::endl;
	*m_pTextStream<<stream.str();
    *m_pTextStream << "ENDSEC;" << std::endl;
}

void CWriterTextUtils::writeEntity(std::iostream & out, CEntity * pEntity, EntityRef nRef)
{
    std::string sName = toString(pEntity->entityName());
    out << "#" << nRef << "=" << sName << "(";
    if (pEntity->getPropCount() > 0)
    {
        for (int i = 0; i < pEntity->getPropCount() - 1; i++)
        {
            auto pProp = pEntity->getProps(i);
            writeProperty(out, pProp);
            out << ",";
        }
        writeProperty(out, pEntity->getProps(pEntity->getPropCount() - 1));
    }
    out << ");";
}

std::string transString(const std::string& sStr)
{
    std::string sResult;
    for(auto itr = sStr.begin(); itr != sStr.end(); ++itr) {
        switch (*itr)
        {
        case '\'':
            sResult.push_back('\\');
            sResult.push_back('\'');
            break;
        case '\n':
            sResult.push_back('\\');
            sResult.push_back('n');
            break;
        case '\r':
            sResult.push_back('\\');
            sResult.push_back('r');
            break;
        case '\\':
            sResult.push_back('\\');
            sResult.push_back('\\');
            break;
        default:
            sResult.push_back(*itr);
            break;
        }
    };
    return sResult;
}

void CWriterTextUtils::writeValue(std::iostream & out, gfc::schema::CTypeObject * pType, CPropValue * pValue)
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
        out << "'" << transString(UnicodeToUtf8(pValue->asString())).c_str() << "'";
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
            str = "." + UnicodeToUtf8(pEnumType->getEnum(n)) + ".";
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

void CWriterTextUtils::writeProperty(std::iostream & out, CProperty * pProp)
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
                writeValue(out, pType, pValue->getItems(j));
                out << ",";
            }
            writeValue(out, pType, pValue->getItems(pValue->getCount() - 1));
            out << ")";
        }
    }
    else
    {
        if (pProp->value()->isNull())
            out << "$";
        else
            writeValue(out, pType, pProp->value());
    }

}

GFCENGINE_NAMESPACE_END