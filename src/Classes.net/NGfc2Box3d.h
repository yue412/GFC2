#ifndef NGFC2BOX3D_H
#define NGFC2BOX3D_H

#include "NGfc2Geometry.h"
#include "Gfc2Box3d.h"
#include "NGfc2Vector3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Box3d: public NGfc2Geometry
{
public:
    NGfc2Box3d();
    NGfc2Box3d(void* pEntity, bool bOwner);
    void setMin(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getMin();
    bool hasMin();
    NGfc2Vector3d^ getMinPtr();
    void setMax(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getMax();
    bool hasMax();
    NGfc2Vector3d^ getMaxPtr();

};
#endif
