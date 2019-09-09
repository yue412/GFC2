#ifndef NGFC2PROJECT_H
#define NGFC2PROJECT_H

#include "NGfc2Object.h"
#include "Gfc2Project.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Project: public NGfc2Object
{
public:
    NGfc2Project();
    NGfc2Project(void* pEntity, bool bOwner);

};
#endif
