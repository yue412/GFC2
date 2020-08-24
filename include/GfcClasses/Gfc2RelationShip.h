#ifndef GFC2RELATIONSHIP_H
#define GFC2RELATIONSHIP_H

#include "GfcClasses.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelationShip: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2RelationShip, gfc::engine::CEntity)
public:
    Gfc2RelationShip();
    Gfc2RelationShip(bool bSetSchema);
    void setName(const Gfc2Label& sValue);
    Gfc2Label getName() const;
    bool hasName() const;

};
#endif
