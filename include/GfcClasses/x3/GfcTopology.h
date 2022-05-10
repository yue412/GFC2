#ifndef GFCTOPOLOGY_H
#define GFCTOPOLOGY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcTopology: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcTopology, gfc::engine::CEntity)
public:
    GfcTopology();
    GfcTopology(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
