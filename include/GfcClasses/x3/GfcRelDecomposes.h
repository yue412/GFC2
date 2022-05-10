#ifndef GFCRELDECOMPOSES_H
#define GFCRELDECOMPOSES_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRelationShip.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelDecomposes: public GfcRelationShip
{
GFCENGINE_DEC_OBJECT(GfcRelDecomposes, gfc::engine::CEntity)
public:
    GfcRelDecomposes();
    GfcRelDecomposes(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
