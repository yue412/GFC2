#ifndef GFC2SIMPLELOOP_H
#define GFC2SIMPLELOOP_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Topology.h"
#include "GfcClasses/x3/Gfc2SimpleVertex.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SimpleLoop: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2SimpleLoop, gfc::engine::CEntity)
public:
    Gfc2SimpleLoop();
    Gfc2SimpleLoop(bool bSetSchema);
    int getVertexesCount() const;
    void clearVertexes();
    void addVertexes(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVertexes(int nIndex) const;
    std::shared_ptr<Gfc2SimpleVertex> getVertexesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
