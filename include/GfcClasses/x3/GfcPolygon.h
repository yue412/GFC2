#ifndef GFCPOLYGON_H
#define GFCPOLYGON_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPolygon: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcPolygon, gfc::engine::CEntity)
public:
    GfcPolygon();
    GfcPolygon(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
