#ifndef GFCFACE_H
#define GFCFACE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcCommonPolygonEx.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcBox3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcFace: public GfcCommonPolygonEx
{
GFCENGINE_DEC_OBJECT(GfcFace, gfc::engine::CEntity)
public:
    GfcFace();
    GfcFace(bool bSetSchema);
    void setSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSurface() const;
    bool hasSurface() const;
    std::shared_ptr<GfcSurface> getSurfacePtr();
    void setBox(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBox() const;
    bool hasBox() const;
    std::shared_ptr<GfcBox3d> getBoxPtr();
    void setSameDir(const GfcBoolean& bValue);
    GfcBoolean getSameDir() const;
    bool hasSameDir() const;
    void setIndex(const GfcInteger& nValue);
    GfcInteger getIndex() const;
    bool hasIndex() const;

};

GFCCLASSES_NAMESPACE_END

#endif
