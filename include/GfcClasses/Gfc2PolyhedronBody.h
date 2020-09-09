#ifndef GFC2POLYHEDRONBODY_H
#define GFC2POLYHEDRONBODY_H

#include "GfcClasses.h"
#include "Gfc2Body.h"
#include "Gfc2PolyhedralFace.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2PolyhedronBody: public Gfc2Body
{
GFCENGINE_DEC_OBJECT(Gfc2PolyhedronBody, gfc::engine::CEntity)
public:
    Gfc2PolyhedronBody();
    Gfc2PolyhedronBody(bool bSetSchema);
    int getFacesCount() const;
    void clearFaces();
    void addFaces(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getFaces(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2PolyhedralFace> getFacesPtr(int nIndex);
    int getVertexesCount() const;
    void clearVertexes();
    void addVertexes(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVertexes(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getVertexesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
