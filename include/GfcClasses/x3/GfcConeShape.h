#ifndef GFCCONESHAPE_H
#define GFCCONESHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPrimitiveShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcConeShape: public GfcPrimitiveShape
{
GFCENGINE_DEC_OBJECT(GfcConeShape, gfc::engine::CEntity)
public:
    GfcConeShape();
    GfcConeShape(bool bSetSchema);
    void setHeight(const GfcDouble& dValue);
    GfcDouble getHeight() const;
    bool hasHeight() const;
    void setBottomRadius(const GfcDouble& dValue);
    GfcDouble getBottomRadius() const;
    bool hasBottomRadius() const;

};

GFCCLASSES_NAMESPACE_END

#endif
