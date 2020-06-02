#ifndef GFC2SIMPLELOOP_H
#define GFC2SIMPLELOOP_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Topology.h"
#include "Gfc2SimpleVertex.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SimpleLoop: public Gfc2Topology
{
GFCENGINE_DEC_OBJECT(Gfc2SimpleLoop,gfc2::engine::EntityFactory)
public:
    Gfc2SimpleLoop();
    Gfc2SimpleLoop(bool bSetSchema);
    int getVertexesCount() const;
    void clearVertexes();
    void addVertexes(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getVertexes(int nIndex) const;
    std::shared_ptr<Gfc2SimpleVertex> getVertexesPtr(int nIndex);

};
#endif
