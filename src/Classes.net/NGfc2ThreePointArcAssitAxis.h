#ifndef NGFC2THREEPOINTARCASSITAXIS_H
#define NGFC2THREEPOINTARCASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2ThreePointArcAssitAxis.h"
#include "NGfc2Vector2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ThreePointArcAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2ThreePointArcAssitAxis();
    NGfc2ThreePointArcAssitAxis(void* pEntity, bool bOwner);
    void setRefPoint1(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRefPoint1();
    bool hasRefPoint1();
    NGfc2Vector2d^ getRefPoint1Ptr();
    void setRefPoint2(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRefPoint2();
    bool hasRefPoint2();
    NGfc2Vector2d^ getRefPoint2Ptr();
    void setRefPoint3(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRefPoint3();
    bool hasRefPoint3();
    NGfc2Vector2d^ getRefPoint3Ptr();

};
#endif
