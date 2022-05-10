#ifndef GFCLIGHTSOURCE_H
#define GFCLIGHTSOURCE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcRepresentationItem.h"
#include "GfcClasses/x3/GfcColor.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcLightSource: public GfcRepresentationItem
{
GFCENGINE_DEC_OBJECT(GfcLightSource, gfc::engine::CEntity)
public:
    GfcLightSource();
    GfcLightSource(bool bSetSchema);
    void setName(const GfcLabel& sValue);
    GfcLabel getName() const;
    bool hasName() const;
    void setLightColour(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLightColour() const;
    bool hasLightColour() const;
    std::shared_ptr<GfcColor> getLightColourPtr();
    void setAmbientIntensity(const GfcDouble& dValue);
    GfcDouble getAmbientIntensity() const;
    bool hasAmbientIntensity() const;
    void setIntensity(const GfcDouble& dValue);
    GfcDouble getIntensity() const;
    bool hasIntensity() const;

};

GFCCLASSES_NAMESPACE_END

#endif
