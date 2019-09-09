#ifndef NGFC2LINESHAPE2D_H
#define NGFC2LINESHAPE2D_H

#include "NGfc2Shape2d.h"
#include "Gfc2LineShape2d.h"
#include "NGfc2Curve2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2LineShape2d: public NGfc2Shape2d
{
public:
    NGfc2LineShape2d();
    NGfc2LineShape2d(void* pEntity, bool bOwner);
    void setLine(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getLine();
    bool hasLine();
    NGfc2Curve2d^ getLinePtr();

};
#endif
