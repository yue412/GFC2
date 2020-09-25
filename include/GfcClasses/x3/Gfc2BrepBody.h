#ifndef GFC2BREPBODY_H
#define GFC2BREPBODY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Body.h"
#include "GfcClasses/x3/Gfc2Face.h"
#include "GfcClasses/x3/Gfc2Edge.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2BrepBody: public Gfc2Body
{
GFCENGINE_DEC_OBJECT(Gfc2BrepBody, gfc::engine::CEntity)
public:
    Gfc2BrepBody();
    Gfc2BrepBody(bool bSetSchema);
    int getFacesCount() const;
    void clearFaces();
    void addFaces(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getFaces(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Face> getFacesPtr(int nIndex);
    int getEdgesCount() const;
    void clearEdges();
    void addEdges(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEdges(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Edge> getEdgesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
