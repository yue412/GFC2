#ifndef GFCPOLYHEDRONBODY_H
#define GFCPOLYHEDRONBODY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcBody.h"
#include "GfcClasses/x3/GfcPolyhedralFace.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPolyhedronBody: public GfcBody
{
GFCENGINE_DEC_OBJECT(GfcPolyhedronBody, gfc::engine::CEntity)
public:
    GfcPolyhedronBody();
    GfcPolyhedronBody(bool bSetSchema);
    int getFacesCount() const;
    void clearFaces();
    void addFaces(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getFaces(int nIndex) const;
    std::shared_ptr<GfcPolyhedralFace> getFacesPtr(int nIndex);
    int getVertexesCount() const;
    void clearVertexes();
    void addVertexes(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVertexes(int nIndex) const;
    std::shared_ptr<GfcVector3d> getVertexesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
