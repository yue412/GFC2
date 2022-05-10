#ifndef GFCEDGE_H
#define GFCEDGE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/GfcCurve3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcEdge: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcEdge, gfc::engine::CEntity)
public:
    GfcEdge();
    GfcEdge(bool bSetSchema);
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<GfcCurve3d> getCurvePtr();
    void setFaceIndex1(const GfcInteger& nValue);
    GfcInteger getFaceIndex1() const;
    bool hasFaceIndex1() const;
    void setFaceIndex2(const GfcInteger& nValue);
    GfcInteger getFaceIndex2() const;
    bool hasFaceIndex2() const;
    void setLoopIndex1(const GfcInteger& nValue);
    GfcInteger getLoopIndex1() const;
    bool hasLoopIndex1() const;
    void setLoopIndex2(const GfcInteger& nValue);
    GfcInteger getLoopIndex2() const;
    bool hasLoopIndex2() const;
    void setCoedgeIndex1(const GfcInteger& nValue);
    GfcInteger getCoedgeIndex1() const;
    bool hasCoedgeIndex1() const;
    void setCoedgeIndex2(const GfcInteger& nValue);
    GfcInteger getCoedgeIndex2() const;
    bool hasCoedgeIndex2() const;

};

GFCCLASSES_NAMESPACE_END

#endif
