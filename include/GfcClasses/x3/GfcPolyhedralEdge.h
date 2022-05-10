#ifndef GFCPOLYHEDRALEDGE_H
#define GFCPOLYHEDRALEDGE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPolyhedralEdge: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcPolyhedralEdge, gfc::engine::CEntity)
public:
    GfcPolyhedralEdge();
    GfcPolyhedralEdge(bool bSetSchema);
    void setStartVertexIndex(const GfcInteger& nValue);
    GfcInteger getStartVertexIndex() const;
    bool hasStartVertexIndex() const;
    void setEndVertexIndex(const GfcInteger& nValue);
    GfcInteger getEndVertexIndex() const;
    bool hasEndVertexIndex() const;

};

GFCCLASSES_NAMESPACE_END

#endif
