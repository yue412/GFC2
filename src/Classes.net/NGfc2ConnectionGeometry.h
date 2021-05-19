#ifndef NGFC2CONNECTIONGEOMETRY_H
#define NGFC2CONNECTIONGEOMETRY_H

#include "NGfc2Root.h"
#include "Gfc2ConnectionGeometry.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ConnectionGeometry: public NGfc2Root
{
public:
    NGfc2ConnectionGeometry();
    NGfc2ConnectionGeometry(void* pEntity, bool bOwner);

};
#endif
