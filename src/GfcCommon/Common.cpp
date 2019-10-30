#include "common.h"
#include <stdarg.h>
#include <algorithm>
#include <clocale>
#include <vector>
#include <Windows.h>

std::wstring _FormatWstring(const wchar_t * lpcwszFormat, va_list _list)
{
    size_t nLength = _vscwprintf(lpcwszFormat, _list) + 1; //��ȡ��ʽ���ַ�������
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
        va_start(marker, lpcwszFormat); //��ʼ����������
        strResult = _FormatWstring(lpcwszFormat, marker);
        va_end(marker); //���ñ�������
    }
    return strResult;
}

std::wstring FormatWstring(const std::wstring sFormat, ...)
{
    va_list _va_list;
    va_start(_va_list, sFormat);      /* ��ʼ���䳤�����б� */
    std::wstring sResult = _FormatWstring(sFormat.c_str(), _va_list);    /* ���ݱ䳤���� */
    va_end(_va_list);         /* ����ʹ�ñ䳤�����б� */
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

// ��һ��wstringת��Ϊstring
std::string toString(const std::wstring & src)
{
    char* loc = std::setlocale(LC_CTYPE, "");

    size_t const mbs_len = wcstombs(NULL, src.c_str(), 0);
    std::vector<char> tmp(mbs_len + 1);
    wcstombs(&tmp[0], src.c_str(), tmp.size());
    std::string dest;
    dest.assign(tmp.begin(), tmp.end() - 1);
    std::setlocale(LC_CTYPE, loc);
    return dest;
}

// ��һ��stringת��Ϊwstring
std::wstring toWstring(const std::string& src)
{
    //   std::setlocale(LC_CTYPE, "");
    char* loc = std::setlocale(LC_CTYPE, "zh_CN");

    size_t const wcs_len = mbstowcs(NULL, src.c_str(), 0);
    std::vector<wchar_t> tmp(wcs_len + 1);
    mbstowcs(&tmp[0], src.c_str(), src.size());

    std::wstring dest;
    dest.assign(tmp.begin(), tmp.end() - 1);
    std::setlocale(LC_CTYPE, loc);

    return dest;
}


std::wstring getExePath()
{
    char exeFullPath[MAX_PATH]; // MAX_PATH��WINDEF.h�ж����ˣ�����260
    memset(exeFullPath, 0, MAX_PATH);

    GetModuleFileName(NULL, exeFullPath, MAX_PATH);
    char *p = /*wcsrchr*/strrchr(exeFullPath, '\\');
    *p = 0x00;
    return  toWstring(exeFullPath);
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
    // unicode to UTF8
    //Ԥת�����õ�����ռ�Ĵ�С������õĺ��������������෴
    int u8Len = ::WideCharToMultiByte(CP_UTF8, NULL, str.c_str(), wcslen(str.c_str()), NULL, 0, NULL, NULL);
    //ͬ�ϣ�����ռ�Ҫ��'\0'�����ռ�
    //UTF8��Ȼ��Unicode��ѹ����ʽ����Ҳ�Ƕ��ֽ��ַ��������Կ�����char����ʽ����
    char* szU8 = new char[u8Len + 1];
    //ת��
    //unicode���Ӧ��strlen��wcslen
    ::WideCharToMultiByte(CP_UTF8, NULL, str.c_str(), wcslen(str.c_str()), szU8, u8Len, NULL, NULL);
    //������'\0'
    szU8[u8Len] = '\0';
    std::string sResult = szU8;
    delete[] szU8;
    return sResult;
}

std::wstring Utf8ToUnicode(const std::string& str)
{
    //UTF8 to Unicode
    //Ԥת�����õ�����ռ�Ĵ�С
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, str.c_str(), strlen(str.c_str()), NULL, 0);
    //����ռ�Ҫ��'\0'�����ռ䣬MultiByteToWideChar�����'\0'�ռ�
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //ת��
    ::MultiByteToWideChar(CP_UTF8, NULL, str.c_str(), strlen(str.c_str()), wszString, wcsLen);
    //������'\0'
    wszString[wcsLen] = '\0';
    std::wstring sResult = wszString;
    delete[] wszString;
    return sResult;
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