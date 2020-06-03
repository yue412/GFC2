#ifndef GFC2BREPBODY_H
#define GFC2BREPBODY_H

#include "GfcClasses.h"
#include "Gfc2Body.h"
#include "Gfc2Face.h"
#include "Gfc2Edge.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BrepBody: public Gfc2Body
{
GFCENGINE_DEC_OBJECT(Gfc2BrepBody, gfc::engine::Entity)
public:
    Gfc2BrepBody();
    Gfc2BrepBody(bool bSetSchema);
    int getFacesCount() const;
    void clearFaces();
    void addFaces(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getFaces(int nIndex) const;
    std::shared_ptr<Gfc2Face> getFacesPtr(int nIndex);
    int getEdgesCount() const;
    void clearEdges();
    void addEdges(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEdges(int nIndex) const;
    std::shared_ptr<Gfc2Edge> getEdgesPtr(int nIndex);

};
#endif
