#ifndef GFCSPHERE_H
#define GFCSPHERE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcCoordinates3d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSphere: public GfcSurface
{
GFCENGINE_DEC_OBJECT(GfcSphere, gfc::engine::CEntity)
public:
    GfcSphere();
    GfcSphere(bool bSetSchema);
    void setRadius(const GfcDouble& dValue);
    GfcDouble getRadius() const;
    bool hasRadius() const;
    void setCoords(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoords() const;
    bool hasCoords() const;
    std::shared_ptr<GfcCoordinates3d> getCoordsPtr();
    void setRangeU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    std::shared_ptr<GfcIntervald> getRangeUPtr();
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<GfcIntervald> getRangeVPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
