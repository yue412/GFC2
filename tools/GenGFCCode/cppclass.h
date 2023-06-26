#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <string>
#include <vector>
#include "cppcode.h"

enum CAccessTypeEnum
{
    AT_PRIVATE,
    AT_PROTECTED,
    AT_PUBLIC
};

enum CFuncTypeEnum
{
    FT_NORMAL,
    FT_CONSTRUCTOR,
    FT_DESTRUCTOR
};

class CFunction;

class CppClass
{
public:
    CppClass(const std::wstring& sName);
    CppClass(const std::wstring& sName, CAccessTypeEnum nAccess, const std::wstring& sParentClass);
    ~CppClass();
    void addFunc(CAccessTypeEnum nAccess, CFunction* pFunc);
    CFunction* addFunc(CAccessTypeEnum nAccess, const std::wstring& sResultType, const std::wstring& sName,
                       bool bIsConst = false, bool bIsVirtual = false, bool bIsInline = false);
    CFunction* addConstructor(CAccessTypeEnum nAccess);
    CFunction* addDestructor(CAccessTypeEnum nAccess);
    void addData(CAccessTypeEnum nAccess, const std::wstring& sType, const std::wstring& sName);
    CppCode* createDeclareCode(bool b4cli = false);
    CppCode* createImpCode();
    const std::wstring& name() {return m_sName;}
    void setParent(CAccessTypeEnum nAccess, const std::wstring& sParent);
    void setMarcoCode(const std::wstring& sMarcoCode);
    void setExportFlag(const std::wstring& sExportFlag);
private:
    std::vector<CFunction*> m_oFuncListArray[3];
    std::vector<std::pair<std::wstring, std::wstring> > m_oDataListArray[3];
    std::wstring m_sName;
    std::wstring m_sParentClass;
    std::wstring m_sMarcoCode;
    std::wstring m_sExportFlag;
    CAccessTypeEnum m_nInheritAccessType;
};

class CParam;

class CFunction
{
public:
    CFunction(const std::wstring& sResultType, const std::wstring& sName);
    CFunction(CFuncTypeEnum nType);
    ~CFunction();
    bool isInline() {return m_bIsInline;}
    void setIsInline(bool bIsInline) {m_bIsInline = bIsInline;}
    std::wstring& resultType() {return m_sResultType;}
    void setResultType(const std::wstring& sResultType) {m_sResultType = sResultType;}
    bool isConst() {return m_bIsConst;}
    void setIsConst(bool bIsConst) {m_bIsConst = bIsConst;}
    void addParam(CParam* pParam);
    void addParam(const std::wstring& sResultType, const std::wstring& sName);
    void addParam(const std::wstring& sResultType, const std::wstring& sName, const std::wstring& sDefault);
    int getParamCount();
    CParam* params(int nIndex);
    CppCode* body();

    CFuncTypeEnum type() {return m_nType;}
    void setType(CFuncTypeEnum nType) {m_nType = nType;}
    void addInitListItem(const std::wstring& sName, const std::wstring& sDefault);
    void addInitListItem(const std::wstring& sItem);
    int getInitListCount();
    std::wstring getInitListItem(int nIndex);
    CppCode* createInitListCode();
    std::wstring getInitListStr();

    std::wstring getParamStr(bool bHasDefault);
    std::wstring& name() {return m_sName;}
    bool isVirtual() {return m_bIsVirtual;}
    void setIsVirtual(bool bIsVirtual) {m_bIsVirtual = bIsVirtual;}
private:
    void createBlock();
    std::wstring m_sName;
    std::wstring m_sResultType;
    std::vector<CParam*> m_oParams;
    std::vector<std::wstring> m_oInitList;
    CppCode* m_pBlock;
    CFuncTypeEnum m_nType;
    bool m_bIsInline;
    bool m_bIsConst;
    bool m_bIsVirtual;
};

class CParam
{
public:
    CParam(const std::wstring& sResultType, const std::wstring& sName);
    CParam(const std::wstring& sResultType, const std::wstring& sName, const std::wstring& sDefault);
    std::wstring& resultType() {return m_sResultType;}
    void setResultType(const std::wstring& sResultType) {m_sResultType = sResultType;}
    std::wstring& defaultValue() {return m_sDefaultValue;}
    void setDefaultValue(const std::wstring& sDefault) {
        m_sDefaultValue = sDefault;
        m_bHasDefaultValue = true;
    }
    bool hasDefaultValue() {return m_bHasDefaultValue;}
    std::wstring& name() {return m_sName;}
private:
    std::wstring m_sName;
    std::wstring m_sResultType;
    std::wstring m_sDefaultValue;
    bool m_bHasDefaultValue;
};

#endif // CPPCLASS_H
