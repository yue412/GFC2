#ifndef CLASSCOMPATIBILITY_H
#define CLASSCOMPATIBILITY_H

#include <vector>
#include "GfcSchema\SchemaMacro.h"

GFC_NAMESPACE_BEGIN

class CClass;
class CAttribute;
class CAttributeCompatibility;

class CClassCompatibility
{
public:
    CClassCompatibility(void) {}
    virtual ~CClassCompatibility(void);
public:
    void init(CClass* pFrom, CClass* pTo);
    std::wstring getName() { return m_sName; }
    int getCount() { return (int)m_oList.size(); }
    CAttributeCompatibility* getCompatibilityAttribute(int nIndex) { return m_oList[nIndex]; }
private:
    void getAttributeList(CClass* pClass, std::vector<CAttribute*>& oAttributeList);
    void clear();
    std::vector<CAttributeCompatibility*> m_oList; // all
    std::wstring m_sName;
};

GFC_NAMESPACE_END

#endif
