#ifndef GFCBODY_H
#define GFCBODY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBody: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcBody, gfc::engine::CEntity)
public:
    GfcBody();
    GfcBody(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
