#ifndef NGFC2CENTERSTARTENDARCASSITAXIS_H
#define NGFC2CENTERSTARTENDARCASSITAXIS_H

#include "NGfc2AssitAxis.h"
#include "Gfc2CenterStartEndArcAssitAxis.h"
#include "NGfc2Vector2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CenterStartEndArcAssitAxis: public NGfc2AssitAxis
{
public:
    NGfc2CenterStartEndArcAssitAxis();
    NGfc2CenterStartEndArcAssitAxis(void* pEntity, bool bOwner);
    void setCenter(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCenter();
    bool hasCenter();
    NGfc2Vector2d^ getCenterPtr();
    void setStartPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getStartPoint();
    bool hasStartPoint();
    NGfc2Vector2d^ getStartPointPtr();
    void setEndPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEndPoint();
    bool hasEndPoint();
    NGfc2Vector2d^ getEndPointPtr();

};
#endif
