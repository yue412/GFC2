#ifndef GFC2RELDECOMPOSES_H
#define GFC2RELDECOMPOSES_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RelationShip.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelDecomposes: public Gfc2RelationShip
{
GFCENGINE_DEC_OBJECT(Gfc2RelDecomposes,gfc2::engine::EntityFactory)
public:
    Gfc2RelDecomposes();
    Gfc2RelDecomposes(bool bSetSchema);

};
#endif
