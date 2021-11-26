#ifndef NGFC2RELDEFINES_H
#define NGFC2RELDEFINES_H

#include "NGfc2RelationShip.h"
#include "GfcClasses\x3\Gfc2RelDefines.h"

public ref class NGfc2RelDefines: public NGfc2RelationShip
{
public:
    NGfc2RelDefines();
    NGfc2RelDefines(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
