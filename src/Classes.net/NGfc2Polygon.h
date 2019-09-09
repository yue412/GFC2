#ifndef NGFC2POLYGON_H
#define NGFC2POLYGON_H

#include "Gfc2Polygon.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Polygon: public glodon::objectbufnet::Entity
{
public:
    NGfc2Polygon();
    NGfc2Polygon(void* pEntity, bool bOwner);

};
#endif
