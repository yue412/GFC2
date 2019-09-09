#ifndef NGFC2COEDGELISTEX_H
#define NGFC2COEDGELISTEX_H

#include "Gfc2CoedgeListEx.h"
#include "NGfc2Coedge.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CoedgeListEx: public glodon::objectbufnet::Entity
{
public:
    NGfc2CoedgeListEx();
    NGfc2CoedgeListEx(void* pEntity, bool bOwner);
    int getCoedgeExsCount();
    void clearCoedgeExs();
    void addCoedgeExs(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCoedgeExs(int nIndex);
    NGfc2Coedge^ getCoedgeExsPtr(int nIndex);

};
#endif
