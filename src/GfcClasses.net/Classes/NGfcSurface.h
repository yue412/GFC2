#ifndef NGFCSURFACE_H
#define NGFCSURFACE_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcSurface.h"

public ref class NGfcSurface: public NGfcGeometry
{
public:
    NGfcSurface();
    NGfcSurface(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
