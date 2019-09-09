#ifndef NGFC2AXISGRID_H
#define NGFC2AXISGRID_H

#include "NGfc2Entity.h"
#include "Gfc2AxisGrid.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2AxisGrid: public NGfc2Entity
{
public:
    NGfc2AxisGrid();
    NGfc2AxisGrid(void* pEntity, bool bOwner);

};
#endif
