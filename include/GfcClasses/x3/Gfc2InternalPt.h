#ifndef GFC2INTERNALPT_H
#define GFC2INTERNALPT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcClasses/x3/Gfc2Vector2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2InternalPt: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2InternalPt, gfc::engine::CEntity)
public:
    Gfc2InternalPt();
    Gfc2InternalPt(bool bSetSchema);
    void setP(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getP() const;
    bool hasP() const;
    std::shared_ptr<Gfc2Vector3d> getPPtr();
    void setTVec(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTVec() const;
    bool hasTVec() const;
    std::shared_ptr<Gfc2Vector3d> getTVecPtr();
    void setT(const Gfc2Double& dValue);
    Gfc2Double getT() const;
    bool hasT() const;
    void setUV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUV() const;
    bool hasUV() const;
    std::shared_ptr<Gfc2Vector2d> getUVPtr();
    void setST(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getST() const;
    bool hasST() const;
    std::shared_ptr<Gfc2Vector2d> getSTPtr();
    void setUVDir(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUVDir() const;
    bool hasUVDir() const;
    std::shared_ptr<Gfc2Vector2d> getUVDirPtr();
    void setSTDir(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSTDir() const;
    bool hasSTDir() const;
    std::shared_ptr<Gfc2Vector2d> getSTDirPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
