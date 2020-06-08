#ifndef GFC2ELLIPSESECTION_H
#define GFC2ELLIPSESECTION_H

#include "GfcClasses.h"
#include "Gfc2ParameterizedSection.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2EllipseSection: public Gfc2ParameterizedSection
{
GFCENGINE_DEC_OBJECT(Gfc2EllipseSection, gfc::engine::CEntity)
public:
    Gfc2EllipseSection();
    Gfc2EllipseSection(bool bSetSchema);
    void setSemiAxis1(const Gfc2Double& dValue);
    Gfc2Double getSemiAxis1() const;
    bool hasSemiAxis1() const;
    void setSemiAxis2(const Gfc2Double& dValue);
    Gfc2Double getSemiAxis2() const;
    bool hasSemiAxis2() const;

};
#endif
