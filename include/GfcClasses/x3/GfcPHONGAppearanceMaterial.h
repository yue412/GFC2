#ifndef GFCPHONGAPPEARANCEMATERIAL_H
#define GFCPHONGAPPEARANCEMATERIAL_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcAppearanceMaterial.h"
#include "GfcClasses/x3/GfcColor.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPHONGAppearanceMaterial: public GfcAppearanceMaterial
{
GFCENGINE_DEC_OBJECT(GfcPHONGAppearanceMaterial, gfc::engine::CEntity)
public:
    GfcPHONGAppearanceMaterial();
    GfcPHONGAppearanceMaterial(bool bSetSchema);
    void setAmbient(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getAmbient() const;
    bool hasAmbient() const;
    std::shared_ptr<GfcColor> getAmbientPtr();
    void setEmissive(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEmissive() const;
    bool hasEmissive() const;
    std::shared_ptr<GfcColor> getEmissivePtr();
    void setSpecular(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSpecular() const;
    bool hasSpecular() const;
    std::shared_ptr<GfcColor> getSpecularPtr();
    void setEnvironment(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEnvironment() const;
    bool hasEnvironment() const;
    std::shared_ptr<GfcColor> getEnvironmentPtr();
    void setShiniess(const GfcDouble& dValue);
    GfcDouble getShiniess() const;
    bool hasShiniess() const;

};

GFCCLASSES_NAMESPACE_END

#endif
