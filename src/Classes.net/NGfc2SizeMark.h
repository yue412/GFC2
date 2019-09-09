#ifndef NGFC2SIZEMARK_H
#define NGFC2SIZEMARK_H

#include "NGfc2Entity.h"
#include "Gfc2SizeMark.h"
#include "NGfc2CoedgeList.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SizeMark: public NGfc2Entity
{
public:
    NGfc2SizeMark();
    NGfc2SizeMark(void* pEntity, bool bOwner);
    void setSizeMarkType(NGfc2SizeMarkType nValue);
    NGfc2SizeMarkType getSizeMarkType();
    bool hasSizeMarkType();
    void setStartLine(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getStartLine();
    bool hasStartLine();
    NGfc2CoedgeList^ getStartLinePtr();
    void setEndLine(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEndLine();
    bool hasEndLine();
    NGfc2CoedgeList^ getEndLinePtr();

};
#endif
