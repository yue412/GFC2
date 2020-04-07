#ifndef NGFC2HALFSPACESOLIDSHAPE_H
#define NGFC2HALFSPACESOLIDSHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2HalfSpaceSolidShape.h"
#include "NGfc2Surface.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2HalfSpaceSolidShape: public NGfc2SolidShape
{
public:
    NGfc2HalfSpaceSolidShape();
    NGfc2HalfSpaceSolidShape(void* pEntity, bool bOwner);
    void setBaseSurface(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getBaseSurface();
    bool hasBaseSurface();
    NGfc2Surface^ getBaseSurfacePtr();
    void setAgreementFlag(NGfc2Boolean bValue);
    NGfc2Boolean getAgreementFlag();
    bool hasAgreementFlag();

};
#endif
