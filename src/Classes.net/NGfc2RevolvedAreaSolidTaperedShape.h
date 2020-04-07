#ifndef NGFC2REVOLVEDAREASOLIDTAPEREDSHAPE_H
#define NGFC2REVOLVEDAREASOLIDTAPEREDSHAPE_H

#include "NGfc2RevolvedAreaSolidShape.h"
#include "Gfc2RevolvedAreaSolidTaperedShape.h"
#include "NGfc2Section.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RevolvedAreaSolidTaperedShape: public NGfc2RevolvedAreaSolidShape
{
public:
    NGfc2RevolvedAreaSolidTaperedShape();
    NGfc2RevolvedAreaSolidTaperedShape(void* pEntity, bool bOwner);
    void setEndSweptArea(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEndSweptArea();
    bool hasEndSweptArea();
    NGfc2Section^ getEndSweptAreaPtr();

};
#endif
