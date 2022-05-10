#ifndef GFCGEOMETRY_H
#define GFCGEOMETRY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcGeometry: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcGeometry, gfc::engine::CEntity)
public:
    GfcGeometry();
    GfcGeometry(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
