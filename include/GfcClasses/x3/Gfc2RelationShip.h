#ifndef GFC2RELATIONSHIP_H
#define GFC2RELATIONSHIP_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelationShip: public Gfc2Root
{
GFCENGINE_DEC_OBJECT(Gfc2RelationShip, gfc::engine::CEntity)
public:
    Gfc2RelationShip();
    Gfc2RelationShip(bool bSetSchema);
    void setName(const Gfc2Label& sValue);
    Gfc2Label getName() const;
    bool hasName() const;

};

GFCCLASSES_NAMESPACE_END

#endif
