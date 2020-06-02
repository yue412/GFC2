#ifndef GFC2RELATIONSHIP_H
#define GFC2RELATIONSHIP_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "TypeDef.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelationShip: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2RelationShip,gfc2::engine::EntityFactory)
public:
    Gfc2RelationShip();
    Gfc2RelationShip(bool bSetSchema);
    void setName(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getName() const;
    bool hasName() const;
    std::shared_ptr<Gfc2Label> getNamePtr();

};
#endif
