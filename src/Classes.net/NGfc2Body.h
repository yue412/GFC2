#ifndef NGFC2BODY_H
#define NGFC2BODY_H

#include "NGfc2Geometry.h"
#include "Gfc2Body.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Body: public NGfc2Geometry
{
public:
    NGfc2Body();
    NGfc2Body(void* pEntity, bool bOwner);

};
#endif
