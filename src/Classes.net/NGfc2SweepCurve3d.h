#ifndef NGFC2SWEEPCURVE3D_H
#define NGFC2SWEEPCURVE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2SweepCurve3d.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Vector2d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SweepCurve3d: public NGfc2Curve3d
{
public:
    NGfc2SweepCurve3d();
    NGfc2SweepCurve3d(void* pEntity, bool bOwner);
    void setSpine3d(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSpine3d();
    bool hasSpine3d();
    NGfc2Curve3d^ getSpine3dPtr();
    void setReferenceVector(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getReferenceVector();
    bool hasReferenceVector();
    NGfc2Vector3d^ getReferenceVectorPtr();
    void setPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoint();
    bool hasPoint();
    NGfc2Vector2d^ getPointPtr();

};
#endif
