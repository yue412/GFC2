#include "glodon/objectbuf/EntityTextSerializer.h"
#include "glodon/objectbuf/Entity.h"
#include <stack>
#include <regex>
namespace glodon {
namespace objectbuf {

EntityTextSerializer::EntityTextSerializer(void)
{
}


EntityTextSerializer::~EntityTextSerializer(void)
{
}

string EntityTextSerializer::serialize(Entity* pEntity) const
{
    return "";
}

bool EntityTextSerializer::parse( const string& input, Entity* pEntity, std::string& error )
{
    bool bResult = true;
    int nStartPos = 0;
    int nFieldNum = 0;
    string sValue;
    while (getNextValue(input, nStartPos, sValue))
    {
        if (!sValue.empty() && sValue.front() == '(' && sValue.back() == ')')
        {
            // array
            string sInput = sValue.substr(1, sValue.length() - 2);
            int nStart = 0;
            string sVal;
            while (getNextValue(sInput, nStart, sVal))
            {
                if (sVal != "$")
                {
                    bResult = parseField(sVal, nFieldNum, pEntity);
                    if (!bResult)
                        break;
                }
                nStart += sVal.length() + 1;
            }
        }
        else 
        {
            if (sValue != "$")
            {
                bResult = parseField(sValue, nFieldNum, pEntity);
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
	    error = "\"" + sValue + "\"" + descript;
	}
    return bResult;
}

glodon::objectbuf::EnParseFieldState EntityTextSerializer::parseField( const string& input, int nFieldNum, Entity* pEntity )
{
    return PFS_IGNORE;
}

bool EntityTextSerializer::getNextValue( const string& input, int nStartPos, string& sValue )
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

    //不使用栈记录状态，有点慢
    //int nState = 0;
    //stack<int> oStack;
    //oStack.push(nState);
    //while (nIndex <= nLength)
    //{
    //    switch(nState)
    //    {
    //    case 0: 
    //        if (input[nIndex] == ',')
    //        {
    //            sValue = input.substr(nStartPos, nIndex - nStartPos);
    //            return true;
    //        }
    //        else if (input[nIndex] == '(')
    //        {
    //            nState = 1; // array
    //        }
    //        else if (input[nIndex] == '\'')
    //        {
    //            nState = 2; // string
    //        }
    //        oStack.push(nState);
    //        break;
    //    case 1:
    //        if (input[nIndex] == '\'')
    //        {
    //            nState = 2; // string
    //        }
    //        else if (input[nIndex] == ')')
    //        {
    //            oStack.pop();
    //            nState = oStack.top();
    //        }
    //        break;
    //    case 2:
    //        if (input[nIndex] == '\'')
    //        {
    //            // string
    //            oStack.pop();
    //            nState = oStack.top();
    //        }
    //        break;
    //    default:
    //        assert(false);
    //    }
    //    ++nIndex;
    //}
    //sValue = input.substr(nStartPos,nLength - nStartPos + 1);
    //return true;
}

bool EntityTextSerializer::readBooleanField( const string& input, bool& value )
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

bool EntityTextSerializer::readIntField( const string& input, int& value )
{
	// 匹配整数与小数,包含科学计数法的表示,不再采用正则表达式，正则表达式存在一定的效率问题
// 	string sPattern("^(0|[+-]?((0|([1-9]\\d*))\\.\\d+)|[+-]?(\\d+))?$");
// 	string sPattern("^(0|[+-]?((0|([1-9]\\d*))\\.\\d+)|[+-]?((0|([1-9]\\d*))\\.\\d+)[Ee][+-]?(\\d+)|[+-]?(\\d+)|[+-]?(\\d+)[Ee][+-]?(\\d+))?$");
// 	regex  rx(sPattern);
// 	smatch rxm;
// 	if(regex_match(input,rxm,rx))
// 	{
// 		value = std::stoi(input);
// 		return true;
// 	}

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

bool EntityTextSerializer::readFloatField( const string& input, double& value )
{
	// 匹配整数与小数,包含科学计数法的表示,不再采用正则表达式，正则表达式存在一定的效率问题
// 	string sPattern("^(0|[+-]?((0|([1-9]\\d*))\\.\\d+)|[+-]?(\\d+))?$");
// 	string sPattern("^(0|[+-]?((0|([1-9]\\d*))\\.\\d+)|[+-]?((0|([1-9]\\d*))\\.\\d+)[Ee][+-]?(\\d+)|[+-]?(\\d+)|[+-]?(\\d+)[Ee][+-]?(\\d+))?$");
// 	regex  rx(sPattern);
// 	smatch rxm;
// 	if(regex_match(input,rxm,rx))
// 	{
// 		value = std::stod(input);
// 		return true;
// 	}
// 	return false;

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

bool EntityTextSerializer::readStringField( const string& input, string& value )
{
    if (input.length() > 1 && input[0] == '\'' && input[input.length() - 1] == '\'')
    {
		value = input.substr(1,input.length() - 2);
    }
    else
    {
        return false;
    }
    return true;
}

bool EntityTextSerializer::readEntityField( const string& input, EntityRef& value )
{
    if (!input.empty() && input[0] == '#')
    {
        //这里不用正则表达式，太慢了
		//string sPattern("\\d+");
		//regex  rx(sPattern);
		//smatch rxm;
		//std::string sValue = input.substr(1,input.length() - 1);
		//if(regex_match(sValue,rxm,rx))
		//{
		//	bOk = true;
		//	value = std::stoi(sValue);
		//}
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

}
}