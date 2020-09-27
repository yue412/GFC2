#ifndef GFC2NURBSCURVE3D_H
#define GFC2NURBSCURVE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve3d.h"
#include "GfcClasses/x3/Gfc2NurbsCtrlPt3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2NurbsCurve3d: public Gfc2Curve3d
{
GFCENGINE_DEC_OBJECT(Gfc2NurbsCurve3d, gfc::engine::CEntity)
public:
    Gfc2NurbsCurve3d();
    Gfc2NurbsCurve3d(bool bSetSchema);
    void setDegree(const Gfc2Integer& nValue);
    Gfc2Integer getDegree() const;
    bool hasDegree() const;
    int getCtrlPtsCount() const;
    void clearCtrlPts();
    void addCtrlPts(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2NurbsCtrlPt3d> getCtrlPtsPtr(int nIndex);
    int getKnotsCount() const;
    void clearKnots();
    void addKnots(const Gfc2Double& dValue);
    Gfc2Double getKnots(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
