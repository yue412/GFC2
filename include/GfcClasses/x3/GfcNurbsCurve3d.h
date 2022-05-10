#ifndef GFCNURBSCURVE3D_H
#define GFCNURBSCURVE3D_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/GfcNurbsCtrlPt3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcNurbsCurve3d: public GfcCurve3d
{
GFCENGINE_DEC_OBJECT(GfcNurbsCurve3d, gfc::engine::CEntity)
public:
    GfcNurbsCurve3d();
    GfcNurbsCurve3d(bool bSetSchema);
    void setDegree(const GfcInteger& nValue);
    GfcInteger getDegree() const;
    bool hasDegree() const;
    int getCtrlPtsCount() const;
    void clearCtrlPts();
    void addCtrlPts(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex) const;
    std::shared_ptr<GfcNurbsCtrlPt3d> getCtrlPtsPtr(int nIndex);
    int getKnotsCount() const;
    void clearKnots();
    void addKnots(const GfcDouble& dValue);
    GfcDouble getKnots(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
