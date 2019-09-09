#ifndef NGFC2SWEEP_H
#define NGFC2SWEEP_H

#include "NGfc2Surface.h"
#include "Gfc2Sweep.h"
#include "NGfc2Curve2d.h"
#include "NGfc2Curve3d.h"
#include "NGfc2Vector3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Sweep: public NGfc2Surface
{
public:
    NGfc2Sweep();
    NGfc2Sweep(void* pEntity, bool bOwner);
    void setProfile(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getProfile();
    bool hasProfile();
    NGfc2Curve2d^ getProfilePtr();
    void setSpine3d(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSpine3d();
    bool hasSpine3d();
    NGfc2Curve3d^ getSpine3dPtr();
    void setReferenceVector(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getReferenceVector();
    bool hasReferenceVector();
    NGfc2Vector3d^ getReferenceVectorPtr();

};
#endif
