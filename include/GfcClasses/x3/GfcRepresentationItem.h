#ifndef GFCREPRESENTATIONITEM_H
#define GFCREPRESENTATIONITEM_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRepresentationItem: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcRepresentationItem, gfc::engine::CEntity)
public:
    GfcRepresentationItem();
    GfcRepresentationItem(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
