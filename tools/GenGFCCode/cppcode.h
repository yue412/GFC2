#ifndef CPPCODE_H
#define CPPCODE_H

#include <string>
#include <vector>

class CppCode
{
public:
    CppCode();
    virtual ~CppCode();
    virtual std::wstring toString(int nIndent) = 0;
    virtual CppCode* clone() = 0;
    virtual CppCode* add(CppCode* pCode);
    virtual CppCode* addLine(const std::wstring& sCode, bool bIgnoreIndent = false);
    virtual int count();
    virtual CppCode* code(int nIndex);
    //
    static CppCode* createBlock(CppCode* pParentCode, bool bWithSemicolon = false);
    static CppCode* createBlockOnly(CppCode* pParentCode, bool bWithSemicolon = false);
    static CppCode* createIndent(CppCode* pParentCode);
    static CppCode* createGroup(CppCode* pParentCode);
};

class CStatement: public CppCode
{
public:
    CStatement(const std::wstring& sCode, bool bIgnoreIndent);
    virtual std::wstring toString(int nIndent);
    virtual CppCode* clone();
private:
    std::wstring m_sCode;
    bool m_bIgnoreIndent;
};

class CGroupCode: public CppCode
{
public:
    virtual ~CGroupCode();
    virtual CppCode* add(CppCode* pCode);
    virtual CppCode* addLine(const std::wstring& sCode, bool bIgnoreIndent = false);
    virtual int count();
    virtual CppCode* code(int nIndex);
    virtual CppCode* clone();
//    CGroupCode& addBlock(bool bWithSemicolon = false);
//    CGroupCode& addBlockOnly(bool bWithSemicolon = false);
//    CGroupCode& addIndent();
    virtual std::wstring toString(int nIndent);
    void cloneChild(CGroupCode* pCode);
private:
    std::vector<CppCode*> m_oCodeList;
};

class CBlock: public CGroupCode
{
public:
    CBlock(bool bWithSemicolon);
    virtual std::wstring toString(int nIndent);
    virtual CppCode* clone();
private:
    bool m_bWithSemicolon;
};

class CIndent: public CGroupCode
{
public:
    CIndent(int nIndent = 4);
    virtual std::wstring toString(int nIndent);
    virtual CppCode* clone();
private:
    int m_nIndent;
};

#endif // CPPCODE_H
