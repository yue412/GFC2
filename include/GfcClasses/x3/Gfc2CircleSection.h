#ifndef GFC2CIRCLESECTION_H
#define GFC2CIRCLESECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ParameterizedSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2CircleSection: public Gfc2ParameterizedSection
{
GFCENGINE_DEC_OBJECT(Gfc2CircleSection, gfc::engine::CEntity)
public:
    Gfc2CircleSection();
    Gfc2CircleSection(bool bSetSchema);
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;

};

GFCCLASSES_NAMESPACE_END

#endif
