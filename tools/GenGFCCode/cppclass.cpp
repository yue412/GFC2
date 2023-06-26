#include "cppclass.h"
#include "assert.h"
#include "common.h"

const std::wstring sAccessTypeCode[3]={L"private",L"protected",L"public"};

CppClass::CppClass(const std::wstring &sName): m_nInheritAccessType(AT_PUBLIC), m_sName(sName)
{
}

CppClass::CppClass(const std::wstring &sName, CAccessTypeEnum nAccess, const std::wstring &sParentClass)
    : m_nInheritAccessType(nAccess), m_sName(sName), m_sParentClass(sParentClass)
{

}

CppClass::~CppClass()
{
    for(int i = 0; i < 3; ++i)
    {
        for(auto itr = m_oFuncListArray[i].begin(); itr != m_oFuncListArray[i].end(); ++itr)
        {
            delete *itr;
        }
        m_oFuncListArray[i].clear();

        m_oDataListArray[i].clear();
    }
}

void CppClass::addFunc(CAccessTypeEnum nAccess, CFunction *pFunc)
{
    assert(pFunc);
    m_oFuncListArray[nAccess].push_back(pFunc);
}

CFunction *CppClass::addFunc(CAccessTypeEnum nAccess, const std::wstring &sResultType, const std::wstring &sName,
                             bool bIsConst, bool bIsVirtual, bool bIsInline)
{
    CFunction* pFunc = new CFunction(sResultType, sName);
    pFunc->setIsConst(bIsConst);
    pFunc->setIsInline(bIsInline);
    pFunc->setIsVirtual(bIsVirtual);
    addFunc(nAccess, pFunc);
    return pFunc;
}

CFunction *CppClass::addConstructor(CAccessTypeEnum nAccess)
{
    CFunction* pFunc = new CFunction(FT_CONSTRUCTOR);
    addFunc(nAccess, pFunc);
    return pFunc;
}

CFunction *CppClass::addDestructor(CAccessTypeEnum nAccess)
{
    CFunction* pFunc = new CFunction(FT_DESTRUCTOR);
    addFunc(nAccess, pFunc);
    return pFunc;
}

void CppClass::addData(CAccessTypeEnum nAccess, const std::wstring &sType, const std::wstring &sName)
{
    m_oDataListArray[nAccess].push_back(std::make_pair(sType, sName));
}

