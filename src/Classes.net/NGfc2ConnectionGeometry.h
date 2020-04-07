#ifndef NGFC2CONNECTIONGEOMETRY_H
#define NGFC2CONNECTIONGEOMETRY_H

#include "Gfc2ConnectionGeometry.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ConnectionGeometry: public glodon::objectbufnet::Entity
{
public:
    NGfc2ConnectionGeometry();
    NGfc2ConnectionGeometry(void* pEntity, bool bOwner);

};
#endif
