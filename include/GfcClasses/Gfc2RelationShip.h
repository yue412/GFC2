#ifndef GFC2RELATIONSHIP_H
#define GFC2RELATIONSHIP_H

#include "GfcClasses.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelationShip: public gfc::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2RelationShip, gfc::engine::Entity)
public:
    Gfc2RelationShip();
    Gfc2RelationShip(bool bSetSchema);
    void setName(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getName() const;
    bool hasName() const;
    std::shared_ptr<Gfc2Label> getNamePtr();

};
#endif