CppCode *CppClass::createDeclareCode(bool b4cli)
{
    CppCode* pCode = new CGroupCode();
    if (m_sParentClass.empty())
        pCode->addLine(FormatWstring(L"%lsclass %ls%ls",
            b4cli ? L"public ref " : L"",
            m_sExportFlag.empty() ? L"" : (m_sExportFlag + L" ").c_str(),
            m_sName.c_str()));
    else
        pCode->addLine(FormatWstring(L"%lsclass %ls%ls: %ls %ls",
            b4cli ? L"public ref " : L"",
            m_sExportFlag.empty() ? L"" : (m_sExportFlag + L" ").c_str(), 
            m_sName.c_str(),
            sAccessTypeCode[m_nInheritAccessType].c_str(),
            m_sParentClass.c_str()
            ));
    CppCode* pBlock = CppCode::createBlockOnly(pCode, true);
    if(!m_sMarcoCode.empty())
        pBlock->addLine(m_sMarcoCode);
    for(int i = 2; i >= 0; --i)
    {
        if(m_oFuncListArray[i].size() == 0 && m_oDataListArray[i].size() == 0)
            continue;
        pBlock->addLine(sAccessTypeCode[i] + L":");
        CppCode* pIndent = CppCode::createIndent(pBlock);
        for(auto itr = m_oFuncListArray[i].begin(); itr != m_oFuncListArray[i].end(); ++itr)
        {
            switch((*itr)->type())
            {
            case FT_CONSTRUCTOR:
                pIndent->addLine(FormatWstring(L"%ls(%ls)%ls",
                    m_sName.c_str(),
                    (*itr)->getParamStr(true).c_str(),
                    (*itr)->isInline() ? (*itr)->getInitListCount() > 0 ? L":" : L"" : L";"
                ));
                if((*itr)->isInline() && (*itr)->getInitListCount() > 0)
                    pIndent->add((*itr)->createInitListCode());
                break;
            case FT_DESTRUCTOR:
                pIndent->addLine(FormatWstring(L"~%ls(%ls)%ls",
                    m_sName.c_str(),
                    (*itr)->getParamStr(true).c_str(),
                    (*itr)->isInline() ? L"" : L";"
                ));
                break;
            default:
                std::wstring sTemp;
                if ((*itr)->isInline() && (*itr)->body()->count() == 1)
                {
                    sTemp = (*itr)->body()->code(0)->toString(0);
                    sTemp = L" {" + sTemp.substr(0, sTemp.length() - 1) + L"}";
                }
                pIndent->addLine(FormatWstring(L"%ls%ls %ls(%ls)%ls%ls",
                    (*itr)->isVirtual() ? L"virtual " : L"",
                    (*itr)->resultType().c_str(),
                    (*itr)->name().c_str(),
                    (*itr)->getParamStr(true).c_str(),
                    (*itr)->isConst() ? L" const" : L"",
                    (*itr)->isInline() ? sTemp.c_str() : L";"
                ));
                if ((*itr)->isInline() && (*itr)->body()->count() == 1)
                {
                    continue;
                }
            }
            if((*itr)->isInline())
                pIndent->add((new CBlock(false))->add((*itr)->body()->clone()));

        }
        if(m_oFuncListArray[i].size() > 0)
        {
            pIndent->addLine(L"");
        }
        for(auto itr = m_oDataListArray[i].begin(); itr != m_oDataListArray[i].end(); ++itr)
        {
            pIndent->addLine(FormatWstring(L"%ls %ls;",
                itr->first.c_str(),
                itr->second.c_str()
            ));
        }
    }
    return pCode;
}

CppCode *CppClass::createImpCode()
{
    CppCode* pCode = new CGroupCode();
    for(int i = 2; i >= 0; --i)
    {
        for(auto itr = m_oFuncListArray[i].begin(); itr != m_oFuncListArray[i].end(); ++itr)
        {
            if((*itr)->isInline())
                continue;
            switch((*itr)->type())
            {
            case FT_CONSTRUCTOR:
                pCode->addLine(FormatWstring(L"%ls::%ls(%ls)%ls",
                    m_sName.c_str(),
                    m_sName.c_str(),
                    (*itr)->getParamStr(false).c_str(),
                    (*itr)->getInitListCount() > 0 ? L":" : L""
                ));
                if((*itr)->getInitListCount() > 0)
                    pCode->add((*itr)->createInitListCode());
                break;
            case FT_DESTRUCTOR:
                pCode->addLine(FormatWstring(L"~%ls::%ls(%ls)",
                    m_sName.c_str(),
                    m_sName.c_str(),
                    (*itr)->getParamStr(false).c_str()
                ));
                break;
            default:
                pCode->addLine(FormatWstring(L"%ls %ls::%ls(%ls)%ls",
                    (*itr)->resultType().c_str(),
                    m_sName.c_str(),
                    (*itr)->name().c_str(),
                    (*itr)->getParamStr(false).c_str(),
                    (*itr)->isConst() ? L" const" : L""
                ));
            }
            pCode->add((new CBlock(false))->add((*itr)->body()->clone()));
            pCode->addLine(L"");

        }
    }
    return pCode;
}

void CppClass::setParent(CAccessTypeEnum nAccess, const std::wstring &sParent)
{
    m_nInheritAccessType = nAccess;
    m_sParentClass = sParent;
}

void CppClass::setMarcoCode(const std::wstring &sMarcoCode)
{
    m_sMarcoCode = sMarcoCode;
}

void CppClass::setExportFlag(const std::wstring &sExportFlag)
{
    m_sExportFlag = sExportFlag;
}


