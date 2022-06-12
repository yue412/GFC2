#ifndef NGFCCONNECTIONGEOMETRY_H
#define NGFCCONNECTIONGEOMETRY_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcConnectionGeometry.h"

public ref class NGfcConnectionGeometry: public NGfcEntity
{
public:
    NGfcConnectionGeometry();
    NGfcConnectionGeometry(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
