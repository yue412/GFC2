#ifndef GFC2PLANE_H
#define GFC2PLANE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Surface.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcClasses/x3/Gfc2Intervald.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Plane: public Gfc2Surface
{
GFCENGINE_DEC_OBJECT(Gfc2Plane, gfc::engine::CEntity)
public:
    Gfc2Plane();
    Gfc2Plane(bool bSetSchema);
    void setPos(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPos() const;
    bool hasPos() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getPosPtr();
    void setDirU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirU() const;
    bool hasDirU() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getDirUPtr();
    void setDirV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDirV() const;
    bool hasDirV() const;
    gfc::engine::CEntityWrapPtr<Gfc2Vector3d> getDirVPtr();
    void setRangeU(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeU() const;
    bool hasRangeU() const;
    gfc::engine::CEntityWrapPtr<Gfc2Intervald> getRangeUPtr();
    void setRangeV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRangeV() const;
    bool hasRangeV() const;
    gfc::engine::CEntityWrapPtr<Gfc2Intervald> getRangeVPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
