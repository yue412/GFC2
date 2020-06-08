#ifndef GFC2CONNECTIONVOLUMEGEOMETRY_H
#define GFC2CONNECTIONVOLUMEGEOMETRY_H

#include "GfcClasses.h"
#include "Gfc2ConnectionGeometry.h"
#include "Gfc2Body.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ConnectionVolumeGeometry: public Gfc2ConnectionGeometry
{
GFCENGINE_DEC_OBJECT(Gfc2ConnectionVolumeGeometry, gfc::engine::CEntity)
public:
    Gfc2ConnectionVolumeGeometry();
    Gfc2ConnectionVolumeGeometry(bool bSetSchema);
    void setVolumeOnRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVolumeOnRelatingElement() const;
    bool hasVolumeOnRelatingElement() const;
    std::shared_ptr<Gfc2Body> getVolumeOnRelatingElementPtr();
    void setVolumeOnRelatedElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getVolumeOnRelatedElement() const;
    bool hasVolumeOnRelatedElement() const;
    std::shared_ptr<Gfc2Body> getVolumeOnRelatedElementPtr();

};
#endif
