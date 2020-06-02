#ifndef NGFC2RELCONNECTS_H
#define NGFC2RELCONNECTS_H

#include "NGfc2RelationShip.h"
#include "Gfc2RelConnects.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RelConnects: public NGfc2RelationShip
{
public:
    NGfc2RelConnects();
    NGfc2RelConnects(void* pEntity, bool bOwner);

};
#endif
