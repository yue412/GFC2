#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <fstream>

std::wstring FormatWstring(const wchar_t *lpcwszFormat, ...);
std::wstring FormatWstring(const std::wstring sFormat, ...);
std::wstring UpperString(const std::wstring& sStr);
std::wstring LowerString(const std::wstring& sStr);
std::string toString(const std::wstring & src);
std::wstring toWstring(const std::string& src);
std::wstring getExePath();
bool isRelativePath(const std::wstring& sPath);
std::wstring getFullPath(const std::wstring& sPath);
wchar_t * getWC(const char *c);
std::string UnicodeToUtf8(const std::wstring& str);
std::wstring Utf8ToUnicode(const std::string& str);
std::fstream& operator<<(std::fstream& out, const std::wstring& s);
std::fstream& operator<<(std::fstream& out, const wchar_t* s);
bool fileExists(const std::wstring& sFile);

// trim from start (in place)
void ltrim(std::string &s);
// trim from end (in place)
void rtrim(std::string &s);
// trim from both ends (in place)
void trim(std::string &s);
// trim from start (copying)
std::string ltrim_copy(std::string s);
// trim from end (copying)
std::string rtrim_copy(std::string s);
// trim from both ends (copying)
std::string trim_copy(std::string s);

#endif // !COMMON_H

