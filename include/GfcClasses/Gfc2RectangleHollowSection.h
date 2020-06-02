#ifndef GFC2RECTANGLEHOLLOWSECTION_H
#define GFC2RECTANGLEHOLLOWSECTION_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2RectangleSection.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RectangleHollowSection: public Gfc2RectangleSection
{
GFCENGINE_DEC_OBJECT(Gfc2RectangleHollowSection,gfc2::engine::EntityFactory)
public:
    Gfc2RectangleHollowSection();
    Gfc2RectangleHollowSection(bool bSetSchema);
    void setThickness(const Gfc2Double& dValue);
    Gfc2Double getThickness() const;
    bool hasThickness() const;

};
#endif
