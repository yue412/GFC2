#include "ReaderTextImp.h"
#include <regex>
#include <sstream>
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/Document.h"
#include "EntityTextSerializer.h"
#include "tinyxml.h"
#include "Common.h"

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) glodon::objectbuf::ReaderImp* CreateReaderImp(TiXmlElement* pNode)
{
    auto pImp = new glodon::objectbuf::ReaderTextImp;
    auto pSchemaPathNode = pNode->FirstChildElement("SchemaPath");
    std::string sPath;
    if (pSchemaPathNode)
    {
        const char* str = pSchemaPathNode->GetText();
        if (str)
            sPath = str;
    }
    pImp->setSchemaPath(UnicodeToUtf8(getFullPath(Utf8ToUnicode(sPath))));
    auto pRemoteNode = pNode->FirstChildElement("Remote");
    if (pRemoteNode)
    {
        const char* sPath = pRemoteNode->GetText();
        if (sPath)
        {
            pImp->setRemote(sPath);
        }
    }
    return pImp;
}

__declspec(dllexport) void FreeReaderImp(glodon::objectbuf::ReaderImp* pImp)
{
    delete pImp;
}

#ifdef __cplusplus
}
#endif

namespace glodon {
namespace objectbuf {

ReaderTextImp::ReaderTextImp(/*SchemaInfoMap* pSchemaInfoMap*/)
{
}


ReaderTextImp::~ReaderTextImp(void)
{
}

bool ReaderTextImp::read( const string& sFileName, Document* pDoc,std::vector<std::string>& errors )
{
    m_oSerMap.clear();

	fstream in;
    //增加读取缓冲区
    char* buf = new char[1024 * 1024];
    in.rdbuf()->pubsetbuf(buf, sizeof buf);
    in.open(sFileName, ios::in);

	// 版本号不一致，也需要继续读取，只读取可以读取到的信息，xuxp，2018-5-17
    string sSchema = getFileSchema(in);
    m_oUpdater.init(sSchema);
// 	if (!_stricmp(sSchema.c_str(),Entity::Version().c_str()))
// 	{
// 		return false;
// 	}

    if (!locate(in, "DATA;"))
    {
        in.close();
        delete[] buf;
        return false;
    }

    while (!in.eof())
    {
        string sLine;
        getline(in, sLine);
        m_oUpdater.update(sLine);
        /*
        //这里不要用正则表达式，因为sLine可能非常长，而事实上这里只关心开头和结尾
        string sPattern("#(\\d+)=(\\w+)\\((.+)\\);");
        regex  rx(sPattern);
		smatch rxm;
		if(regex_match(sLine,rxm,rx))
        {
			int nId = 0;
			stringstream stream(rxm[1]);  
			stream>>nId;  

			string sName = rxm[2];
			string sContent = rxm[3];
            {
                EntityTextSerializer* pSerializer = (EntityTextSerializer*)EntitySerializer::GetFactory()->Create(sName+"T");
                Entity* pEntity = (Entity*)Entity::GetFactory()->Create(sName);
                if (pEntity && pSerializer)
                {
					std::string error;
					if (!pSerializer->parse(sContent,pEntity,error))
					{
						// 添加log日志
						errors.push_back(sLine + " {"+error+"}");
					}
					pDoc->add(nId, pEntity);
                    delete pSerializer;
                }
            }
        }
        */
        if (sLine.size() < 7) // #0=X(); 至少七个字符
        {
            continue;
        }
        if (sLine.front() != '#' || sLine.back() != ';')
        {
            continue;
        }
        sLine.pop_back();
        if (sLine.back() != ')')
        {
            continue;
        }
        sLine.pop_back();
        auto l = sLine.find_first_of("(");
        if (l == string::npos)
        {
            continue;
        }
        auto e = sLine.find_first_of("=");
        if (e == string::npos)
        {
            continue;
        }
        string sID = sLine.substr(1, e - 1);
        int nID = -1;
        try
        {
            nID = stoi(sID);
        }
        catch (...)
        {
            continue;
        }
        string sName = sLine.substr(e + 1, l - e - 1);
        string sContent = sLine.substr(l + 1);
        EntityTextSerializer* pSerializer = nullptr;
        auto pIter = m_oSerMap.find(sName + "T");
        if (pIter == m_oSerMap.end())
        {
            pSerializer = (EntityTextSerializer*)EntitySerializer::GetFactory()->Create(sName + "T");
            m_oSerMap[sName + "T"] = pSerializer;
        }
        else
        {
            pSerializer = pIter->second;
        }
        if (pSerializer != nullptr)
        {
            if (Entity* pEntity = (Entity*)Entity::GetFactory()->Create(sName))
            {
				pEntity->setDocument(pDoc);
                string error;
                if (!pSerializer->parse(sContent, pEntity, error))
                {
                    // 添加log日志
                    errors.push_back(sLine + " {" + error + "}");
                }
                if (!pDoc->getNeedAddEntityFunc() || pDoc->getNeedAddEntityFunc()(pDoc, nID, pEntity))
                {
                    pDoc->add(nID, pEntity);
                }
                else
                {
                    delete pEntity;
                }
            }
        }
    }
    if (pDoc->getAfterReadDocFunc())
    {
        pDoc->getAfterReadDocFunc()(pDoc);
    }
    for (auto pIter = m_oSerMap.begin(); pIter != m_oSerMap.end(); pIter++)
    {
        delete pIter->second;
    }
    in.close();
    delete[] buf;
    return true;
}

bool ReaderTextImp::preRead(const string& sFileName)
{
    char sHead[8];
    std::fstream in(sFileName, std::ios::in | std::ios::binary);
    in.get(sHead, 8);
    sHead[7] = 0;
    in.close();
    return strcmp(sHead, "HEADER;") == 0;
}

string ReaderTextImp::getFileSchema( fstream& in )
{
    string sResult;
    if (locate(in, "HEADER;"))
    {
        while (!in.eof())
        {
			string sLine;
			getline(in,sLine);

			string schema = sLine.substr(0,11);
			if (_stricmp(schema.c_str(),"FILE_SCHEMA") == 0)
			{
				int nStartPos = sLine.find_first_of('\'');
				int nLastPos = sLine.find_last_of('\'');
				return sLine.substr(nStartPos + 1, nLastPos - nStartPos - 1);
			}
			else if (_stricmp(sLine.c_str(),"ENDSEC;") == 0)
			{
				break;
			}
        }
    }
    return sResult;
}

string ReaderTextImp::projectId(const string& sFileName)
{
	string sResult = "";
	fstream txtInput(sFileName,ios::in);
	if (!txtInput)
	{
		return sResult;
	}
	string line;  
	while(!txtInput.eof())  
	{  
		getline(txtInput,line);
		string::size_type idx = line.find("GMP$");
		if (idx != string::npos)
		{
			int firstIndex = line.find_first_of('$');
			int lastIndex = line.find_last_of('$');
			if (firstIndex != lastIndex)
			{
				sResult = line.substr(firstIndex+1,lastIndex - firstIndex-1);
				return sResult;
			}
		}
	}  
	return sResult;
}

bool ReaderTextImp::locate( fstream& in, const string& sWord )
{
    while (!in.eof())
    {
		string line;
		getline(in,line);
		// 忽略大小写进行比较
		if (_stricmp(line.c_str(),sWord.c_str()))
		{
			return true;
		}
    }
    return false;
}


}
}
