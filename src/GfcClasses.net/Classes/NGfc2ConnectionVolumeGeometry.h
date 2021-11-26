#ifndef NGFC2CONNECTIONVOLUMEGEOMETRY_H
#define NGFC2CONNECTIONVOLUMEGEOMETRY_H

#include "NGfc2ConnectionGeometry.h"
#include "GfcClasses\x3\Gfc2ConnectionVolumeGeometry.h"
#include "NGfc2Body.h"

public ref class NGfc2ConnectionVolumeGeometry: public NGfc2ConnectionGeometry
{
public:
    NGfc2ConnectionVolumeGeometry();
    NGfc2ConnectionVolumeGeometry(gfc::engine::CEntity* pEntity, bool bOwner);
    void setVolumeOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVolumeOnRelatingElement();
    bool hasVolumeOnRelatingElement();
    void setVolumeOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVolumeOnRelatedElement();
    bool hasVolumeOnRelatedElement();

};
#endif
