#ifndef NGFC2BOOLEANRESULT_H
#define NGFC2BOOLEANRESULT_H

#include "NGfc2SolidShape.h"
#include "Gfc2BooleanResult.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2BooleanResult: public NGfc2SolidShape
{
public:
    NGfc2BooleanResult();
    NGfc2BooleanResult(void* pEntity, bool bOwner);

};
#endif
