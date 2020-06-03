#ifndef GFC2CIRCLESECTION_H
#define GFC2CIRCLESECTION_H

#include "GfcClasses.h"
#include "Gfc2ParameterizedSection.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CircleSection: public Gfc2ParameterizedSection
{
GFCENGINE_DEC_OBJECT(Gfc2CircleSection, gfc::engine::Entity)
public:
    Gfc2CircleSection();
    Gfc2CircleSection(bool bSetSchema);
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;

};
#endif
