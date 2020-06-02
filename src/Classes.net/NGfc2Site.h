#ifndef NGFC2SITE_H
#define NGFC2SITE_H

#include "NGfc2SpatialStructureElement.h"
#include "Gfc2Site.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Site: public NGfc2SpatialStructureElement
{
public:
    NGfc2Site();
    NGfc2Site(void* pEntity, bool bOwner);

};
#endif
