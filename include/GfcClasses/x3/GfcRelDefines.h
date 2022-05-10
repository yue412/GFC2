#ifndef GFCRELDEFINES_H
#define GFCRELDEFINES_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRelationShip.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelDefines: public GfcRelationShip
{
GFCENGINE_DEC_OBJECT(GfcRelDefines, gfc::engine::CEntity)
public:
    GfcRelDefines();
    GfcRelDefines(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
