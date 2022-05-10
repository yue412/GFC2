#ifndef GFCSIMPLELOOP_H
#define GFCSIMPLELOOP_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/GfcSimpleVertex.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSimpleLoop: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcSimpleLoop, gfc::engine::CEntity)
public:
    GfcSimpleLoop();
    GfcSimpleLoop(bool bSetSchema);
    int getVertexesCount() const;
    void clearVertexes();
    void addVertexes(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVertexes(int nIndex) const;
    std::shared_ptr<GfcSimpleVertex> getVertexesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
