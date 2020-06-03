#include "ReaderTextImp.h"
#include "FileMap.h"
#include "GfcSchema\Model.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\EnumType.h"
#include "Common.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Document.h"
#include "GfcEngine\GfcEngineUtils.h"
#include <fstream>
#include <stack>

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_OBJECT(ReaderTextImp, L"express", 0)

ReaderTextImp::ReaderTextImp(/*SchemaInfoMap* pSchemaInfoMap*/)
{
}


ReaderTextImp::~ReaderTextImp(void)
{
}

bool ReaderTextImp::preRead(const std::wstring& sFileName)
{
    char sHead[8];
    std::fstream in(sFileName, std::ios::in | std::ios::binary);
    in.get(sHead, 8);
    sHead[7] = 0;
    in.close();
    return strcmp(sHead, "HEADER;") == 0;
}

void ReaderTextImp::read( Document* pDoc,std::vector<std::wstring>& errors )
{
    //m_oSerMap.clear();

    //fstream in;
    ////增加读取缓冲区
    //char* buf = new char[1024 * 1024];
    //in.rdbuf()->pubsetbuf(buf, sizeof buf);
    //in.open(sFileName, ios::in);

    // 版本号不一致，也需要继续读取，只读取可以读取到的信息，xuxp，2018-5-17
    //todo update
/*
    string sSchema = getFileSchema(in);
    m_oUpdater.init(sSchema);
*/
    // 	if (!_stricmp(sSchema.c_str(),Entity::Version().c_str()))
    // 	{
    // 		return false;
    // 	}

    //if (!locate(in, "DATA;"))
    //{
    //    in.close();
    //    delete[] buf;
    //    return false;
    //}

    m_pFileMap->setPos(0);
    while (!m_pFileMap->eof())
    {
        std::string sLine = m_pFileMap->getLine();
//        m_oUpdater.update(sLine);
        EntityRef nId;
        std::string sName, sContent;
        std::wstring sError;
        if (parseLine(sLine, nId, sName, sContent))
        {
            if (Entity* pEntity = GfcEngineUtils::createEntity(schema(), toWstring(sName)))
            {
                if (!parse(sContent, pEntity, sError))
                {
                    delete pEntity;
                    // 添加log日志
                    errors.push_back(toWstring(sLine) + L" {" + sError + L"}");
                    continue;
                }

                if (!pDoc->getNeedAddEntityFunc() || pDoc->getNeedAddEntityFunc()(pDoc, nId, pEntity))
                {
                    pDoc->add(nId, pEntity);
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
}

//string ReaderTextImp::getFileSchema( fstream& in )
//{
//    string sResult;
//    if (locate(in, "HEADER;"))
//    {
//        while (!in.eof())
//        {
//			string sLine;
//			getline(in,sLine);
//
//			string schema = sLine.substr(0,11);
//			if (_stricmp(schema.c_str(),string("FILE_SCHEMA").c_str()))
//			{
//				int nStartPos = sLine.find_first_of('\'');
//				int nLastPos = sLine.find_last_of('\'');
//				return sLine.substr(nStartPos + 1, nLastPos - nStartPos - 1);
//			}
//			else if (_stricmp(sLine.c_str(),string("ENDSEC;").c_str()))
//			{
//				break;
//			}
//        }
//    }
//    return sResult;
//}
//
//string ReaderTextImp::projectId(const std::string& sFileName)
//{
//	string sResult = "";
//	fstream txtInput(sFileName,ios::in);
//	if (!txtInput)
//	{
//		return sResult;
//	}
//	string line;  
//	while(!txtInput.eof())  
//	{  
//		getline(txtInput,line);
//		string::size_type idx = line.find("GMP$");
//		if (idx != string::npos)
//		{
//			int firstIndex = line.find_first_of('$');
//			int lastIndex = line.find_last_of('$');
//			if (firstIndex != lastIndex)
//			{
//				sResult = line.substr(firstIndex+1,lastIndex - firstIndex-1);
//				return sResult;
//			}
//		}
//	}  
//	return sResult;
//}
//
//bool ReaderTextImp::locate( fstream& in, const std::string& sWord )
//{
//    while (!in.eof())
//    {
//		string line;
//		getline(in,line);
//		// 忽略大小写进行比较
//		if (_stricmp(line.c_str(),sWord.c_str()))
//		{
//			return true;
//		}
//    }
//    return false;
//}

bool ReaderTextImp::getIndex(EntityInfo & oInfo)
{
    while (!m_pFileMap->eof())
    {
        auto nPos = m_pFileMap->pos();
        std::string sLine = m_pFileMap->getLine();
        EntityRef nId;
        std::string sName, sContent;
        if (parseLine(sLine, nId, sName, sContent))
        {
            oInfo.id = nId;
            oInfo.pos = nPos;
            oInfo.type = schema()->findTypeObject(toWstring(sName));
            return true;
        }
    }
    return false;
}

Entity * ReaderTextImp::createEntity(EntityInfo & oInfo)
{
    Entity* pEntity = nullptr;
    if (m_pFileMap)
    {
        std::string sLine = m_pFileMap->getLine(oInfo.pos, nullptr);
        EntityRef nId;
        std::string sName, sContext;
        std::wstring sError;
        parseLine(sLine, nId, sName, sContext);

        pEntity = GfcEngineUtils::createEntity(schema(), toWstring(sName));
        if (pEntity)
        {
            //pEntity->setID(oInfo.id);
            if (!parse(sContext, pEntity, sError))
            {
                delete pEntity;
                pEntity = nullptr;
            }
        }
    }
    return pEntity;

}

bool ReaderTextImp::parse(const std::string& input, Entity* pEntity, std::wstring& error)
{
    bool bResult = true;
    int nStartPos = 0;
    int nFieldNum = 0;
    std::string sValue;
    while (getNextValue(input, nStartPos, sValue))
    {
        if (nFieldNum >= pEntity->getClass()->getTotalAttributeCount())
            break;
        auto pProp = pEntity->getProps(nFieldNum);
        auto pType = pProp->schema()->getType();
        auto pValue = pProp->value();

        if (!sValue.empty() && sValue.front() == '(' && sValue.back() == ')')
        {
            // array
            std::string sInput = sValue.substr(1, sValue.length() - 2);
            int nStart = 0;
            std::string sVal;
            while (getNextValue(sInput, nStart, sVal))
            {
                if (sVal != "$")
                {
                    auto pChildValue = Property::createValue(pType);
                    bResult = parseField(sVal, pType, pChildValue);
                    if (!bResult)
                    {
                        delete pValue;
                        break;
                    }
                    pValue->add(pChildValue);
                }
                nStart += sVal.length() + 1;
            }
        }
        else
        {
            if (sValue != "$")
            {
                bResult = parseField(sValue, pType, pValue);
                if (!bResult)
                    break;
            }
        }
        nStartPos += sValue.length() + 1;
        ++nFieldNum;
    }
    if (!bResult)
    {
        const std::string descript = "字段解析失败!";
        error = toWstring("\"" + sValue + "\"" + descript);
    }
    return bResult;
}

bool ReaderTextImp::parseField(const std::string & input, gfc::schema::CTypeObject* pType, PropValue * pValue)
{
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
    auto nType = pType->getDataType();
    switch (nType)
    {
    case gfc::schema::EDT_BOOLEAN:
        DO_(parseBooleanField(input, pValue));
        break;
    case gfc::schema::EDT_INTEGER:
        DO_(parseIntField(input, pValue));
        break;
    case gfc::schema::EDT_DOUBLE:
        DO_(parseFloatField(input, pValue));
        break;
    case gfc::schema::EDT_STRING:
        DO_(parseStringField(input, pValue));
        break;
    case gfc::schema::EDT_ENUM:
        {
            auto pEnumType = dynamic_cast<gfc::schema::CEnumType*>(pType->getBaseType());
            DO_(parseEnumField(input, pEnumType, pValue));
        }
        break;
    case gfc::schema::EDT_ENTITY:
        DO_(parseEntityField(input, pValue));
        break;
    default:
        assert(false);
        break;
    }
    return true;
}

bool ReaderTextImp::getNextValue(const std::string& input, int nStartPos, std::string& sValue)
{
    int nLength = input.length();
    if (nStartPos >= nLength)
    {
        return false;
    }
    bool bInStr = false;
    int nBracketStack = 0;

    for (int nIndex = nStartPos; nIndex < nLength; nIndex++)
    {
        const char& sChar = input[nIndex];
        if (sChar == '(')
        {
            nBracketStack++;
        }
        else if (sChar == ')')
        {
            nBracketStack--;
        }
        else if (sChar == '\'')
        {
            bInStr = !bInStr;
        }
        else if ((sChar == ',') && !bInStr && nBracketStack == 0)
        {
            sValue = input.substr(nStartPos, nIndex - nStartPos);
            return true;
        }
    }
    sValue = input.substr(nStartPos, nLength - nStartPos + 1);
    return true;
}

bool ReaderTextImp::parseLine(const std::string & sLine, EntityRef& nId, std::string& sName, std::string& sContent)
{
    if (sLine.size() < 7) // #0=X(); 至少七个字符
    {
        return false;
    }

    if (sLine.front() != '#' || sLine.back() != ';')
    {
        return false;
    }
    auto l = sLine.find_first_of("(");
    if (l == std::string::npos)
    {
        return false;
    }
    auto e = sLine.find_first_of("=");
    if (e == std::string::npos)
    {
        return false;
    }
    auto k = sLine.find_last_of(")");
    if (k == std::string::npos)
    {
        return false;
    }
    auto sID = sLine.substr(1, e - 1);
    nId = -1;
    try
    {
        nId = stol(sID);
    }
    catch (...)
    {
        return false;
    }
    sName = sLine.substr(e + 1, l - e - 1);
    sContent = sLine.substr(l + 1, k -l -1);
    return true;
}

bool ReaderTextImp::parseBoolean(const std::string& input, bool& value)
{
    if (input == ".T.")
    {
        value = true;
    }
    else if (input == ".F.")
    {
        value = false;
    }
    else
    {
        return false;
    }
    return true;
}

bool ReaderTextImp::parseInt(const std::string& input, int& value)
{

    try
    {
        value = stoi(input);
    }
    catch (...)
    {
        return false;
    }
    return true;
}

bool ReaderTextImp::parseFloat(const std::string& input, double& value)
{
    try
    {
        value = stod(input);
    }
    catch (...)
    {
        return false;
    }
    return true;
}

bool ReaderTextImp::parseString(const std::string& input, std::string& value)
{
    if (input.length() > 1 && input[0] == '\'' && input[input.length() - 1] == '\'')
    {
        value = input.substr(1, input.length() - 2);
    }
    else
    {
        return false;
    }
    return true;
}

bool ReaderTextImp::parseEntity(const std::string& input, EntityRef& value)
{
    if (!input.empty() && input[0] == '#')
    {
        std::string sValue = input.substr(1);
        try
        {
            value = std::stoi(sValue);
            return true;
        }
        catch (...)
        {

        }
    }
    return false;
}


bool ReaderTextImp::parseBooleanField(const std::string& input, PropValue* pValue)
{
    bool val;
    bool bResult = parseBoolean(input, val);
    if (bResult)
        pValue->setAsBoolean(val);
    return bResult;
}

bool ReaderTextImp::parseIntField(const std::string& input, PropValue* pValue)
{
    int val;
    bool bResult = parseInt(input, val);
    if (bResult)
        pValue->setAsInteger(val);
    return bResult;
}

bool ReaderTextImp::parseFloatField(const std::string& input, PropValue* pValue)
{
    double val;
    bool bResult = parseFloat(input, val);
    if (bResult)
        pValue->setAsDouble(val);
    return bResult;
}

bool ReaderTextImp::parseStringField(const std::string& input, PropValue* pValue)
{
    std::string val;
    bool bResult = parseString(input, val);
    if (bResult)
        pValue->setAsString(val);
    return bResult;
}

bool ReaderTextImp::parseEnumField(const std::string & input, gfc::schema::CEnumType * pEnumType, PropValue * pValue)
{
    bool bResult = false;
    if (input.length() > 1 && input[0] == '.' && input[input.length() - 1] == '.' && pEnumType)
    {
        auto str = input.substr(1, input.length() - 2);
        auto nIndex = pEnumType->indexOf(toWstring(str));
        if (nIndex >= 0)
        {
            pValue->setAsInteger(nIndex);
            bResult = true;
        }
    }
    return bResult;
}

bool ReaderTextImp::parseEntityField(const std::string& input, PropValue* pValue)
{
    EntityRef val;
    bool bResult = parseEntity(input, val);
    if (bResult)
        pValue->setAsEntityRef(val);
    return bResult;
}


GFCENGINE_NAMESPACE_END