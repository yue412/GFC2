#ifndef NGFC2SPATIALSTRUCTUREENTITY_H
#define NGFC2SPATIALSTRUCTUREENTITY_H

#include "NGfc2Object.h"
#include "Gfc2SpatialStructureEntity.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SpatialStructureEntity: public NGfc2Object
{
public:
    NGfc2SpatialStructureEntity();
    NGfc2SpatialStructureEntity(void* pEntity, bool bOwner);

};
#endif
