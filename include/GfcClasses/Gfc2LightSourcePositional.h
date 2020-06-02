#ifndef GFC2LIGHTSOURCEPOSITIONAL_H
#define GFC2LIGHTSOURCEPOSITIONAL_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2LightSource.h"
#include "Gfc2Vector3d.h"
#include "TypeDef.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2LightSourcePositional: public Gfc2LightSource
{
GFCENGINE_DEC_OBJECT(Gfc2LightSourcePositional,gfc2::engine::EntityFactory)
public:
    Gfc2LightSourcePositional();
    Gfc2LightSourcePositional(bool bSetSchema);
    void setPosition(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPosition() const;
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
#endif
