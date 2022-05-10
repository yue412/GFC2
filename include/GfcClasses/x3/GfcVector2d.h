#ifndef GFCVECTOR2D_H
#define GFCVECTOR2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcVector2d: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcVector2d, gfc::engine::CEntity)
public:
    GfcVector2d();
    GfcVector2d(bool bSetSchema);
    void setX(const GfcDouble& dValue);
    GfcDouble getX() const;
    bool hasX() const;
    void setY(const GfcDouble& dValue);
    GfcDouble getY() const;
    bool hasY() const;

};

GFCCLASSES_NAMESPACE_END

#endif
