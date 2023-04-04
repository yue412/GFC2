#ifndef GFCPBRAPPEARANCEMATERIAL_H
#define GFCPBRAPPEARANCEMATERIAL_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcAppearanceMaterial.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPBRAppearanceMaterial: public GfcAppearanceMaterial
{
GFCENGINE_DEC_OBJECT(GfcPBRAppearanceMaterial, gfc::engine::CEntity)
public:
    GfcPBRAppearanceMaterial();
    GfcPBRAppearanceMaterial(bool bSetSchema);
    void setMetalness(const GfcDouble& dValue);
    GfcDouble getMetalness() const;
    bool hasMetalness() const;
    void setRoughness(const GfcDouble& dValue);
    GfcDouble getRoughness() const;
    bool hasRoughness() const;

};

GFCCLASSES_NAMESPACE_END

#endif
