#ifndef GFC2PLANEINFO_H
#define GFC2PLANEINFO_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2PlaneInfo: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2PlaneInfo, gfc::engine::CEntity)
public:
    Gfc2PlaneInfo();
    Gfc2PlaneInfo(bool bSetSchema);
    void setDirX(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getDirXPtr();
    void setDirY(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirY() const;
    bool hasDirY() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getDirYPtr();
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getPosPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
