#ifndef GFC2LIGHTSOURCE_H
#define GFC2LIGHTSOURCE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RepresentationItem.h"
#include "Gfc2Color.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2LightSource: public Gfc2RepresentationItem
{
GFCENGINE_DEC_OBJECT(Gfc2LightSource,gfc2::engine::EntityFactory)
public:
    Gfc2LightSource();
    Gfc2LightSource(bool bSetSchema);
    void setName(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getName() const;
    bool hasName() const;
    std::shared_ptr<Gfc2Label> getNamePtr();
    void setLightColour(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getLightColour() const;
    bool hasLightColour() const;
    std::shared_ptr<Gfc2Color> getLightColourPtr();
    void setAmbientIntensity(const Gfc2Double& dValue);
    Gfc2Double getAmbientIntensity() const;
    bool hasAmbientIntensity() const;
    void setIntensity(const Gfc2Double& dValue);
    Gfc2Double getIntensity() const;
    bool hasIntensity() const;

};
#endif
