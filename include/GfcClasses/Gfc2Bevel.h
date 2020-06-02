#ifndef GFC2BEVEL_H
#define GFC2BEVEL_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Surface.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Bevel: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Bevel,gfc2::engine::EntityFactory)
public:
    Gfc2Bevel();
    Gfc2Bevel(bool bSetSchema);
    void setCoord(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCoord() const;
    bool hasCoord() const;
    std::shared_ptr<Gfc2Coordinates3d> getCoordPtr();
    void setHeight(const Gfc2Double& dValue);
    Gfc2Double getHeight() const;
    bool hasHeight() const;
    void setRangeV(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<Gfc2Intervald> getRangeVPtr();
    void setCurve(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<Gfc2Curve2d> getCurvePtr();

};
#endif
