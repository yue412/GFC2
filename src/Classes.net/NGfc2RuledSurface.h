#ifndef NGFC2RULEDSURFACE_H
#define NGFC2RULEDSURFACE_H

#include "NGfc2Surface.h"
#include "GfcClasses\x3\Gfc2RuledSurface.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve3d.h"
#include "NTypeDef.h"

public ref class NGfc2RuledSurface: public NGfc2Surface
{
public:
    NGfc2RuledSurface();
    NGfc2RuledSurface(gfc::engine::CEntity* pEntity, bool bOwner);
    void setApexIndex(NGfc2Integer nValue);
    NGfc2Integer getApexIndex();
    bool hasApexIndex();
    void setRangeV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeV();
    bool hasRangeV();
    void setRangeU(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRangeU();
    bool hasRangeU();
    void setDirectrix1(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirectrix1();
    bool hasDirectrix1();
    void setDirectrix2(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getDirectrix2();
    bool hasDirectrix2();

};
#endif
