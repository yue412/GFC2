#ifndef GFC2ROOT_H
#define GFC2ROOT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Root: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2Root, gfc::engine::CEntity)
public:
    Gfc2Root();
    Gfc2Root(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
