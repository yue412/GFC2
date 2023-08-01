#include "common.h"
#include <stdarg.h>
#include <algorithm>
#include <clocale>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <ctype.h>
#include <objbase.h>

std::wstring _FormatWstring(const wchar_t * lpcwszFormat, va_list _list)
{
    size_t nLength = _vscwprintf(lpcwszFormat, _list) + 1; //获取格式化字符串长度
    wchar_t* pszStr = new wchar_t[nLength];
    memset(pszStr, L'\0', nLength);
    _vsnwprintf_s(pszStr, nLength, nLength, lpcwszFormat, _list);
    std::wstring strResult(pszStr);
    delete[]pszStr;
    return strResult;
}

std::wstring FormatWstring(const wchar_t * lpcwszFormat, ...)
{
    std::wstring strResult;
    if (NULL != lpcwszFormat)
    {
        va_list marker = NULL;
        va_start(marker, lpcwszFormat); //初始化变量参数
        strResult = _FormatWstring(lpcwszFormat, marker);
        va_end(marker); //重置变量参数
    }
    return strResult;
}

std::wstring FormatWstring(const std::wstring sFormat, ...)
{
    va_list _va_list;
    va_start(_va_list, sFormat);      /* 初始化变长参数列表 */
    std::wstring sResult = _FormatWstring(sFormat.c_str(), _va_list);    /* 传递变长参数 */
    va_end(_va_list);         /* 结束使用变长参数列表 */
    return sResult;
}

std::wstring UpperString(const std::wstring & sStr)
{
    std::wstring sTmp = sStr;
    transform(sTmp.begin(), sTmp.end(), sTmp.begin(), towupper);
    return sTmp;
}

std::wstring LowerString(const std::wstring & sStr)
{
    std::wstring sTmp = sStr;
    transform(sTmp.begin(), sTmp.end(), sTmp.begin(), towlower);
    return sTmp;
}

// 把一个wstring转化为string
std::string UnicodeToACP(const std::wstring & str)
{
    return WStringToMBString(str, CP_ACP);
}

// 把一个string转化为wstring
std::wstring ACPToUnicode(const std::string& str)
{
    return MBStringToWString(str, CP_ACP);
}

std::wstring getExePath()
{
    char exeFullPath[MAX_PATH]; // MAX_PATH在WINDEF.h中定义了，等于260
    memset(exeFullPath, 0, MAX_PATH);

    GetModuleFileNameA(NULL, exeFullPath, MAX_PATH);
    char *p = /*wcsrchr*/strrchr(exeFullPath, '\\');
    *p = 0x00;
    return  ACPToUnicode(exeFullPath);
}

bool isRelativePath(const std::wstring & sPath)
{
    return sPath.find(L":") == -1;
}

std::wstring getFullPath(const std::wstring & sPath)
{
    if (isRelativePath(sPath))
    {
        return getExePath() + L"\\" + sPath;
    }
    else
    {
        return sPath;
    }
}

wchar_t * getWC(const char *c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}

std::string UnicodeToUtf8(const std::wstring & str)
{
    return WStringToMBString(str, CP_UTF8);
}

std::wstring Utf8ToUnicode(const std::string& str)
{
    return MBStringToWString(str, CP_UTF8);
}

std::fstream & operator<<(std::fstream & out, const std::wstring & s)
{
    out << UnicodeToUtf8(s);
    return out;
}

std::fstream & operator<<(std::fstream & out, const wchar_t * s)
{
    out << UnicodeToUtf8(s);
    return out;
}

std::string WStringToMBString(const std::wstring & str, UINT nCodePage)
{
    // unicode to UTF8
    //预转换，得到所需空间的大小，这次用的函数和上面名字相反
    int u8Len = ::WideCharToMultiByte(nCodePage, NULL, str.c_str(), wcslen(str.c_str()), NULL, 0, NULL, NULL);
    //同上，分配空间要给'\0'留个空间
    //UTF8虽然是Unicode的压缩形式，但也是多字节字符串，所以可以以char的形式保存
    char* szU8 = new char[u8Len + 1];
    //转换
    //unicode版对应的strlen是wcslen
    ::WideCharToMultiByte(nCodePage, NULL, str.c_str(), wcslen(str.c_str()), szU8, u8Len, NULL, NULL);
    //最后加上'\0'
    szU8[u8Len] = '\0';
    std::string sResult = szU8;
    delete[] szU8;
    return sResult;
}

std::wstring MBStringToWString(const std::string & str, UINT nCodePage)
{
    //Ascii to Unicode
    //预转换，得到所需空间的大小
    int wcsLen = ::MultiByteToWideChar(nCodePage, NULL, str.c_str(), strlen(str.c_str()), NULL, 0);
    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //转换
    ::MultiByteToWideChar(nCodePage, NULL, str.c_str(), strlen(str.c_str()), wszString, wcsLen);
    //最后加上'\0'
    wszString[wcsLen] = '\0';
    std::wstring sResult = wszString;
    delete[] wszString;
    return sResult;
}

bool fileExists(const std::wstring & sFile)
{
    std::wfstream _file;
    _file.open(sFile, std::ios::in);
    bool bResult = !_file.fail();
    _file.close();
    return bResult;
}

void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
}

// trim from end (in place)
void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
std::string trim_copy(std::string s) {
    trim(s);
    return s;
}

std::string transString(const std::string& sStr)
{
    std::string sResult;
    for (auto itr = sStr.begin(); itr != sStr.end(); ++itr) {
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

std::wstring transString(const std::wstring & sStr)
{
    return Utf8ToUnicode(transString(UnicodeToUtf8(sStr)));
}

std::wstring generateGuid()
{
    GUID guid;
    CoCreateGuid(&guid);
    const int nLen = 64;
    wchar_t cBuffer[nLen] = { 0 };
    swprintf_s(cBuffer, nLen,
        L"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
        guid.Data1, guid.Data2,
        guid.Data3, guid.Data4[0],
        guid.Data4[1], guid.Data4[2],
        guid.Data4[3], guid.Data4[4],
        guid.Data4[5], guid.Data4[6],
        guid.Data4[7]);
    return std::wstring(cBuffer);
}

std::wstring transformCompatibleName(const std::wstring & sEntityName)
{
    auto sName = sEntityName;
    auto sPrefix = sName.substr(0, 4);
    std::transform(sPrefix.begin(), sPrefix.end(), sPrefix.begin(), toupper);
    if (sPrefix.compare(L"GFC2") == 0)
        return sName.erase(3, 1);
    else
        return sName;
}

