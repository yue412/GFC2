#ifndef NGFC2SITE_H
#define NGFC2SITE_H

#include "NGfc2SpatialStructureElement.h"
#include "GfcClasses\x3\Gfc2Site.h"

public ref class NGfc2Site: public NGfc2SpatialStructureElement
{
public:
    NGfc2Site();
    NGfc2Site(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
