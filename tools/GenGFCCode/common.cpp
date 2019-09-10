#include "common.h"
#include <stdarg.h>
#include <algorithm>
#include <clocale>
#include <vector>
#include <Windows.h>

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
std::string toString(const std::wstring & src)
{
    std::setlocale(LC_CTYPE, "");

    size_t const mbs_len = wcstombs(NULL, src.c_str(), 0);
    std::vector<char> tmp(mbs_len + 1);
    wcstombs(&tmp[0], src.c_str(), tmp.size());
    std::string dest;
    dest.assign(tmp.begin(), tmp.end() - 1);

    return dest;
}

// 把一个string转化为wstring
std::wstring toWstring(const std::string& src)
{
    //   std::setlocale(LC_CTYPE, "");
    std::setlocale(LC_CTYPE, "zh_CN");

    size_t const wcs_len = mbstowcs(NULL, src.c_str(), 0);
    std::vector<wchar_t> tmp(wcs_len + 1);
    mbstowcs(&tmp[0], src.c_str(), src.size());

    std::wstring dest;
    dest.assign(tmp.begin(), tmp.end() - 1);

    return dest;
}


std::wstring getExePath()
{
    WCHAR exeFullPath[MAX_PATH]; // MAX_PATH在WINDEF.h中定义了，等于260
    memset(exeFullPath, 0, MAX_PATH);

    GetModuleFileName(NULL, exeFullPath, MAX_PATH);
    WCHAR *p = wcsrchr(exeFullPath, L'\\');
    *p = 0x00;
    return  std::wstring(exeFullPath);
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
