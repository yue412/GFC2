#ifndef GFC2COEDGE_H
#define GFC2COEDGE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Topology.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Coedge: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2Coedge,gfc2::engine::EntityFactory)
public:
    Gfc2Coedge();
    Gfc2Coedge(bool bSetSchema);
    void setCurve(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCurve() const;
    bool hasCurve() const;
    std::shared_ptr<Gfc2Curve2d> getCurvePtr();
    void setEdgeIndex(const Gfc2Integer& nValue);
    Gfc2Integer getEdgeIndex() const;
    bool hasEdgeIndex() const;
    void setEdgeSameDir(const Gfc2Boolean& bValue);
    Gfc2Boolean getEdgeSameDir() const;
    bool hasEdgeSameDir() const;

};
#endif
