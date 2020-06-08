#ifndef TEXTUPDATER_H
#define TEXTUPDATER_H

#include "GfcEngine\GfcEngine.h"
#include "GfcSchema\SchemaMacro.h"
#include <string>

GFC_NAMESPACE_BEGIN

class CModel;
class CAttributeValue;

GFC_NAMESPACE_END

GFCENGINE_NAMESPACE_BEGIN

class CModelCompatibility;
class CClassCompatibility;
class CEntity;

class CUpgrader
{
public:
    CUpgrader() : m_pModelCompatibility(nullptr) {}
    ~CUpgrader();
    void init(gfc::schema::CModel* pModel, gfc::schema::CModel* pFileModel);
    CEntity* update(CEntity* pEntity);
    // for test
    void transform(CClassCompatibility* pClassCompatibility, CEntity* pSrcEntity, CEntity* pDestEntity);
private:
    void clear();
    gfc::schema::CModel* m_pModel;
    gfc::schema::CModel* m_pFileModel;
    CModelCompatibility* m_pModelCompatibility;
};

GFCENGINE_NAMESPACE_END

#endif // !TEXTUPDATER_H

