#ifndef NGFC2REPRESENTATIONITEM_H
#define NGFC2REPRESENTATIONITEM_H

#include "NGfc2Root.h"
#include "Gfc2RepresentationItem.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RepresentationItem: public NGfc2Root
{
public:
    NGfc2RepresentationItem();
    NGfc2RepresentationItem(void* pEntity, bool bOwner);

};
#endif
