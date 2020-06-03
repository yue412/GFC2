#ifndef GFC2FACE_H
#define GFC2FACE_H

#include "GfcClasses.h"
#include "Gfc2CommonPolygonEx.h"
#include "Gfc2Surface.h"
#include "Gfc2Box3d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Face: public Gfc2CommonPolygonEx
{
GFCENGINE_DEC_OBJECT(Gfc2Face, gfc::engine::Entity)
public:
    Gfc2Face();
    Gfc2Face(bool bSetSchema);
    void setSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurface() const;
    bool hasSurface() const;
    std::shared_ptr<Gfc2Surface> getSurfacePtr();
    void setBox(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBox() const;
    bool hasBox() const;
    std::shared_ptr<Gfc2Box3d> getBoxPtr();
    void setSameDir(const Gfc2Boolean& bValue);
    Gfc2Boolean getSameDir() const;
    bool hasSameDir() const;
    void setIndex(const Gfc2Integer& nValue);
    Gfc2Integer getIndex() const;
    bool hasIndex() const;

};
#endif
