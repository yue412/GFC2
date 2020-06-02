#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <string>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\SysMarco.h"

namespace gfc2 {
    namespace schema {
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Entity;

class GFCENGINE_API EntityFactory
{
    GFCENGINE_DEC_FACTORY(EntityFactory, 0, std::wstring)
public:
    EntityFactory(gfc2::schema::CModel* pModel, bool bOwnerModel = true);
    ~EntityFactory();
public:
    Entity* create(const std::wstring& sName);
    gfc2::schema::CModel* schema() { return m_pModel; }
private:
    void clear();
    gfc2::schema::CModel* m_pModel;
    bool m_bOwnerModel;
};

GFCENGINE_NAMESPACE_END

#endif

