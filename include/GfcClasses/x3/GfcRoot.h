#ifndef GFCROOT_H
#define GFCROOT_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRoot: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcRoot, gfc::engine::CEntity)
public:
    GfcRoot();
    GfcRoot(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
