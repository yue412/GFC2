#ifndef GFC2NURBSCURVE2D_H
#define GFC2NURBSCURVE2D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Curve2d.h"
#include "GfcClasses/x3/Gfc2NurbsCtrlPt2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2NurbsCurve2d: public Gfc2Curve2d
{
GFCENGINE_DEC_OBJECT(Gfc2NurbsCurve2d, gfc::engine::CEntity)
public:
    Gfc2NurbsCurve2d();
    Gfc2NurbsCurve2d(bool bSetSchema);
    void setDegree(const Gfc2Integer& nValue);
    Gfc2Integer getDegree() const;
    bool hasDegree() const;
    int getCtrlPtsCount() const;
    void clearCtrlPts();
    void addCtrlPts(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex) const;
    std::shared_ptr<Gfc2NurbsCtrlPt2d> getCtrlPtsPtr(int nIndex);
    int getKnotsCount() const;
    void clearKnots();
    void addKnots(const Gfc2Double& dValue);
    Gfc2Double getKnots(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
