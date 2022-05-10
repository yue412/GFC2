#ifndef GFCBLOCKSHAPE_H
#define GFCBLOCKSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPrimitiveShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBlockShape: public GfcPrimitiveShape
{
GFCENGINE_DEC_OBJECT(GfcBlockShape, gfc::engine::CEntity)
public:
    GfcBlockShape();
    GfcBlockShape(bool bSetSchema);
    void setXLength(const GfcDouble& dValue);
    GfcDouble getXLength() const;
    bool hasXLength() const;
    void setYLength(const GfcDouble& dValue);
    GfcDouble getYLength() const;
    bool hasYLength() const;
    void setZLength(const GfcDouble& dValue);
    GfcDouble getZLength() const;
    bool hasZLength() const;

};

GFCCLASSES_NAMESPACE_END

#endif
