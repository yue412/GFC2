#include "Schema.h"
#include <assert.h>
#include "GfcSchema/Model.h"

gfc::schema::CTypeObject* findSchema(const std::wstring& sName)
{
    assert(g_pModel);
    gfc::schema::CTypeObject* pType =  g_pModel ? g_pModel->findTypeObject(sName) : nullptr;
    assert(pType);
    return pType;
}
