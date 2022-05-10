#ifndef GFCARBITRARYSECTION_H
#define GFCARBITRARYSECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSection.h"
#include "GfcClasses/x3/GfcPolygon.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcArbitrarySection: public GfcSection
{
GFCENGINE_DEC_OBJECT(GfcArbitrarySection, gfc::engine::CEntity)
public:
    GfcArbitrarySection();
    GfcArbitrarySection(bool bSetSchema);
    void setPoly(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPoly() const;
    bool hasPoly() const;
    std::shared_ptr<GfcPolygon> getPolyPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
