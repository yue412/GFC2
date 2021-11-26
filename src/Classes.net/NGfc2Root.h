#ifndef NGFC2ROOT_H
#define NGFC2ROOT_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\Gfc2Root.h"

public ref class NGfc2Root: public NGfcEntity
{
public:
    NGfc2Root();
    NGfc2Root(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
