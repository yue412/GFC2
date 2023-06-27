#include "common.h"
#include <stdarg.h>
#include <algorithm>
#include <clocale>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <wchar.h>
#if (defined _WIN32 || defined _WIN64)
	#include <Windows.h>
    #include <objbase.h>
#else
    #include <uuid/uuid.h>
    #include <unistd.h>
    #include <wchar.h>

    #define CP_ACP                    0
    #define CP_UTF8                   65001       // UTF-8 translation
    #define MAX_PATH          260
#endif

std::wstring FormatWstring(const wchar_t * lpcwszFormat, ...)
{
    std::wstring strResult;
    if (NULL != lpcwszFormat)
    {
        va_list marker;
        //获取格式化字符串长度
        va_start(marker, lpcwszFormat); //初始化变量参数
        size_t nLength = vwprintf(lpcwszFormat, marker) + 1; 
        va_end(marker); //重置变量参数
        // 格式化字符串
        va_start(marker, lpcwszFormat); //初始化变量参数
        wchar_t* pszStr = new wchar_t[nLength];
        vswprintf(pszStr, nLength, lpcwszFormat, marker);
        strResult = pszStr;
        delete[]pszStr;
        va_end(marker); //重置变量参数
    }
    return strResult;
}


std::wstring FormatWstring(const std::wstring sFormat, ...)
{
    va_list _va_list;
    va_start(_va_list, sFormat);      /* 初始化变长参数列表 */
    size_t nLength = vwprintf(sFormat.c_str(), _va_list) + 1;
    va_end(_va_list); //重置变量参数

    va_start(_va_list, sFormat); //初始化变量参数
    wchar_t* pszStr = new wchar_t[nLength];
    vswprintf(pszStr, nLength, sFormat.c_str(), _va_list);
    std::wstring strResult = pszStr;
    delete[]pszStr;
    va_end(_va_list);         /* 结束使用变长参数列表 */
    return strResult;
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
#if (defined _WIN32 || defined _WIN64)
    GetModuleFileNameA(NULL, exeFullPath, MAX_PATH);
    char *p = /*wcsrchr*/strrchr(exeFullPath, '\\');
#else
    //获取当前程序绝对路径
    int cnt = readlink("/proc/self/exe", exeFullPath, MAX_PATH);
    
    if (cnt < 0 || cnt >= MAX_PATH)
    {
        printf("***Error***\n");
        exit(-1);
    }
    char *p = /*wcsrchr*/strrchr(exeFullPath, '/');
#endif

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
        return getExePath() + L"/" + sPath;
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

std::string WStringToMBString(const std::wstring & str, unsigned int nCodePage)
{
    char* locale;
    if(nCodePage == CP_UTF8)
        locale = setlocale(LC_ALL, "zh_CN.utf8");
    else
        locale = setlocale(LC_ALL, NULL);
    int u8Len = wcstombs(NULL, str.c_str(), 0);
    char* szU8 = new char[u8Len + 1];
    wcstombs(szU8, str.c_str(), u8Len);
    szU8[u8Len] = '\0';
    std::string sResult = szU8;
    delete[] szU8;
    setlocale(LC_ALL, locale);
    return sResult;
}

std::wstring MBStringToWString(const std::string & str, unsigned int nCodePage)
{
    char* locale;
    if(nCodePage == CP_UTF8)
        locale = setlocale(LC_ALL, "zh_CN.utf8");
    else
        locale = setlocale(LC_ALL, NULL);
    int wcsLen = mbstowcs(NULL, str.c_str(), 0);    
    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //转换
    mbstowcs(wszString, str.c_str(), wcsLen);
    //最后加上'\0'
    wszString[wcsLen] = '\0';
    std::wstring sResult = wszString;
    delete[] wszString;
    setlocale(LC_ALL, locale);
    return sResult;
}

bool fileExists(const std::wstring & sFile)
{
#if (defined _WIN32 || defined _WIN64)
    int ret = _waccess(sFile.c_str(), 0);
#else
    int ret = access(WStringToMBString(sFile, CP_UTF8).c_str(), F_OK);
#endif
    return ret == 0;
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
#if (defined _WIN32 || defined _WIN64)
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
#else
    uuid_t uuid;
    uuid_generate(uuid);
    char s[37];
    uuid_unparse(uuid, s);
    return Utf8ToUnicode(s);
#endif
}