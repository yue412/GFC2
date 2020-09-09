#ifndef GFC2RELCONNECTS_H
#define GFC2RELCONNECTS_H

#include "GfcClasses.h"
#include "Gfc2RelationShip.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelConnects: public Gfc2RelationShip
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnects, gfc::engine::CEntity)
public:
    Gfc2RelConnects();
    Gfc2RelConnects(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
