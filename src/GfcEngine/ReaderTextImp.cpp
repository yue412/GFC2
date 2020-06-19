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
#include <algorithm>

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_OBJECT(CReaderTextImp, L"express", 0)

CReaderTextImp::CReaderTextImp(/*SchemaInfoMap* pSchemaInfoMap*/)
{
}


CReaderTextImp::~CReaderTextImp(void)
{
}

bool CReaderTextImp::preRead(const std::wstring& sFileName)
{
    char sHead[8];
    std::fstream in(sFileName, std::ios::in | std::ios::binary);
    in.get(sHead, 8);
    sHead[7] = 0;
    in.close();
    return strcmp(sHead, "HEADER;") == 0;
}

std::wstring CReaderTextImp::readFileVersion()
{
    std::string sResult;
    if (m_pFileMap)
    {
        m_pFileMap->setPos(0);
        while (!m_pFileMap->eof())
        {
            auto sLine = m_pFileMap->getLine();

            auto schema = sLine.substr(0, 11);
            if (_stricmp(schema.c_str(), "FILE_SCHEMA") == 0)
            {
                int nStartPos = sLine.find_first_of('\'');
                int nLastPos = sLine.find_last_of('\'');
                sResult = sLine.substr(nStartPos + 1, nLastPos - nStartPos - 1);
                break;
            }
            else if (_stricmp(sLine.c_str(), "ENDSEC;") == 0)
            {
                break;
            }
        }
    }
    std::replace(sResult.begin(), sResult.end(), L'.', L'X');
    return Utf8ToUnicode(sResult);
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

bool CReaderTextImp::getIndex(EntityInfo & oInfo)
{
    while (!m_pFileMap->eof())
    {
        auto nPos = m_pFileMap->pos();
        std::string sLine = m_pFileMap->getLine();
        EntityRef nId;
        std::string sName, sContent;
        if (CReaderTextUtils::parseLine(sLine, nId, sName, sContent))
        {
            oInfo.id = nId;
            oInfo.pos = nPos;
            oInfo.type = schema()->findTypeObject(Utf8ToUnicode(sName));
            return true;
        }
    }
    return false;
}

CEntity * CReaderTextImp::createEntity(__int64 nPos, EntityRef& nId)
{
    CEntity* pEntity = nullptr;
    if (m_pFileMap)
    {
        m_pFileMap->setPos(nPos);
        std::string sLine = m_pFileMap->getLine();
        std::string sName, sContent;
        std::wstring sError;
        if (CReaderTextUtils::parseLine(sLine, nId, sName, sContent))
        {
            pEntity = m_bUseStaticClass ? dynamic_cast<CEntity*>(CEntity::GetFactory()->Create(ACPToUnicode(sName)))
                : CEngineUtils::createEntity(schema(), Utf8ToUnicode(sName));
            if (pEntity)
            {
                if (!CReaderTextUtils::parse(sContent, pEntity, sError))
                {
                    delete pEntity;
                    pEntity = nullptr;
                    // 添加log日志
                    log(Utf8ToUnicode(sLine) + L" {" + sError + L"}");
                }
            }

        }
    }
    return pEntity;
}

bool CReaderTextUtils::parse(const std::string& input, CEntity* pEntity, std::wstring& error)
{
    bool bResult = true;
    int nStartPos = 0;
    int nFieldNum = 0;
    std::string sValue;
    while (getNextValue(input, nStartPos, sValue))
    {
        auto nLen = sValue.length();
        trim(sValue);
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
                nStart += sVal.length() + 1;
                trim(sVal);
                if (sVal != "$")
                {
                    auto pChildValue = CProperty::createValue(pType);
                    bResult = parseField(sVal, pType, pChildValue);
                    if (!bResult)
                    {
                        delete pValue;
                        break;
                    }
                    pValue->add(pChildValue);
                }
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
        nStartPos += nLen + 1;
        ++nFieldNum;
    }
    if (!bResult)
    {
        const std::string descript = "字段解析失败!";
        error = Utf8ToUnicode("\"" + sValue + "\"" + descript);
    }
    return bResult;
}

bool CReaderTextUtils::parseField(const std::string & input, gfc::schema::CTypeObject* pType, CPropValue * pValue)
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

bool CReaderTextUtils::getNextValue(const std::string& input, int nStartPos, std::string& sValue)
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
        if (bInStr)
        {
            // 处理转义
            if ('\\' == sChar)
            {
                ++nIndex;
            }
            else if (sChar == '\'')
            {
                bInStr = false;
            }
        }
        else
        {
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
                bInStr = true;
            }
            else if ((sChar == ',') && !bInStr && nBracketStack == 0)
            {
                sValue = input.substr(nStartPos, nIndex - nStartPos);
                return true;
            }
        }
    }
    sValue = input.substr(nStartPos, nLength - nStartPos + 1);
    return true;
}

