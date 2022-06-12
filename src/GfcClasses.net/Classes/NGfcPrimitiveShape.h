#ifndef NGFCPRIMITIVESHAPE_H
#define NGFCPRIMITIVESHAPE_H

#include "NGfcSolidShape.h"
#include "GfcClasses\x3\GfcPrimitiveShape.h"

public ref class NGfcPrimitiveShape: public NGfcSolidShape
{
public:
    NGfcPrimitiveShape();
    NGfcPrimitiveShape(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
