#ifndef GFCPBRMATERIAL_H
#define GFCPBRMATERIAL_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcMaterial.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPBRMaterial: public GfcMaterial
{
GFCENGINE_DEC_OBJECT(GfcPBRMaterial, gfc::engine::CEntity)
public:
    GfcPBRMaterial();
    GfcPBRMaterial(bool bSetSchema);
    void setMetalness(const GfcDouble& dValue);
    GfcDouble getMetalness() const;
    bool hasMetalness() const;
    void setRoughness(const GfcDouble& dValue);
    GfcDouble getRoughness() const;
    bool hasRoughness() const;

};

GFCCLASSES_NAMESPACE_END

#endif
