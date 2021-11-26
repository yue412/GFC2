#ifndef NGFC2RELDECOMPOSES_H
#define NGFC2RELDECOMPOSES_H

#include "NGfc2RelationShip.h"
#include "GfcClasses\x3\Gfc2RelDecomposes.h"

public ref class NGfc2RelDecomposes: public NGfc2RelationShip
{
public:
    NGfc2RelDecomposes();
    NGfc2RelDecomposes(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
