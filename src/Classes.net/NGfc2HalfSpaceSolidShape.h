#ifndef NGFC2HALFSPACESOLIDSHAPE_H
#define NGFC2HALFSPACESOLIDSHAPE_H

#include "NGfc2SolidShape.h"
#include "GfcClasses\x3\Gfc2HalfSpaceSolidShape.h"
#include "NGfc2Surface.h"
#include "NTypeDef.h"

public ref class NGfc2HalfSpaceSolidShape: public NGfc2SolidShape
{
public:
    NGfc2HalfSpaceSolidShape();
    NGfc2HalfSpaceSolidShape(void* pEntity, bool bOwner);
    void setBaseSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBaseSurface();
    bool hasBaseSurface();
    void setAgreementFlag(NGfc2Boolean bValue);
    NGfc2Boolean getAgreementFlag();
    bool hasAgreementFlag();

};
#endif
