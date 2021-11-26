#ifndef NGFC2CONNECTIONCURVEGEOMETRY_H
#define NGFC2CONNECTIONCURVEGEOMETRY_H

#include "NGfc2ConnectionGeometry.h"
#include "GfcClasses\x3\Gfc2ConnectionCurveGeometry.h"
#include "NGfc2Curve3d.h"

public ref class NGfc2ConnectionCurveGeometry: public NGfc2ConnectionGeometry
{
public:
    NGfc2ConnectionCurveGeometry();
    NGfc2ConnectionCurveGeometry(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCurveOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurveOnRelatingElement();
    bool hasCurveOnRelatingElement();
    void setCurveOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurveOnRelatedElement();
    bool hasCurveOnRelatedElement();

};
#endif
