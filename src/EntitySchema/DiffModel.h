#ifndef DIFFMODEL_H
#define DIFFMODEL_H

#include <vector>
#include <map>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN

class CModel;

class CDiffTypeObject;

class CDiffModel
{
public:
    CDiffModel(void);
    virtual ~CDiffModel(void);
    void compare(CModel* pLeft, CModel* pRight);
    CDiffTypeObject* find(const std::wstring& sName);
    CDiffTypeObject* getItems(int nIndex);
    int getCount();
public:
    void add(CDiffTypeObject* pObject);
    std::vector<CDiffTypeObject*> m_oDiffList;
    std::map<std::wstring, CDiffTypeObject*> m_oDiffIndex;
};

GFC_NAMESPACE_END

#endif
