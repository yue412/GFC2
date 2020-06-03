#ifndef GFC2PLANE_H
#define GFC2PLANE_H

#include "GfcClasses.h"
#include "Gfc2Surface.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Intervald.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Plane: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Plane, gfc::engine::Entity)
public:
    Gfc2Plane();
    Gfc2Plane(bool bSetSchema);
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    std::shared_ptr<Gfc2Vector3d> getPosPtr();
    void setDirU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirU() const;
    bool hasDirU() const;
    std::shared_ptr<Gfc2Vector3d> getDirUPtr();
    void setDirV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirV() const;
    bool hasDirV() const;
    std::shared_ptr<Gfc2Vector3d> getDirVPtr();
    void setRangeU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    std::shared_ptr<Gfc2Intervald> getRangeUPtr();
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    std::shared_ptr<Gfc2Intervald> getRangeVPtr();

};
#endif
