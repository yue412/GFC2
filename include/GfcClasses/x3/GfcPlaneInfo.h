#ifndef GFCPLANEINFO_H
#define GFCPLANEINFO_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPlaneInfo: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcPlaneInfo, gfc::engine::CEntity)
public:
    GfcPlaneInfo();
    GfcPlaneInfo(bool bSetSchema);
    void setDirX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    std::shared_ptr<GfcVector3d> getDirXPtr();
    void setDirY(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirY() const;
    bool hasDirY() const;
    std::shared_ptr<GfcVector3d> getDirYPtr();
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<GfcVector3d> getPosPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
