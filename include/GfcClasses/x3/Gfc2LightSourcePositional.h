#ifndef GFC2LIGHTSOURCEPOSITIONAL_H
#define GFC2LIGHTSOURCEPOSITIONAL_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2LightSource.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2LightSourcePositional: public Gfc2LightSource
{
GFCENGINE_DEC_OBJECT(Gfc2LightSourcePositional, gfc::engine::CEntity)
public:
    Gfc2LightSourcePositional();
    Gfc2LightSourcePositional(bool bSetSchema);
    void setPosition(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPosition() const;
    bool hasPosition() const;
    std::shared_ptr<Gfc2Vector3d> getPositionPtr();
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;
    void setConstantAttenuation(const Gfc2Double& dValue);
    Gfc2Double getConstantAttenuation() const;
    bool hasConstantAttenuation() const;
    void setDistanceAttenuation(const Gfc2Double& dValue);
    Gfc2Double getDistanceAttenuation() const;
    bool hasDistanceAttenuation() const;
    void setQuadricAttenuation(const Gfc2Double& dValue);
    Gfc2Double getQuadricAttenuation() const;
    bool hasQuadricAttenuation() const;

};

GFCCLASSES_NAMESPACE_END

#endif
