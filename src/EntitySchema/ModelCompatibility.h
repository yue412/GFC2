#ifndef MODELCOMPATIBILITY_H
#define MODELCOMPATIBILITY_H

#include <vector>
#include <map>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN

class CModel;

class CClassCompatibility;

class CModelCompatibility
{
public:
    CModelCompatibility(void);
    virtual ~CModelCompatibility(void);
    void init(CModel* pFrom, CModel* pTo);
    CClassCompatibility* find(const std::wstring& sName);
    CClassCompatibility* getItems(int nIndex);
    int getCount();
public:
    void add(CClassCompatibility* pObject);
    void clear();
    std::vector<CClassCompatibility*> m_oClassList;
    std::map<std::wstring, CClassCompatibility*> m_oClassIndex;
};

GFC_NAMESPACE_END

#endif
