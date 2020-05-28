#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <string>
#include "GfcEngine\GfcEngine.h"

namespace gfc2 {
    namespace schema {
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Entity;

class GFCENGINE_API EntityFactory
{
public:
    EntityFactory(gfc2::schema::CModel* pModel, bool bOwnerModel = true);
    ~EntityFactory();
public:
    Entity* create(const std::string& sName);
    gfc2::schema::CModel* schema() { return m_pModel; }
private:
    void clear();
    gfc2::schema::CModel* m_pModel;
    bool m_bOwnerModel;
};

GFCENGINE_NAMESPACE_END

#endif

