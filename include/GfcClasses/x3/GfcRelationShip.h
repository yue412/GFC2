#ifndef GFCRELATIONSHIP_H
#define GFCRELATIONSHIP_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelationShip: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcRelationShip, gfc::engine::CEntity)
public:
    GfcRelationShip();
    GfcRelationShip(bool bSetSchema);
    void setName(const GfcLabel& sValue);
    GfcLabel getName() const;
    bool hasName() const;

};

GFCCLASSES_NAMESPACE_END

#endif
