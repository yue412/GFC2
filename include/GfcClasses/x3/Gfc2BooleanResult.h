#ifndef GFC2BOOLEANRESULT_H
#define GFC2BOOLEANRESULT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SolidShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2BooleanResult: public Gfc2SolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2BooleanResult, gfc::engine::CEntity)
public:
    Gfc2BooleanResult();
    Gfc2BooleanResult(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
