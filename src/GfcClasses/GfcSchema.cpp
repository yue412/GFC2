#include "GfcSchema.h"
#include <assert.h>
#include "Model.h"

gfc2::schema::CTypeObject* findSchema(const std::wstring& sName)
{
    assert(g_pModel);
    gfc2::schema::CTypeObject* pType =  g_pModel ? g_pModel->findTypeObject(sName) : nullptr;
    assert(pType);
    return pType;
}
