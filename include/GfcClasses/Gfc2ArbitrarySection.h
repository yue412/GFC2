#ifndef GFC2ARBITRARYSECTION_H
#define GFC2ARBITRARYSECTION_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Section.h"
#include "Gfc2Polygon.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ArbitrarySection: public Gfc2Section
{
GFCENGINE_DEC_OBJECT(Gfc2ArbitrarySection,gfc2::engine::EntityFactory)
public:
    Gfc2ArbitrarySection();
    Gfc2ArbitrarySection(bool bSetSchema);
    void setPoly(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPoly() const;
    bool hasPoly() const;
    std::shared_ptr<Gfc2Polygon> getPolyPtr();

};
#endif
