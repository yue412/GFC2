#ifndef GFCBEVEL_H
#define GFCBEVEL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcCoordinates3d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBevel: public GfcSurface
{
GFCENGINE_DEC_OBJECT(GfcBevel, gfc::engine::CEntity)
public:
    GfcBevel();
    GfcBevel(bool bSetSchema);
    void setCoord(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoord() const;
    bool hasCoord() const;
    std::shared_ptr<GfcCoordinates3d> getCoordPtr();
    void setHeight(const GfcDouble& dValue);
    GfcDouble getHeight() const;
    bool hasHeight() const;
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<GfcIntervald> getRangeVPtr();
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<GfcCurve2d> getCurvePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
