#ifndef COMMON_H
#define COMMON_H

#include <string>

std::wstring FormatWstring(const wchar_t *lpcwszFormat, ...);
std::wstring FormatWstring(const std::wstring sFormat, ...);
std::wstring UpperString(const std::wstring& sStr);
std::wstring LowerString(const std::wstring& sStr);
std::string toString(const std::wstring & src);
std::wstring toWstring(const std::string& src);
std::wstring getExePath();
bool isRelativePath(const std::wstring& sPath);
std::wstring getFullPath(const std::wstring& sPath);

#endif // !COMMON_H

