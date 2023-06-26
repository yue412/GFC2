#ifndef FILEMAP_H
#define FILEMAP_H

#if (defined _WIN32 || defined _WIN64)
#include <Windows.h>
#endif
#include <string>
#include "GfcEngine/GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

class CFileMap
{
public:
    CFileMap(const std::wstring& sFileName);
    ~CFileMap();
    bool init();
    int64_t size() { return m_dwFileSize; }
    char* ptr() { return m_pbFile; }
    std::string getLine(int64_t nStart, int64_t* pEnd);
    int64_t getLineEnd(int64_t nStart);
    int64_t getLineCount();

    int64_t pos() { return m_nPos; }
    void setPos(int64_t nPos);
    std::string getLine();
    bool eof();
private:
#if (defined _WIN32 || defined _WIN64)
    HANDLE m_hFile;
    HANDLE m_hFileMapping;
#endif
    char* m_pbFile;
    std::wstring m_sFileName;
    int64_t m_dwFileSize; // 文件可能超过4G
    int64_t m_nPos;
};

GFCENGINE_NAMESPACE_END

#endif // !FILEMAP_H