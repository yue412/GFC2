#ifndef GFC2RELDEFINES_H
#define GFC2RELDEFINES_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelationShip.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelDefines: public Gfc2RelationShip
{
GFCENGINE_DEC_OBJECT(Gfc2RelDefines, gfc::engine::CEntity)
public:
    Gfc2RelDefines();
    Gfc2RelDefines(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
