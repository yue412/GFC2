#ifndef GFCREPRESENTATIONITEM_H
#define GFCREPRESENTATIONITEM_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRepresentationItem: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcRepresentationItem, gfc::engine::CEntity)
public:
    GfcRepresentationItem();
    GfcRepresentationItem(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
