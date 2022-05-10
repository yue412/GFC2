#ifndef GFCHALFSPACESOLIDSHAPE_H
#define GFCHALFSPACESOLIDSHAPE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSolidShape.h"
#include "GfcClasses/x3/GfcSurface.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcHalfSpaceSolidShape: public GfcSolidShape
{
GFCENGINE_DEC_OBJECT(GfcHalfSpaceSolidShape, gfc::engine::CEntity)
public:
    GfcHalfSpaceSolidShape();
    GfcHalfSpaceSolidShape(bool bSetSchema);
    void setBaseSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBaseSurface() const;
    bool hasBaseSurface() const;
    std::shared_ptr<GfcSurface> getBaseSurfacePtr();
    void setAgreementFlag(const GfcBoolean& bValue);
    GfcBoolean getAgreementFlag() const;
    bool hasAgreementFlag() const;

};

GFCCLASSES_NAMESPACE_END

#endif
