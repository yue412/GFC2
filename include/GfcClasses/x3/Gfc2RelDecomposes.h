#ifndef GFC2RELDECOMPOSES_H
#define GFC2RELDECOMPOSES_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelationShip.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelDecomposes: public Gfc2RelationShip
{
GFCENGINE_DEC_OBJECT(Gfc2RelDecomposes, gfc::engine::CEntity)
public:
    Gfc2RelDecomposes();
    Gfc2RelDecomposes(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
