#ifndef GFC2LIGHTSOURCE_H
#define GFC2LIGHTSOURCE_H

#include "GfcClasses.h"
#include "Gfc2RepresentationItem.h"
#include "Gfc2Color.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2LightSource: public Gfc2RepresentationItem
{
GFCENGINE_DEC_OBJECT(Gfc2LightSource, gfc::engine::CEntity)
public:
    Gfc2LightSource();
    Gfc2LightSource(bool bSetSchema);
    void setName(const Gfc2Label& sValue);
    Gfc2Label getName() const;
    bool hasName() const;
    void setLightColour(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLightColour() const;
    bool hasLightColour() const;
    gfc::engine::CEntityWrapPtr<Gfc2Color> getLightColourPtr();
    void setAmbientIntensity(const Gfc2Double& dValue);
    Gfc2Double getAmbientIntensity() const;
    bool hasAmbientIntensity() const;
    void setIntensity(const Gfc2Double& dValue);
    Gfc2Double getIntensity() const;
    bool hasIntensity() const;

};

GFCCLASSES_NAMESPACE_END

#endif
