#ifndef GFCPLANE_H
#define GFCPLANE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcClasses/x3/GfcIntervald.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPlane: public GfcSurface
{
GFCENGINE_DEC_OBJECT(GfcPlane, gfc::engine::CEntity)
public:
    GfcPlane();
    GfcPlane(bool bSetSchema);
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<GfcVector3d> getPosPtr();
    void setDirU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirU() const;
    bool hasDirU() const;
    std::shared_ptr<GfcVector3d> getDirUPtr();
    void setDirV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirV() const;
    bool hasDirV() const;
    std::shared_ptr<GfcVector3d> getDirVPtr();
    void setRangeU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    std::shared_ptr<GfcIntervald> getRangeUPtr();
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<GfcIntervald> getRangeVPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
