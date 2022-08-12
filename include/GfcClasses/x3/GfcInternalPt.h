#ifndef GFCINTERNALPT_H
#define GFCINTERNALPT_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcInternalPt: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcInternalPt, gfc::engine::CEntity)
public:
    GfcInternalPt();
    GfcInternalPt(bool bSetSchema);
    void setP(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getP() const;
    bool hasP() const;
    std::shared_ptr<GfcVector3d> getPPtr();
    void setTVec(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTVec() const;
    bool hasTVec() const;
    std::shared_ptr<GfcVector3d> getTVecPtr();
    void setT(const GfcDouble& dValue);
    GfcDouble getT() const;
    bool hasT() const;
    void setUV(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUV() const;
    bool hasUV() const;
    std::shared_ptr<GfcVector2d> getUVPtr();
    void setST(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getST() const;
    bool hasST() const;
    std::shared_ptr<GfcVector2d> getSTPtr();
    void setUVDir(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getUVDir() const;
    bool hasUVDir() const;
    std::shared_ptr<GfcVector2d> getUVDirPtr();
    void setSTDir(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSTDir() const;
    bool hasSTDir() const;
    std::shared_ptr<GfcVector2d> getSTDirPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
