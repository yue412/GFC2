#ifndef CPPFILE_H
#define CPPFILE_H

#include <string>
#include "cppcode.h"

class CppBaseFile
{
public:
    CppBaseFile(const std::wstring& sFileNameOnly);
    virtual ~CppBaseFile();
    virtual CppCode* body();
    void saveTo(const std::wstring& sPath = L"");
    void setFileExt(const std::wstring& sExt);
    void addInclude(const std::wstring& sIncludeFile, bool bSystem = false);
    std::wstring fileName() {return m_sFileNameOnly + L'.' + m_sFileExt;}
    std::wstring fileNameOnly() {return m_sFileNameOnly;}
protected:
    CppCode* m_pBody;
    CppCode* m_pIncludeGroup;
private:
    std::wstring m_sFileNameOnly;
    std::wstring m_sFileExt;
};

class CppHeadFile: public CppBaseFile
{
public:
    CppHeadFile(const std::wstring& sFileNameOnly);
    virtual CppCode* body();
private:
    CppCode* m_pIntfCode;
};

class CppFile: public CppBaseFile
{
public:
    //CppFile(const std::wstring& sFileNameOnly, CppHeadFile* pHeadFile, bool bHasPreCompleHead);
    CppFile(const std::wstring& sFileNameOnly, const std::wstring& sHeadRelativePath, bool bHasPreCompleHead);
};

#endif // CPPFILE_H
