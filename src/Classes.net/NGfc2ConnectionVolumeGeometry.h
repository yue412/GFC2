#ifndef NGFC2CONNECTIONVOLUMEGEOMETRY_H
#define NGFC2CONNECTIONVOLUMEGEOMETRY_H

#include "NGfc2ConnectionGeometry.h"
#include "Gfc2ConnectionVolumeGeometry.h"
#include "NGfc2Body.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ConnectionVolumeGeometry: public NGfc2ConnectionGeometry
{
public:
    NGfc2ConnectionVolumeGeometry();
    NGfc2ConnectionVolumeGeometry(void* pEntity, bool bOwner);
    void setVolumeOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVolumeOnRelatingElement();
    bool hasVolumeOnRelatingElement();
    NGfc2Body^ getVolumeOnRelatingElementPtr();
    void setVolumeOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVolumeOnRelatedElement();
    bool hasVolumeOnRelatedElement();
    NGfc2Body^ getVolumeOnRelatedElementPtr();

};
#endif
