#ifndef CLASSCOMPATIBILITY_H
#define CLASSCOMPATIBILITY_H

#include <vector>
#include "GfcEngine\GfcEngine.h"

namespace gfc {
    namespace schema {
        class CClass;
        class CAttribute;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CAttributeCompatibility;

class GFCENGINE_API CClassCompatibility
{
public:
    CClassCompatibility(void) {}
    virtual ~CClassCompatibility(void);
public:
    void init(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
    std::wstring getName() { return m_sName; }
    int getCount() { return (int)m_oList.size(); }
    CAttributeCompatibility* getCompatibilityAttribute(int nIndex) { return m_oList[nIndex]; }
private:
    void getAttributeList(gfc::schema::CClass* pClass, std::vector<gfc::schema::CAttribute*>& oAttributeList);
    void clear();
    std::vector<CAttributeCompatibility*> m_oList; // all
    std::wstring m_sName;
};

GFCENGINE_NAMESPACE_END

#endif
