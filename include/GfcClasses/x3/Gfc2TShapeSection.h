#ifndef GFC2TSHAPESECTION_H
#define GFC2TSHAPESECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ParameterizedSection.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2TShapeSection: public Gfc2ParameterizedSection
{
GFCENGINE_DEC_OBJECT(Gfc2TShapeSection, gfc::engine::CEntity)
public:
    Gfc2TShapeSection();
    Gfc2TShapeSection(bool bSetSchema);
    void setWidth(const Gfc2Double& dValue);
    Gfc2Double getWidth() const;
    bool hasWidth() const;
    void setHeight(const Gfc2Double& dValue);
    Gfc2Double getHeight() const;
    bool hasHeight() const;
    void setThickness1(const Gfc2Double& dValue);
    Gfc2Double getThickness1() const;
    bool hasThickness1() const;
    void setThickness2(const Gfc2Double& dValue);
    Gfc2Double getThickness2() const;
    bool hasThickness2() const;
    void setLeftWidth(const Gfc2Double& dValue);
    Gfc2Double getLeftWidth() const;
    bool hasLeftWidth() const;

};

GFCCLASSES_NAMESPACE_END

#endif
