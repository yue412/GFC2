#ifndef NGFC2VARIABLESECTIONLINESHAPE_H
#define NGFC2VARIABLESECTIONLINESHAPE_H

#include "NGfc2SectionLineShape.h"
#include "Gfc2VariableSectionLineShape.h"
#include "NGfc2Polygon.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2VariableSectionLineShape: public NGfc2SectionLineShape
{
public:
    NGfc2VariableSectionLineShape();
    NGfc2VariableSectionLineShape(void* pEntity, bool bOwner);
    void setEndPoly(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEndPoly();
    bool hasEndPoly();
    NGfc2Polygon^ getEndPolyPtr();

};
#endif
