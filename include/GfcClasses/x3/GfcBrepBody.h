#ifndef GFCBREPBODY_H
#define GFCBREPBODY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcBody.h"
#include "GfcClasses/x3/GfcFace.h"
#include "GfcClasses/x3/GfcEdge.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBrepBody: public GfcBody
{
GFCENGINE_DEC_OBJECT(GfcBrepBody, gfc::engine::CEntity)
public:
    GfcBrepBody();
    GfcBrepBody(bool bSetSchema);
    int getFacesCount() const;
    void clearFaces();
    void addFaces(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getFaces(int nIndex) const;
    std::shared_ptr<GfcFace> getFacesPtr(int nIndex);
    int getEdgesCount() const;
    void clearEdges();
    void addEdges(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEdges(int nIndex) const;
    std::shared_ptr<GfcEdge> getEdgesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
