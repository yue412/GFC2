#ifndef MODELCOMPATIBILITY_H
#define MODELCOMPATIBILITY_H

#include <vector>
#include <map>
#include "GfcEngine\GfcEngine.h"

namespace gfc {
    namespace schema {
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CClassCompatibility;

class CModelCompatibility
{
public:
    CModelCompatibility(void);
    virtual ~CModelCompatibility(void);
    void init(gfc::schema::CModel* pFrom, gfc::schema::CModel* pTo);
    CClassCompatibility* find(const std::wstring& sName);
    CClassCompatibility* getItems(int nIndex);
    int getCount();
public:
    void add(CClassCompatibility* pObject);
    void clear();
    std::vector<CClassCompatibility*> m_oClassList;
    std::map<std::wstring, CClassCompatibility*> m_oClassIndex;
};

GFCENGINE_NAMESPACE_END

#endif
