#ifndef GFC2HALFSPACESOLIDSHAPE_H
#define GFC2HALFSPACESOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SolidShape.h"
#include "GfcClasses/x3/Gfc2Surface.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2HalfSpaceSolidShape: public Gfc2SolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2HalfSpaceSolidShape, gfc::engine::CEntity)
public:
    Gfc2HalfSpaceSolidShape();
    Gfc2HalfSpaceSolidShape(bool bSetSchema);
    void setBaseSurface(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBaseSurface() const;
    bool hasBaseSurface() const;
    std::shared_ptr<Gfc2Surface> getBaseSurfacePtr();
    void setAgreementFlag(const Gfc2Boolean& bValue);
    Gfc2Boolean getAgreementFlag() const;
    bool hasAgreementFlag() const;

};

GFCCLASSES_NAMESPACE_END

#endif
