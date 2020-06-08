#ifndef FILEMAP_H
#define FILEMAP_H

#include <Windows.h>
#include <string>
#include "GfcEngine\GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

class CFileMap
{
public:
    CFileMap(const std::wstring& sFileName);
    ~CFileMap();
    bool init();
    __int64 size() { return m_dwFileSize; }
    PBYTE ptr() { return m_pbFile; }
    std::string getLine(__int64 nStart, __int64* pEnd);
    __int64 getLineEnd(__int64 nStart);
    __int64 getLineCount();

    __int64 pos() { return m_nPos; }
    void setPos(__int64 nPos);
    std::string getLine();
    bool eof();
private:
    HANDLE m_hFile;
    HANDLE m_hFileMapping;
    PBYTE m_pbFile;
    std::wstring m_sFileName;
    __int64 m_dwFileSize; // 文件可能超过4G
    __int64 m_nPos;
};

GFCENGINE_NAMESPACE_END

#endif // !FILEMAP_H