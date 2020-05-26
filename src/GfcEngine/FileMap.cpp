#include "FileMap.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

FileMap::FileMap(const std::wstring& sFileName): m_hFile(0), m_hFileMapping(0), m_pbFile(0), m_dwFileSize(0), m_sFileName(sFileName), m_nPos(0)
{
}

bool FileMap::init()
{
    m_hFile = ::CreateFile(m_sFileName.c_str(),
        GENERIC_READ,
        0,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (INVALID_HANDLE_VALUE == m_hFile)
    {
        assert(false);
        return false;
    }
    
    // Create a file-mapping object for the file.

    m_hFileMapping = ::CreateFileMapping(m_hFile,
        NULL,
        PAGE_READONLY,
        0, 0,
        NULL);
    if (NULL == m_hFileMapping)
    {
        CloseHandle(m_hFile);
        m_hFile = 0;
        assert(false);
        return false;
    }

    GetFileSizeEx(m_hFile, (PLARGE_INTEGER)&m_dwFileSize);
    m_pbFile = (PBYTE)::MapViewOfFile(m_hFileMapping, FILE_MAP_READ, 0, 0, 0);
    if (NULL == m_pbFile)
    {
        CloseHandle(m_hFileMapping); m_hFileMapping = 0;
        CloseHandle(m_hFile); m_hFile = 0;
        assert(false);
        return false;
    }
    return true;
}

std::string FileMap::getLine(__int64 nStart, __int64 * pEnd)
{
    __int64 i = nStart;
    while (i < size())
    {
        if (*(ptr() + i) == '\n')
        {
            auto nOffset = (i == nStart || *(ptr() + i - 1) != '\r') ? 0 : -1;
            if (pEnd)
                *pEnd = i + 1;
            return std::string((char*)(ptr() + nStart), i - nStart + nOffset);
        }
        ++i;
    }
    if (pEnd)
        *pEnd = i;
    return std::string((char*)(ptr() + nStart), i - nStart);
}

__int64 FileMap::getLineEnd(__int64 nStart)
{
    __int64 i = nStart;
    while (i < size())
    {
        if (*(ptr() + i) == '\n')
        {
            return i + 1;
        }
        ++i;
    }
    return i;
}

__int64 FileMap::getLineCount()
{
    __int64 nCount = 0;
    __int64 i = 0;
    __int64 nPos = 0;
    while (i < size())
    {
        if (*(ptr() + i) == '\n')
        {
            nPos = i;
            ++nCount;
        }
        ++i;
    }
    if (nPos != size())
    {
        ++nCount;
    }
    return nCount;
}

void FileMap::setPos(__int64 nPos)
{
    m_nPos = nPos;
}

std::string FileMap::getLine()
{
    __int64 nEnd;
    auto str = getLine(m_nPos, &nEnd);
    setPos(nEnd);
    return str;
}

bool FileMap::eof()
{
    return m_nPos >= m_dwFileSize;
}


FileMap::~FileMap()
{
    if (m_pbFile)
    {
        ::UnmapViewOfFile(m_pbFile);
        ::CloseHandle(m_hFileMapping);
        ::CloseHandle(m_hFile);
    }
}

GFCENGINE_NAMESPACE_END