#ifndef NGFCCONNECTIONCURVEGEOMETRY_H
#define NGFCCONNECTIONCURVEGEOMETRY_H

#include "NGfcConnectionGeometry.h"
#include "GfcClasses\x3\GfcConnectionCurveGeometry.h"
#include "NGfcCurve3d.h"

public ref class NGfcConnectionCurveGeometry: public NGfcConnectionGeometry
{
public:
    NGfcConnectionCurveGeometry();
    NGfcConnectionCurveGeometry(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCurveOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurveOnRelatingElement();
    bool hasCurveOnRelatingElement();
    void setCurveOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurveOnRelatedElement();
    bool hasCurveOnRelatedElement();

};
#endif
