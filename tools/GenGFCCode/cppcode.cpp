#include "cppcode.h"
#include "assert.h"

CppCode::CppCode()
{
}

CppCode::~CppCode()
{

}

CppCode *CppCode::add(CppCode *pCode)
{
    assert(false);
    return NULL;
}

CppCode *CppCode::addLine(const std::wstring &sCode, bool bIgnoreIndent)
{
    assert(false);
    return NULL;
}

int CppCode::count()
{
    return 0;
}

CppCode *CppCode::code(int nIndex)
{
    return NULL;
}

CppCode *CppCode::createBlock(CppCode *pParentCode, bool bWithSemicolon)
{
    return createIndent(createBlockOnly(pParentCode, bWithSemicolon));
}

CppCode *CppCode::createBlockOnly(CppCode *pParentCode, bool bWithSemicolon)
{
    assert(pParentCode);
    CBlock* pBlock = new CBlock(bWithSemicolon);
    pParentCode->add(pBlock);
    return pBlock;
}

CppCode *CppCode::createIndent(CppCode *pParentCode)
{
    assert(pParentCode);
    CIndent* pIndent = new CIndent();
    pParentCode->add(pIndent);
    return pIndent;
}

CppCode *CppCode::createGroup(CppCode *pParentCode)
{
    assert(pParentCode);
    CppCode* pGroup = new CGroupCode();
    pParentCode->add(pGroup);
    return pGroup;
}

CStatement::CStatement(const std::wstring &sCode, bool bIgnoreIndent): m_sCode(sCode), m_bIgnoreIndent(bIgnoreIndent)
{

}

std::wstring CStatement::toString(int nIndent)
{
    assert(nIndent >= 0);
    if (m_sCode == L"\n" || m_bIgnoreIndent)
        return m_sCode;
    else
        return std::wstring(nIndent, ' ') + m_sCode;
}

CppCode *CStatement::clone()
{
    return new CStatement(*this);
}

CGroupCode::~CGroupCode()
{
    for(auto itr = m_oCodeList.begin(); itr != m_oCodeList.end(); ++itr)
    {
        delete *itr;
    }
    m_oCodeList.clear();
}

CppCode *CGroupCode::add(CppCode *pCode)
{
    assert(pCode);
    m_oCodeList.push_back(pCode);
    return this;
}

int CGroupCode::count()
{
    return m_oCodeList.size();
}

CppCode *CGroupCode::code(int nIndex)
{
    return m_oCodeList[nIndex];
}

void CGroupCode::cloneChild(CGroupCode* pCode)
{
    for(auto itr = m_oCodeList.begin(); itr != m_oCodeList.end(); ++itr)
    {
        pCode->m_oCodeList.push_back((*itr)->clone());
    }
}

CppCode *CGroupCode::clone()
{
    CGroupCode* pCode = new CGroupCode;
    cloneChild(pCode);
    return pCode;
}

CppCode *CGroupCode::addLine(const std::wstring &sCode, bool bIgnoreIndent)
{
    add(new CStatement(sCode + L"\n", bIgnoreIndent));
    return this;
}

std::wstring CGroupCode::toString(int nIndent)
{
    std::wstring sResult;
    for(auto itr = m_oCodeList.begin(); itr != m_oCodeList.end(); ++itr)
    {
        sResult += (*itr)->toString(nIndent);
    }
    return sResult;
}

CBlock::CBlock(bool bWithSemicolon): m_bWithSemicolon(bWithSemicolon)
{

}

std::wstring CBlock::toString(int nIndent)
{
    std::wstring sEnd = m_bWithSemicolon ? L";" : L"";
    std::wstring sTemp = std::wstring(nIndent, ' ');
    return sTemp + L"{\n" + CGroupCode::toString(nIndent) + sTemp + L"}" + sEnd + L"\n";
}

CppCode *CBlock::clone()
{
    CBlock* pCode = new CBlock(m_bWithSemicolon);
    cloneChild(pCode);
    return pCode;
}


CIndent::CIndent(int nIndent): m_nIndent(nIndent)
{

}

std::wstring CIndent::toString(int nIndent)
{
    return CGroupCode::toString(nIndent + m_nIndent);
}

CppCode *CIndent::clone()
{
    CIndent* pCode = new CIndent(m_nIndent);
    cloneChild(pCode);
    return pCode;
}
