#ifndef GFCNURBSCURVE2D_H
#define GFCNURBSCURVE2D_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/GfcNurbsCtrlPt2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcNurbsCurve2d: public GfcCurve2d
{
GFCENGINE_DEC_OBJECT(GfcNurbsCurve2d, gfc::engine::CEntity)
public:
    GfcNurbsCurve2d();
    GfcNurbsCurve2d(bool bSetSchema);
    void setDegree(const GfcInteger& nValue);
    GfcInteger getDegree() const;
    bool hasDegree() const;
    int getCtrlPtsCount() const;
    void clearCtrlPts();
    void addCtrlPts(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCtrlPts(int nIndex) const;
    std::shared_ptr<GfcNurbsCtrlPt2d> getCtrlPtsPtr(int nIndex);
    int getKnotsCount() const;
    void clearKnots();
    void addKnots(const GfcDouble& dValue);
    GfcDouble getKnots(int nIndex) const;

};

GFCCLASSES_NAMESPACE_END

#endif
