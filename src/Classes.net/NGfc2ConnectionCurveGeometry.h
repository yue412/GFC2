#ifndef NGFC2CONNECTIONCURVEGEOMETRY_H
#define NGFC2CONNECTIONCURVEGEOMETRY_H

#include "NGfc2ConnectionGeometry.h"
#include "Gfc2ConnectionCurveGeometry.h"
#include "NGfc2Curve3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ConnectionCurveGeometry: public NGfc2ConnectionGeometry
{
public:
    NGfc2ConnectionCurveGeometry();
    NGfc2ConnectionCurveGeometry(void* pEntity, bool bOwner);
    void setCurveOnRelatingElement(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCurveOnRelatingElement();
    bool hasCurveOnRelatingElement();
    NGfc2Curve3d^ getCurveOnRelatingElementPtr();
    void setCurveOnRelatedElement(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCurveOnRelatedElement();
    bool hasCurveOnRelatedElement();
    NGfc2Curve3d^ getCurveOnRelatedElementPtr();

};
#endif
