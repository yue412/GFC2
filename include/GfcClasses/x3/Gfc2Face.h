#ifndef GFC2FACE_H
#define GFC2FACE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2CommonPolygonEx.h"
#include "GfcClasses/x3/Gfc2Surface.h"
#include "GfcClasses/x3/Gfc2Box3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Face: public Gfc2CommonPolygonEx
{
GFCENGINE_DEC_OBJECT(Gfc2Face, gfc::engine::CEntity)
public:
    Gfc2Face();
    Gfc2Face(bool bSetSchema);
    void setSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurface() const;
    bool hasSurface() const;
    gfc::engine::CEntityWrapPtr<Gfc2Surface> getSurfacePtr();
    void setBox(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBox() const;
    bool hasBox() const;
    gfc::engine::CEntityWrapPtr<Gfc2Box3d> getBoxPtr();
    void setSameDir(const Gfc2Boolean& bValue);
    Gfc2Boolean getSameDir() const;
    bool hasSameDir() const;
    void setIndex(const Gfc2Integer& nValue);
    Gfc2Integer getIndex() const;
    bool hasIndex() const;

};

GFCCLASSES_NAMESPACE_END

#endif
