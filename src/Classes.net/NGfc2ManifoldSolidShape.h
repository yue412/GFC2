#ifndef NGFC2MANIFOLDSOLIDSHAPE_H
#define NGFC2MANIFOLDSOLIDSHAPE_H

#include "NGfc2SolidShape.h"
#include "GfcClasses\x3\Gfc2ManifoldSolidShape.h"
#include "NGfc2Body.h"

public ref class NGfc2ManifoldSolidShape: public NGfc2SolidShape
{
public:
    NGfc2ManifoldSolidShape();
    NGfc2ManifoldSolidShape(void* pEntity, bool bOwner);
    void setBody(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBody();
    bool hasBody();

};
#endif
