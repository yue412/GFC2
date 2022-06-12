#ifndef NGFCROOT_H
#define NGFCROOT_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcRoot.h"

public ref class NGfcRoot: public NGfcEntity
{
public:
    NGfcRoot();
    NGfcRoot(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
