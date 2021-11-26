#ifndef NGFC2ARBITRARYSECTION_H
#define NGFC2ARBITRARYSECTION_H

#include "NGfc2Section.h"
#include "GfcClasses\x3\Gfc2ArbitrarySection.h"
#include "NGfc2Polygon.h"

public ref class NGfc2ArbitrarySection: public NGfc2Section
{
public:
    NGfc2ArbitrarySection();
    NGfc2ArbitrarySection(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPoly(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoly();
    bool hasPoly();

};
#endif
