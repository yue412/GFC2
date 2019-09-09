#ifndef NGFC2RELAGGREGATES_H
#define NGFC2RELAGGREGATES_H

#include "NGfc2RelDecomposes.h"
#include "Gfc2RelAggregates.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelAggregates: public NGfc2RelDecomposes
{
public:
    NGfc2RelAggregates();
    NGfc2RelAggregates(void* pEntity, bool bOwner);

};
#endif
