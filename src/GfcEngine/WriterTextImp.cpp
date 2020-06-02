#include "WriterTextImp.h"
#include <Windows.h>
#include <sstream>
#include <time.h>
#include <io.h>
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "EnumType.h"
#include "GfcEngine\PropValue.h"
#include "Common.h"

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

GFCENGINE_IMP_OBJECT(WriterTextImp, L"express", 0)

WriterTextImp::WriterTextImp(void):m_pTextStream(0)
{
    m_nCount = 1;
}


WriterTextImp::~WriterTextImp(void)
{
    close();
}

bool WriterTextImp::open( const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion)
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

void WriterTextImp::close()
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

EntityRef WriterTextImp::writeEntity( Entity* pEntity )
{
    if (m_pTextStream)
    {
        std::string sName = toString(pEntity->entityName());
        *m_pTextStream << "#" << m_nCount << "=" << sName << "(";
        for (int i = 0; i < pEntity->getPropCount()-1; i++)
        {
            auto pProp = pEntity->getProps(i);
            writeProperty(pProp);
            *m_pTextStream << ",";
        }
        writeProperty(pEntity->getProps(pEntity->getPropCount() - 1));
        *m_pTextStream << ");" << std::endl;
        return m_nCount++;
    }
    return -1;
}

void WriterTextImp::writeHead( const std::wstring& sFileName,const std::wstring& sProductCode, const std::wstring& sVersion)
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

void WriterTextImp::writeValue(gfc2::schema::CAttribute* pSchema, PropValue* pValue)
{
    auto nType = pSchema->getType()->getDataType();
    switch (nType)
    {
    case gfc2::schema::EDT_BOOLEAN:
        *m_pTextStream << pValue->asBoolean() ? ".T." : ".F.";
        break;
    case gfc2::schema::EDT_INTEGER:
        *m_pTextStream << pValue->asInteger();
        break;
    case gfc2::schema::EDT_DOUBLE:
        *m_pTextStream << pValue->asDouble();
        break;
    case gfc2::schema::EDT_STRING:
        *m_pTextStream << pValue->asString().c_str();
        break;
    case gfc2::schema::EDT_ENUM:
        {
        auto pEnumType = dynamic_cast<gfc2::schema::CEnumType*>(pSchema->getType()->getBaseType());
        std::string str = "$";
        if (pValue->asInteger() < pEnumType->getEnumCount())
            str = "." + toString(pEnumType->getEnum(pValue->asInteger())) + ".";
        *m_pTextStream << str.c_str();
        }
        break;
    case gfc2::schema::EDT_ENTITY:
        *m_pTextStream << "#" << pValue->asEntityRef();
        break;
    default:
        break;
    }
}

void WriterTextImp::writeProperty(Property * pProp)
{
    auto pSchema = pProp->schema();
    if (pSchema->getRepeatFlag())
    {

        auto pValue = pProp->value();
        if (pValue->getCount() == 0)
        {
            *m_pTextStream << "$";
        }
        else
        {
            *m_pTextStream << "(";
            for (int j = 0; j < pValue->getCount() - 1; ++j)
            {
                writeValue(pSchema, pValue->getItems(j));
                *m_pTextStream << ",";
            }
            writeValue(pSchema, pValue->getItems(pValue->getCount() - 1));
            *m_pTextStream << ")";
        }
    }
    else
    {
        if (pProp->value()->isNull())
            *m_pTextStream << "$";
        else
            writeValue(pSchema, pProp->value());
    }
}

GFCENGINE_NAMESPACE_END