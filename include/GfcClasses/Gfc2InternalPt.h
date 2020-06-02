#ifndef GFC2INTERNALPT_H
#define GFC2INTERNALPT_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2InternalPt: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2InternalPt,gfc2::engine::EntityFactory)
public:
    Gfc2InternalPt();
    Gfc2InternalPt(bool bSetSchema);
    void setP(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getP() const;
    bool hasP() const;
    std::shared_ptr<Gfc2Vector3d> getPPtr();
    void setTVec(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getTVec() const;
    bool hasTVec() const;
    std::shared_ptr<Gfc2Vector3d> getTVecPtr();
    void setT(const Gfc2Double& dValue);
    Gfc2Double getT() const;
    bool hasT() const;
    void setUV(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getUV() const;
    bool hasUV() const;
    std::shared_ptr<Gfc2Vector2d> getUVPtr();
    void setST(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getST() const;
    bool hasST() const;
    std::shared_ptr<Gfc2Vector2d> getSTPtr();
    void setUVDir(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getUVDir() const;
    bool hasUVDir() const;
    std::shared_ptr<Gfc2Vector2d> getUVDirPtr();
    void setSTDir(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getSTDir() const;
    bool hasSTDir() const;
    std::shared_ptr<Gfc2Vector2d> getSTDirPtr();

};
#endif
