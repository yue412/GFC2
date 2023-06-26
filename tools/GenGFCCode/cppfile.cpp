#include "cppfile.h"
#include "common.h"
#include <fstream>
#include <iostream>

CppBaseFile::CppBaseFile(const std::wstring &sFileNameOnly):
    m_sFileNameOnly(sFileNameOnly), m_pBody(NULL), m_pIncludeGroup(NULL)
{
    m_pBody = new CGroupCode;
}

CppBaseFile::~CppBaseFile()
{
    delete m_pBody;
}

CppCode *CppBaseFile::body()
{
    return m_pBody;
}

void CppBaseFile::saveTo(const std::wstring &sPath)
{
    std::wstring sNew = m_pBody->toString(0);
    bool bSame = false;
    {/*
        std::wfstream oFile;
        oFile.open(sPath + L"\\" + fileName(), std::ios::in);
        if (oFile.good())
        {
            // get length of file:
            oFile.seekg(0, oFile.end);
            int length = (int)oFile.tellg();
            oFile.seekg(0, oFile.beg);

            wchar_t * sOld = new wchar_t[length];
            try
            {
                oFile.read(sOld, length);
            }
            catch (...)
            {
                std::wcout << "errorr";
            }
            bSame = sNew.compare(sOld) == 0;
            delete[] sOld;
        }
        oFile.close();*/
    }
    if (!bSame)
    {
        std::wfstream oFile;
        auto sFileName = UnicodeToACP(sPath + L"/" + fileName());
        oFile.open(sFileName, std::ios::out);
        if (oFile.good())
        {
            oFile << sNew;
            oFile.close();
        }
    }
}

void CppBaseFile::setFileExt(const std::wstring &sExt)
{
    m_sFileExt = sExt;
}

void CppBaseFile::addInclude(const std::wstring &sIncludeFile, bool bSystem)
{
    if(m_pIncludeGroup == 0)
    {
        m_pIncludeGroup = new CGroupCode;
        body()->add(m_pIncludeGroup);
        body()->addLine(L"");
    }
    if(bSystem)
        m_pIncludeGroup->addLine(FormatWstring(L"#include <%ls>", 
            sIncludeFile.c_str()
        ));
    else
        m_pIncludeGroup->addLine(FormatWstring(L"#include \"%ls\"",
            sIncludeFile.c_str()
        ));
}


CppHeadFile::CppHeadFile(const std::wstring& sFileNameOnly): CppBaseFile(sFileNameOnly)
{
    m_pBody->addLine(FormatWstring(L"#ifndef %ls_H", 
        UpperString(sFileNameOnly).c_str()
    ));
    m_pBody->addLine(FormatWstring(L"#define %ls_H", 
        UpperString(sFileNameOnly).c_str()
    ));
    m_pBody->addLine(L"");
    m_pIntfCode = new CGroupCode();
    m_pBody->add(m_pIntfCode);
    m_pBody->addLine(L"#endif");
    setFileExt(L"h");
}

CppCode *CppHeadFile::body()
{
    return m_pIntfCode;
}

/*
CppFile::CppFile(const std::wstring &sFileNameOnly, CppHeadFile *pHeadFile, bool bHasPreCompleHead): CppBaseFile(sFileNameOnly)
{
    setFileExt(L"cpp");
    if(pHeadFile)
    {
        if (bHasPreCompleHead)
            m_pBody->addLine(L"#include \"StdAfx.h\"");
        m_pBody->addLine(FormatWstring(L"#include \"%ls\"",
            pHeadFile->fileName().c_str()
        ));
    }
}
*/

CppFile::CppFile(const std::wstring &sFileNameOnly, const std::wstring& sHeadRelativePath, bool bHasPreCompleHead): CppBaseFile(sFileNameOnly)
{
    setFileExt(L"cpp");
    if (bHasPreCompleHead)
        m_pBody->addLine(L"#include \"StdAfx.h\"");
    m_pBody->addLine(FormatWstring(L"#include \"%ls.h\"", 
        (sHeadRelativePath + sFileNameOnly).c_str()
    ));
}
