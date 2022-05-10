#ifndef GFCCOEDGE_H
#define GFCCOEDGE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/GfcCurve2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCoedge: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcCoedge, gfc::engine::CEntity)
public:
    GfcCoedge();
    GfcCoedge(bool bSetSchema);
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<GfcCurve2d> getCurvePtr();
    void setEdgeIndex(const GfcInteger& nValue);
    GfcInteger getEdgeIndex() const;
    bool hasEdgeIndex() const;
    void setEdgeSameDir(const GfcBoolean& bValue);
    GfcBoolean getEdgeSameDir() const;
    bool hasEdgeSameDir() const;

};

GFCCLASSES_NAMESPACE_END

#endif