bool CReaderTextUtils::parseLine(const std::string & sLine, EntityRef& nId, std::string& sName, std::string& sContent)
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

bool CReaderTextUtils::parseBoolean(const std::string& input, bool& value)
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

bool CReaderTextUtils::parseInt(const std::string& input, int& value)
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

bool CReaderTextUtils::parseFloat(const std::string& input, double& value)
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

bool CReaderTextUtils::parseString(const std::string& input, std::string& value)
{
    value = "";
    if (input.length() > 1 && input[0] == '\'' && input[input.length() - 1] == '\'')
    {
        //value = input.substr(1, input.length() - 2);
        for (std::size_t i = 1; i < (input.length() - 1); ++i)
        {
            if ('\\' == input[i])
            {
                ++i;
                if (input.length() - 1 == i)
                    return false;
                switch (input[i])
                {
                case '\'':
                    value.push_back('\'');
                    break;
                case 'n':
                    value.push_back('\n');
                    break;
                case 'r':
                    value.push_back('\r');
                    break;
                case '\\':
                    value.push_back('\\');
                    break;
                default:
                    return false;
                    break;
                }
            }
            else
            {
                value.push_back(input[i]);
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool CReaderTextUtils::parseEntity(const std::string& input, EntityRef& value)
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


bool CReaderTextUtils::parseBooleanField(const std::string& input, CPropValue* pValue)
{
    bool val;
    bool bResult = parseBoolean(input, val);
    if (bResult)
        pValue->setAsBoolean(val);
    return bResult;
}

bool CReaderTextUtils::parseIntField(const std::string& input, CPropValue* pValue)
{
    int val;
    bool bResult = parseInt(input, val);
    if (bResult)
        pValue->setAsInteger(val);
    return bResult;
}

bool CReaderTextUtils::parseFloatField(const std::string& input, CPropValue* pValue)
{
    double val;
    bool bResult = parseFloat(input, val);
    if (bResult)
        pValue->setAsDouble(val);
    return bResult;
}

bool CReaderTextUtils::parseStringField(const std::string& input, CPropValue* pValue)
{
    std::string val;
    bool bResult = parseString(input, val);
    if (bResult)
        pValue->setAsString(Utf8ToUnicode(val));
    return bResult;
}

bool CReaderTextUtils::parseEnumField(const std::string & input, gfc::schema::CEnumType * pEnumType, CPropValue * pValue)
{
    bool bResult = false;
    if (input.length() > 1 && input[0] == '.' && input[input.length() - 1] == '.' && pEnumType)
    {
        auto str = input.substr(1, input.length() - 2);
        auto nIndex = pEnumType->indexOf(Utf8ToUnicode(str));
        if (nIndex >= 0)
        {
            pValue->setAsInteger(nIndex);
            bResult = true;
        }
    }
    return bResult;
}

bool CReaderTextUtils::parseEntityField(const std::string& input, CPropValue* pValue)
{
    EntityRef val;
    bool bResult = parseEntity(input, val);
    if (bResult)
        pValue->setAsEntityRef(val);
    return bResult;
}


GFCENGINE_NAMESPACE_END