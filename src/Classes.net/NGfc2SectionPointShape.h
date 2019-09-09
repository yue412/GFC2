#ifndef NGFC2SECTIONPOINTSHAPE_H
#define NGFC2SECTIONPOINTSHAPE_H

#include "NGfc2CustomPointShape.h"
#include "Gfc2SectionPointShape.h"
#include "NGfc2Polygon.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SectionPointShape: public NGfc2CustomPointShape
{
public:
    NGfc2SectionPointShape();
    NGfc2SectionPointShape(void* pEntity, bool bOwner);
    void setPoly(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoly();
    bool hasPoly();
    NGfc2Polygon^ getPolyPtr();

};
#endif
