#include "FileMap.h"
#include <assert.h>
#if (defined _WIN32 || defined _WIN64)
#include <Windows.h>
#else
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif
#include "Common.h"
GFCENGINE_NAMESPACE_BEGIN

CFileMap::CFileMap(const std::wstring& sFileName): 
#if (defined _WIN32 || defined _WIN64)
    m_hFile(0), m_hFileMapping(0),
#endif
    m_pbFile(0), m_dwFileSize(0), m_sFileName(sFileName), m_nPos(0)
{
}

bool CFileMap::init()
{
#if (defined _WIN32 || defined _WIN64)
    m_hFile = ::CreateFile(m_sFileName.c_str(),
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (INVALID_HANDLE_VALUE == m_hFile)
    {
        //assert(false);
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
        //assert(false);
        return false;
    }

    GetFileSizeEx(m_hFile, (PLARGE_INTEGER)&m_dwFileSize);
    m_pbFile = (char*)::MapViewOfFile(m_hFileMapping, FILE_MAP_READ, 0, 0, 0);
    if (NULL == m_pbFile)
    {
        CloseHandle(m_hFileMapping); m_hFileMapping = 0;
        CloseHandle(m_hFile); m_hFile = 0;
        //assert(false);
        return false;
    }
    
#else
    int fd;
    char * buf;
    struct stat sb;
    char buf_test[40];

    auto filename = UnicodeToUtf8(m_sFileName);
    fd = open(filename.c_str(), O_RDWR, S_IRUSR);
    if (fd == -1)
    {
        perror("open failed!\n");
        return false;
    }
    if (fstat(fd, &sb) == -1)
    {
        perror("fstat failed\n");
        return false;
    }
    m_dwFileSize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    m_pbFile = (char*)mmap(0, m_dwFileSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (m_pbFile == MAP_FAILED)
    {
        perror("mmap failed!\n");
        return false;
    }
    if (close(fd) == -1)
    {
        perror("close failed!\n");
        return false;
    }

#endif
    return true;
}

std::string CFileMap::getLine(int64_t nStart, int64_t * pEnd)
{
    int64_t i = nStart;
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

int64_t CFileMap::getLineEnd(int64_t nStart)
{
    int64_t i = nStart;
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

int64_t CFileMap::getLineCount()
{
    int64_t nCount = 0;
    int64_t i = 0;
    int64_t nPos = 0;
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

void CFileMap::setPos(int64_t nPos)
{
    m_nPos = nPos;
}

std::string CFileMap::getLine()
{
    int64_t nEnd;
    auto str = getLine(m_nPos, &nEnd);
    setPos(nEnd);
    return str;
}

bool CFileMap::eof()
{
    return m_nPos >= m_dwFileSize;
}


CFileMap::~CFileMap()
{
#if (defined _WIN32 || defined _WIN64)
    if (m_pbFile)
    {
        ::UnmapViewOfFile(m_pbFile);
        ::CloseHandle(m_hFileMapping);
        ::CloseHandle(m_hFile);
    }
#else
    if ((munmap(m_pbFile, m_dwFileSize)) == -1)
    {
        perror("munmap failed");
    }
#endif
}

GFCENGINE_NAMESPACE_END