CParam::CParam(const std::wstring &sResultType, const std::wstring &sName):
    m_sName(sName), m_sResultType(sResultType), m_bHasDefaultValue(false)
{

}

CParam::CParam(const std::wstring &sResultType, const std::wstring &sName, const std::wstring &sDefault):
    m_sName(sName), m_sResultType(sResultType), m_sDefaultValue(sDefault), m_bHasDefaultValue(true)
{

}


CFunction::CFunction(const std::wstring &sResultType, const std::wstring &sName):
    m_sName(sName), m_sResultType(sResultType), m_bIsConst(false), m_bIsInline(false), m_bIsVirtual(false), m_nType(FT_NORMAL)
{
    createBlock();
}

CFunction::CFunction(CFuncTypeEnum nType):
    m_bIsConst(false), m_bIsInline(false), m_bIsVirtual(false), m_nType(nType)
{
    createBlock();
}

void CFunction::createBlock()
{
    m_pBlock = new CIndent();
}

CFunction::~CFunction()
{
    delete m_pBlock;
    for(auto itr = m_oParams.begin(); itr != m_oParams.end(); ++itr)
    {
        delete *itr;
    }
    m_oParams.clear();
}

void CFunction::addParam(CParam *pParam)
{
    assert(pParam);
    m_oParams.push_back(pParam);
}

void CFunction::addParam(const std::wstring &sResultType, const std::wstring &sName)
{
    addParam(new CParam(sResultType, sName));
}

void CFunction::addParam(const std::wstring &sResultType, const std::wstring &sName, const std::wstring &sDefault)
{
    addParam(new CParam(sResultType, sName, sDefault));
}

int CFunction::getParamCount()
{
    return m_oParams.size();
}

CParam *CFunction::params(int nIndex)
{
    return m_oParams[nIndex];
}

CppCode *CFunction::body()
{
    return m_pBlock;
}

void CFunction::addInitListItem(const std::wstring &sName, const std::wstring &sDefault)
{
    m_oInitList.push_back(FormatWstring(L"%ls(%ls)",
        sName.c_str(),
        sDefault.c_str()
    ));
}

void CFunction::addInitListItem(const std::wstring &sItem)
{
    m_oInitList.push_back(sItem);
}

int CFunction::getInitListCount()
{
    return m_oInitList.size();
}

std::wstring CFunction::getInitListItem(int nIndex)
{
    return m_oInitList[nIndex];
}

CppCode *CFunction::createInitListCode()
{
    CppCode* pCode = new CIndent();
    int nCount = m_oInitList.size();
    for(int i = 0; i < nCount; ++i)
    {
        std::wstring sTemp = m_oInitList[i];
        if (i == nCount - 1)
            pCode->addLine(sTemp);
        else
            pCode->addLine(sTemp + L",");
    }
    return pCode;
}

std::wstring CFunction::getInitListStr()
{
    std::wstring sResult;
    for(auto itr = m_oInitList.begin(); itr != m_oInitList.end(); ++itr)
    {
        sResult += FormatWstring(L"%ls, ", (*itr).c_str());
    }
    if(!sResult.empty())
        sResult = sResult.substr(0, sResult.length() - 2);
    return sResult;
}

std::wstring CFunction::getParamStr(bool bHasDefault)
{
    std::wstring sResult;
    for(auto itr = m_oParams.begin(); itr != m_oParams.end(); ++itr)
    {
        if (bHasDefault && (*itr)->hasDefaultValue())
            sResult += FormatWstring(L"%ls %ls = %ls, ",
                (*itr)->resultType().c_str(),
                (*itr)->name().c_str(),
                (*itr)->defaultValue().c_str()
            );
        else
            sResult += FormatWstring(L"%ls %ls, ",
                (*itr)->resultType().c_str(),
                (*itr)->name().c_str()
            );
    }
    if(!sResult.empty())
        sResult = sResult.substr(0 , sResult.length() - 2);
    return sResult;
}
