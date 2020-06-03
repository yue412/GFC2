#ifndef GFC2PLANEINFO_H
#define GFC2PLANEINFO_H

#include "GfcClasses.h"
#include "Gfc2Vector3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2PlaneInfo: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2PlaneInfo, gfc2::engine::Entity)
public:
    Gfc2PlaneInfo();
    Gfc2PlaneInfo(bool bSetSchema);
    void setDirX(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDirX() const;
    bool hasDirX() const;
    std::shared_ptr<Gfc2Vector3d> getDirXPtr();
    void setDirY(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getDirY() const;
    bool hasDirY() const;
    std::shared_ptr<Gfc2Vector3d> getDirYPtr();
    void setPos(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<Gfc2Vector3d> getPosPtr();

};
#endif
