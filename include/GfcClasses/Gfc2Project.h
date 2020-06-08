#ifndef GFC2PROJECT_H
#define GFC2PROJECT_H

#include "GfcClasses.h"
#include "Gfc2Object.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Project: public Gfc2Object
{
GFCENGINE_DEC_OBJECT(Gfc2Project, gfc::engine::CEntity)
public:
    Gfc2Project();
    Gfc2Project(bool bSetSchema);

};
#endif
