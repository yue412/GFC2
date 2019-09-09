#ifndef NGFC2TWOPOINTASSITAXIS_H
#define NGFC2TWOPOINTASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2TwoPointAssitAxis.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2TwoPointAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2TwoPointAssitAxis();
    NGfc2TwoPointAssitAxis(void* pEntity, bool bOwner);

};
#endif
