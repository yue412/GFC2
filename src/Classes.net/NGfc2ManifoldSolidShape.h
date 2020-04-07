#ifndef NGFC2MANIFOLDSOLIDSHAPE_H
#define NGFC2MANIFOLDSOLIDSHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2ManifoldSolidShape.h"
#include "NGfc2Body.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ManifoldSolidShape: public NGfc2SolidShape
{
public:
    NGfc2ManifoldSolidShape();
    NGfc2ManifoldSolidShape(void* pEntity, bool bOwner);
    void setBody(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getBody();
    bool hasBody();
    NGfc2Body^ getBodyPtr();

};
#endif
