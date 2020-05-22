#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <string>
#include "GfcEngine\GfcEngine.h"

namespace gfc2 {
    namespace schema {
        class CModel;
        class CAttribute;
        class CClass;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Entity;

class GFCENGINE_API EntityFactory
{
public:
    EntityFactory();
    ~EntityFactory();
public:
    void loadSchema(const std::string& sFileName);
    void loadSchema(const char* buf, int len);
    Entity* create(const std::string& sName);
    // for Test
    void initClass(gfc2::schema::CClass* pClass); 
private:
    void clear();
    void finalize(gfc2::schema::CModel* pModel);
    void initAttr(gfc2::schema::CAttribute* pAttribute);
    gfc2::schema::CModel* m_pModel;
    gfc2::schema::CModel* m_pTempModel;
};

GFCENGINE_NAMESPACE_END

#endif

