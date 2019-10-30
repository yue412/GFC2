#include "WriterTextImp.h"
#include "glodon/objectbuf/EntitySchema.h"
#include <Windows.h>
#include <sstream>
#include <time.h>
#include "EntityTextSerializer.h"
#include <io.h>
#include "tinyxml.h"

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

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) glodon::objectbuf::WriterImp* CreateWriterImp(TiXmlElement* pNode)
{
    return new glodon::objectbuf::WriterTextImp;
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

glodon::objectbuf::EntityRef WriterTextImp::writeEntity( Entity* pEntity )
{
    if (m_pTextStream)
    {
        string sName = pEntity->entityName();
        EntityTextSerializer* pSerializer = (EntityTextSerializer*)EntitySerializer::GetFactory()->Create(sName + "T");
        if (pSerializer)
        {
			std::stringstream stream;
			stream<<"#"<<m_nCount<<"="<<sName<<"("<<pSerializer->serialize(pEntity)<<");";
			std::string sLine = stream.str();
            delete pSerializer;
            *m_pTextStream << sLine << endl;
            return m_nCount++;
        }
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

}
}