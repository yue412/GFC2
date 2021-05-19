#ifndef NGFC2ROOT_H
#define NGFC2ROOT_H

#include "Gfc2Root.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Root: public glodon::objectbufnet::Entity
{
public:
    NGfc2Root();
    NGfc2Root(void* pEntity, bool bOwner);

};
#endif
