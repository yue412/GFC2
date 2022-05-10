#ifndef GFCBOOLEANRESULT_H
#define GFCBOOLEANRESULT_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSolidShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBooleanResult: public GfcSolidShape
{
GFCENGINE_DEC_OBJECT(GfcBooleanResult, gfc::engine::CEntity)
public:
    GfcBooleanResult();
    GfcBooleanResult(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
