#ifndef GFCCONNECTIONVOLUMEGEOMETRY_H
#define GFCCONNECTIONVOLUMEGEOMETRY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcConnectionGeometry.h"
#include "GfcClasses/x3/GfcBody.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcConnectionVolumeGeometry: public GfcConnectionGeometry
{
GFCENGINE_DEC_OBJECT(GfcConnectionVolumeGeometry, gfc::engine::CEntity)
public:
    GfcConnectionVolumeGeometry();
    GfcConnectionVolumeGeometry(bool bSetSchema);
    void setVolumeOnRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVolumeOnRelatingElement() const;
    bool hasVolumeOnRelatingElement() const;
    std::shared_ptr<GfcBody> getVolumeOnRelatingElementPtr();
    void setVolumeOnRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVolumeOnRelatedElement() const;
    bool hasVolumeOnRelatedElement() const;
    std::shared_ptr<GfcBody> getVolumeOnRelatedElementPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
