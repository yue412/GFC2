#ifndef NGFCGEOMETRY_H
#define NGFCGEOMETRY_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcGeometry.h"

public ref class NGfcGeometry: public NGfcEntity
{
public:
    NGfcGeometry();
    NGfcGeometry(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
