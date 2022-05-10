#ifndef GFCELLIPSESECTION_H
#define GFCELLIPSESECTION_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcParameterizedSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcEllipseSection: public GfcParameterizedSection
{
GFCENGINE_DEC_OBJECT(GfcEllipseSection, gfc::engine::CEntity)
public:
    GfcEllipseSection();
    GfcEllipseSection(bool bSetSchema);
    void setSemiAxis1(const GfcDouble& dValue);
    GfcDouble getSemiAxis1() const;
    bool hasSemiAxis1() const;
    void setSemiAxis2(const GfcDouble& dValue);
    GfcDouble getSemiAxis2() const;
    bool hasSemiAxis2() const;

};

GFCCLASSES_NAMESPACE_END

#endif
