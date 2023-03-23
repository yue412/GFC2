#ifndef GFCMATERIAL_H
#define GFCMATERIAL_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/GfcColor.h"
#include "GfcClasses/x3/GfcSurfaceTexture.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcMaterial: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcMaterial, gfc::engine::CEntity)
public:
    GfcMaterial();
    GfcMaterial(bool bSetSchema);
    void setColor(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getColor() const;
    bool hasColor() const;
    std::shared_ptr<GfcColor> getColorPtr();
    void setDoubleSide(const GfcBoolean& bValue);
    GfcBoolean getDoubleSide() const;
    bool hasDoubleSide() const;
    void setOpacity(const GfcDouble& dValue);
    GfcDouble getOpacity() const;
    bool hasOpacity() const;
    int getTexturesCount() const;
    void clearTextures();
    void addTextures(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTextures(int nIndex) const;
    std::shared_ptr<GfcSurfaceTexture> getTexturesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
