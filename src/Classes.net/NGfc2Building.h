#ifndef NGFC2BUILDING_H
#define NGFC2BUILDING_H

#include "NGfc2SpatialStructureElement.h"
#include "GfcClasses\x3\Gfc2Building.h"

public ref class NGfc2Building: public NGfc2SpatialStructureElement
{
public:
    NGfc2Building();
    NGfc2Building(void* pEntity, bool bOwner);

};
#endif
