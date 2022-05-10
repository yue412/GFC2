#ifndef GFCVECTOR3D_H
#define GFCVECTOR3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcVector3d: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcVector3d, gfc::engine::CEntity)
public:
    GfcVector3d();
    GfcVector3d(bool bSetSchema);
    void setX(const GfcDouble& dValue);
    GfcDouble getX() const;
    bool hasX() const;
    void setY(const GfcDouble& dValue);
    GfcDouble getY() const;
    bool hasY() const;
    void setZ(const GfcDouble& dValue);
    GfcDouble getZ() const;
    bool hasZ() const;

};

GFCCLASSES_NAMESPACE_END

#endif
