#ifndef NGFC2PROJECT_H
#define NGFC2PROJECT_H

#include "NGfc2Object.h"
#include "GfcClasses\x3\Gfc2Project.h"

public ref class NGfc2Project: public NGfc2Object
{
public:
    NGfc2Project();
    NGfc2Project(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
