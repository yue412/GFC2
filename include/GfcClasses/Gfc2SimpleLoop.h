#ifndef GFC2SIMPLELOOP_H
#define GFC2SIMPLELOOP_H

#include "GfcClasses.h"
#include "Gfc2Topology.h"
#include "Gfc2SimpleVertex.h"
#include "GfcEngine/Entity.h"

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
    gfc::engine::CEntityWrapPtr<Gfc2SimpleVertex> getVertexesPtr(int nIndex);

};
#endif
