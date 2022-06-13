#ifndef NGFCHALFSPACESOLIDSHAPE_H
#define NGFCHALFSPACESOLIDSHAPE_H

#include "NGfcSolidShape.h"
#include "GfcClasses\x3\GfcHalfSpaceSolidShape.h"
#include "NGfcSurface.h"
#include "NTypeDef.h"

public ref class NGfcHalfSpaceSolidShape: public NGfcSolidShape
{
public:
    NGfcHalfSpaceSolidShape();
    NGfcHalfSpaceSolidShape(bool bNoCreate);
    void setBaseSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBaseSurface();
    bool hasBaseSurface();
    void setAgreementFlag(NGfcBoolean bValue);
    NGfcBoolean getAgreementFlag();
    bool hasAgreementFlag();

};
#endif
