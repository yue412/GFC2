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
class Entity;

class Upgrader
{
public:
    Upgrader() : m_pModelCompatibility(nullptr) {}
    ~Upgrader();
    void init(gfc::schema::CModel* pModel, gfc::schema::CModel* pFileModel);
    Entity* update(Entity* pEntity);
    // for test
    void transform(CClassCompatibility* pClassCompatibility, Entity* pSrcEntity, Entity* pDestEntity);
private:
    void clear();
    gfc::schema::CModel* m_pModel;
    gfc::schema::CModel* m_pFileModel;
    CModelCompatibility* m_pModelCompatibility;
};

GFCENGINE_NAMESPACE_END

#endif // !TEXTUPDATER_H

