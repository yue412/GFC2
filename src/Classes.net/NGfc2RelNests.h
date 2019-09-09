#ifndef NGFC2RELNESTS_H
#define NGFC2RELNESTS_H

#include "NGfc2RelDecomposes.h"
#include "Gfc2RelNests.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RelNests: public NGfc2RelDecomposes
{
public:
    NGfc2RelNests();
    NGfc2RelNests(void* pEntity, bool bOwner);

};
#endif
