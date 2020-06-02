#ifndef GFC2REPRESENTATIONITEM_H
#define GFC2REPRESENTATIONITEM_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RepresentationItem: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2RepresentationItem,gfc2::engine::EntityFactory)
public:
    Gfc2RepresentationItem();
    Gfc2RepresentationItem(bool bSetSchema);

};
#endif
