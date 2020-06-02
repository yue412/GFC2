#ifndef GFC2BREPBODY_H
#define GFC2BREPBODY_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Body.h"
#include "Gfc2Face.h"
#include "Gfc2Edge.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BrepBody: public Gfc2Body
{
GFCENGINE_DEC_OBJECT(Gfc2BrepBody,gfc2::engine::EntityFactory)
public:
    Gfc2BrepBody();
    Gfc2BrepBody(bool bSetSchema);
    int getFacesCount() const;
    void clearFaces();
    void addFaces(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getFaces(int nIndex) const;
    std::shared_ptr<Gfc2Face> getFacesPtr(int nIndex);
    int getEdgesCount() const;
    void clearEdges();
    void addEdges(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getEdges(int nIndex) const;
    std::shared_ptr<Gfc2Edge> getEdgesPtr(int nIndex);

};
#endif
