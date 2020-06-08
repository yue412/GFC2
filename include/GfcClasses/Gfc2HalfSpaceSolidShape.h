#ifndef GFC2HALFSPACESOLIDSHAPE_H
#define GFC2HALFSPACESOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2SolidShape.h"
#include "Gfc2Surface.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

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
#endif
