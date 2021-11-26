#ifndef NGFC2REPRESENTATIONITEM_H
#define NGFC2REPRESENTATIONITEM_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2RepresentationItem.h"

public ref class NGfc2RepresentationItem: public NGfc2Root
{
public:
    NGfc2RepresentationItem();
    NGfc2RepresentationItem(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
