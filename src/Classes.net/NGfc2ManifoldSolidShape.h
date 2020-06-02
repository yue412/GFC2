#ifndef NGFC2MANIFOLDSOLIDSHAPE_H
#define NGFC2MANIFOLDSOLIDSHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2ManifoldSolidShape.h"
#include "NGfc2Body.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ManifoldSolidShape: public NGfc2SolidShape
{
public:
    NGfc2ManifoldSolidShape();
    NGfc2ManifoldSolidShape(void* pEntity, bool bOwner);
    void setBody(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getBody();
    bool hasBody();
    NGfc2Body^ getBodyPtr();

};
#endif
