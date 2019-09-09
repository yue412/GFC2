#ifndef NGFC2RULEDSURFACE_H
#define NGFC2RULEDSURFACE_H

#include "NGfc2Surface.h"
#include "Gfc2RuledSurface.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve3d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RuledSurface: public NGfc2Surface
{
public:
    NGfc2RuledSurface();
    NGfc2RuledSurface(void* pEntity, bool bOwner);
    void setApexIndex(NGfc2Integer nValue);
    NGfc2Integer getApexIndex();
    bool hasApexIndex();
    void setRangeV(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();
    void setRangeU(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeU();
    bool hasRangeU();
    NGfc2Intervald^ getRangeUPtr();
    void setDirectrix1(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirectrix1();
    bool hasDirectrix1();
    NGfc2Curve3d^ getDirectrix1Ptr();
    void setDirectrix2(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirectrix2();
    bool hasDirectrix2();
    NGfc2Curve3d^ getDirectrix2Ptr();

};
#endif
