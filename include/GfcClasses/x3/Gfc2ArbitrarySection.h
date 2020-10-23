#ifndef GFC2ARBITRARYSECTION_H
#define GFC2ARBITRARYSECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Section.h"
#include "GfcClasses/x3/Gfc2Polygon.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ArbitrarySection: public Gfc2Section
{
GFCENGINE_DEC_OBJECT(Gfc2ArbitrarySection, gfc::engine::CEntity)
public:
    Gfc2ArbitrarySection();
    Gfc2ArbitrarySection(bool bSetSchema);
    void setPoly(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPoly() const;
    bool hasPoly() const;
    std::shared_ptr<Gfc2Polygon> getPolyPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
