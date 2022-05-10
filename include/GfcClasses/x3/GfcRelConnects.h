#ifndef GFCRELCONNECTS_H
#define GFCRELCONNECTS_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRelationShip.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelConnects: public GfcRelationShip
{
GFCENGINE_DEC_OBJECT(GfcRelConnects, gfc::engine::CEntity)
public:
    GfcRelConnects();
    GfcRelConnects(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
