#ifndef GFC2BOOLEANRESULT_H
#define GFC2BOOLEANRESULT_H

#include "GfcClasses.h"
#include "Gfc2SolidShape.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BooleanResult: public Gfc2SolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2BooleanResult, gfc2::engine::Entity)
public:
    Gfc2BooleanResult();
    Gfc2BooleanResult(bool bSetSchema);

};
#endif
