#ifndef GFC2SPHERE_H
#define GFC2SPHERE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Surface.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Intervald.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Sphere: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Sphere,gfc2::engine::EntityFactory)
public:
    Gfc2Sphere();
    Gfc2Sphere(bool bSetSchema);
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;
    void setCoords(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCoords() const;
    bool hasCoords() const;
    std::shared_ptr<Gfc2Coordinates3d> getCoordsPtr();
    void setRangeU(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    std::shared_ptr<Gfc2Intervald> getRangeUPtr();
    void setRangeV(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<Gfc2Intervald> getRangeVPtr();

};
#endif
