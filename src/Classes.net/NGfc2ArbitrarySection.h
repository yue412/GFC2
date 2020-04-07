#ifndef NGFC2ARBITRARYSECTION_H
#define NGFC2ARBITRARYSECTION_H

#include "NGfc2Section.h"
#include "Gfc2ArbitrarySection.h"
#include "NGfc2Polygon.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ArbitrarySection: public NGfc2Section
{
public:
    NGfc2ArbitrarySection();
    NGfc2ArbitrarySection(void* pEntity, bool bOwner);
    void setPoly(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoly();
    bool hasPoly();
    NGfc2Polygon^ getPolyPtr();

};
#endif
