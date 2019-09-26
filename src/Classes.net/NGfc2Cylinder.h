#ifndef NGFC2CYLINDER_H
#define NGFC2CYLINDER_H

#include "NGfc2Surface.h"
#include "Gfc2Cylinder.h"
#include "NGfc2Intervald.h"
#include "NGfc2Curve2d.h"
#include "NGfc2Vector3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Cylinder: public NGfc2Surface
{
public:
    NGfc2Cylinder();
    NGfc2Cylinder(void* pEntity, bool bOwner);
    void setRangeV(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();
    void setCurve(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve2d^ getCurvePtr();
    void setDirX(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirX();
    bool hasDirX();
    NGfc2Vector3d^ getDirXPtr();
    void setDirY(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirY();
    bool hasDirY();
    NGfc2Vector3d^ getDirYPtr();
    void setDirZ(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirZ();
    bool hasDirZ();
    NGfc2Vector3d^ getDirZPtr();
    void setPos(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPos();
    bool hasPos();
    NGfc2Vector3d^ getPosPtr();

};
#endif
