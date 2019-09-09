#ifndef NGFC2GEOMETRY_H
#define NGFC2GEOMETRY_H

#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Geometry: public glodon::objectbufnet::Entity
{
public:
    NGfc2Geometry();
    NGfc2Geometry(void* pEntity, bool bOwner);

};
#endif
