#ifndef GFC2RELCONNECTS_H
#define GFC2RELCONNECTS_H

#include "GfcClasses.h"
#include "Gfc2RelationShip.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelConnects: public Gfc2RelationShip
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnects, gfc::engine::Entity)
public:
    Gfc2RelConnects();
    Gfc2RelConnects(bool bSetSchema);

};
#endif
