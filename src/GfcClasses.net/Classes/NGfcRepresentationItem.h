#ifndef NGFCREPRESENTATIONITEM_H
#define NGFCREPRESENTATIONITEM_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcRepresentationItem.h"

public ref class NGfcRepresentationItem: public NGfcEntity
{
public:
    NGfcRepresentationItem();
    NGfcRepresentationItem(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
