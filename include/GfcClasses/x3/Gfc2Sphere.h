#ifndef GFC2SPHERE_H
#define GFC2SPHERE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Surface.h"
#include "GfcClasses/x3/Gfc2Coordinates3d.h"
#include "GfcClasses/x3/Gfc2Intervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Sphere: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Sphere, gfc::engine::CEntity)
public:
    Gfc2Sphere();
    Gfc2Sphere(bool bSetSchema);
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;
    void setCoords(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoords() const;
    bool hasCoords() const;
    std::shared_ptr<Gfc2Coordinates3d> getCoordsPtr();
    void setRangeU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    std::shared_ptr<Gfc2Intervald> getRangeUPtr();
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<Gfc2Intervald> getRangeVPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
