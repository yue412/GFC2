#ifndef GFCLIGHTSOURCEPOSITIONAL_H
#define GFCLIGHTSOURCEPOSITIONAL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcLightSource.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcLightSourcePositional: public GfcLightSource
{
GFCENGINE_DEC_OBJECT(GfcLightSourcePositional, gfc::engine::CEntity)
public:
    GfcLightSourcePositional();
    GfcLightSourcePositional(bool bSetSchema);
    void setPosition(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPosition() const;
    bool hasPosition() const;
    std::shared_ptr<GfcVector3d> getPositionPtr();
    void setRadius(const GfcDouble& dValue);
    GfcDouble getRadius() const;
    bool hasRadius() const;
    void setConstantAttenuation(const GfcDouble& dValue);
    GfcDouble getConstantAttenuation() const;
    bool hasConstantAttenuation() const;
    void setDistanceAttenuation(const GfcDouble& dValue);
    GfcDouble getDistanceAttenuation() const;
    bool hasDistanceAttenuation() const;
    void setQuadricAttenuation(const GfcDouble& dValue);
    GfcDouble getQuadricAttenuation() const;
    bool hasQuadricAttenuation() const;

};

GFCCLASSES_NAMESPACE_END

#endif
