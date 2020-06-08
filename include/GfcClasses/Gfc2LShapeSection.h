#ifndef GFC2LSHAPESECTION_H
#define GFC2LSHAPESECTION_H

#include "GfcClasses.h"
#include "Gfc2ParameterizedSection.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2LShapeSection: public Gfc2ParameterizedSection
{
GFCENGINE_DEC_OBJECT(Gfc2LShapeSection, gfc::engine::CEntity)
public:
    Gfc2LShapeSection();
    Gfc2LShapeSection(bool bSetSchema);
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

};
#endif
