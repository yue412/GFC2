#ifndef NGFC2BASELINEARCINFO_H
#define NGFC2BASELINEARCINFO_H

#include "Gfc2BaseLineArcInfo.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2BaseLineArcInfo: public glodon::objectbufnet::Entity
{
public:
    NGfc2BaseLineArcInfo();
    NGfc2BaseLineArcInfo(void* pEntity, bool bOwner);

};
#endif
