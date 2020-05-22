#include "WriterTextImp.h"
#include <Windows.h>
#include <sstream>
#include <time.h>
#include <io.h>
#include "EntityClass.h"
#include "EntityAttribute.h"

string getUserName()
{
     DWORD size=0;
     string sName;
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

WriterTextImp::WriterTextImp(void):m_pTextStream(0)
{
    m_nCount = 1;
}


WriterTextImp::~WriterTextImp(void)
{
    close();
}

bool WriterTextImp::open( const string& sFileName, const string& sProductCode )
{
	if (-1 != _access(sFileName.c_str(), 0))
	{
		//É¾³ýÎÄ¼þ
		remove(sFileName.c_str());
	}

    m_pTextStream = new fstream(sFileName,std::ios::out | std::ios::app);
    writeHead(sFileName, sProductCode);
    *m_pTextStream << "DATA;" << endl;
    return true;
}

void WriterTextImp::close()
{
    if (m_pTextStream)
    {
        *m_pTextStream << "ENDSEC;" << endl;
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
        string sName = pEntity->entityName();
        *m_pTextStream << "#" << m_nCount << "=" << sName << "(";
        for (int i = 0; i < pEntity->getPropCount(); i++)
        {
            auto pProp = pEntity->getProps(i);
            auto pSchema = pProp->getSchema();
            if (pSchema->getRepeatFlag())
            {
                auto nType = pSchema->getType()->getDataType();
                switch (nType)
                {
                case gfc2::schema::EDT_BOOLEAN: {
                    auto oList = pProp->asBooleanList();
                    if (oList.empty)
                    {
                        *m_pTextStream << "$" << ",";
                    }
                    else
                    {
                        *m_pTextStream << "(";
                        for each (auto value in oList)
                        {
                            *m_pTextStream << value ? ".T." : ".F.";
                        }
                        *m_pTextStream << ",";
                    }
                }
                    break;
                case gfc2::schema::EDT_INTEGER:
                    break;
                case gfc2::schema::EDT_DOUBLE:
                    break;
                case gfc2::schema::EDT_STRING:
                    break;
                case gfc2::schema::EDT_ENUM:
                    break;
                case gfc2::schema::EDT_ENTITY:
                    break;
                default:
                    break;
                }
            }
            else
            {

            }
        }
        *m_pTextStream << ");" << endl;
        return m_nCount++;
    }
    return -1;
}

void WriterTextImp::writeHead( const string& sFileName,const string& sProductCode )
{
	time_t current;
	time(&current);
	char charTime[64];
	strftime(charTime, sizeof(charTime), "%Y-%m-%d %H:%M:%S",localtime(&current) );

	stringstream stream;
	stream<< "HEADER;" << endl;
	stream<<"FILE_DESCRIPTION(('"<<Entity::Version()<<"'),'');"<<endl;
	stream<<"FILE_NAME('"<<sFileName<<"','"<<charTime<<"',('"<<getUserName()<<"'),('Glodon'),'objectbuf','"<<sProductCode<<"','');"<<endl;
	stream<<"FILE_SCHEMA(('"<<Entity::Version()<<"'));"<<endl;
	*m_pTextStream<<stream.str();
    *m_pTextStream << "ENDSEC;" << endl;
}

GFCENGINE_NAMESPACE_END