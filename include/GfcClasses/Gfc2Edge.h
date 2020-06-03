#ifndef GFC2EDGE_H
#define GFC2EDGE_H

#include "GfcClasses.h"
#include "Gfc2Topology.h"
#include "Gfc2Curve3d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Edge: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2Edge, gfc::engine::Entity)
public:
    Gfc2Edge();
    Gfc2Edge(bool bSetSchema);
    void setCurve(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<Gfc2Curve3d> getCurvePtr();
    void setFaceIndex1(const Gfc2Integer& nValue);
    Gfc2Integer getFaceIndex1() const;
    bool hasFaceIndex1() const;
    void setFaceIndex2(const Gfc2Integer& nValue);
    Gfc2Integer getFaceIndex2() const;
    bool hasFaceIndex2() const;
    void setLoopIndex1(const Gfc2Integer& nValue);
    Gfc2Integer getLoopIndex1() const;
    bool hasLoopIndex1() const;
    void setLoopIndex2(const Gfc2Integer& nValue);
    Gfc2Integer getLoopIndex2() const;
    bool hasLoopIndex2() const;
    void setCoedgeIndex1(const Gfc2Integer& nValue);
    Gfc2Integer getCoedgeIndex1() const;
    bool hasCoedgeIndex1() const;
    void setCoedgeIndex2(const Gfc2Integer& nValue);
    Gfc2Integer getCoedgeIndex2() const;
    bool hasCoedgeIndex2() const;

};
#endif
