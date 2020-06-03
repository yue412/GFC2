#ifndef GFC2RELDEFINES_H
#define GFC2RELDEFINES_H

#include "GfcClasses.h"
#include "Gfc2RelationShip.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelDefines: public Gfc2RelationShip
{
GFCENGINE_DEC_OBJECT(Gfc2RelDefines, gfc2::engine::Entity)
public:
    Gfc2RelDefines();
    Gfc2RelDefines(bool bSetSchema);

};
#endif
