#ifndef NGFCCONNECTIONVOLUMEGEOMETRY_H
#define NGFCCONNECTIONVOLUMEGEOMETRY_H

#include "NGfcConnectionGeometry.h"
#include "GfcClasses\x3\GfcConnectionVolumeGeometry.h"
#include "NGfcBody.h"

public ref class NGfcConnectionVolumeGeometry: public NGfcConnectionGeometry
{
public:
    NGfcConnectionVolumeGeometry();
    NGfcConnectionVolumeGeometry(bool bNoCreate);
    void setVolumeOnRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVolumeOnRelatingElement();
    bool hasVolumeOnRelatingElement();
    void setVolumeOnRelatedElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVolumeOnRelatedElement();
    bool hasVolumeOnRelatedElement();

};
#endif
