#ifndef GFC2RELCONNECTS_H
#define GFC2RELCONNECTS_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RelationShip.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelConnects: public Gfc2RelationShip
{
GFCENGINE_DEC_OBJECT(Gfc2RelConnects,gfc2::engine::EntityFactory)
public:
    Gfc2RelConnects();
    Gfc2RelConnects(bool bSetSchema);

};
#endif
