#ifndef NGFC2BOX3D_H
#define NGFC2BOX3D_H

#include "NGfc2Geometry.h"
#include "Gfc2Box3d.h"
#include "NGfc2Vector3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Box3d: public NGfc2Geometry
{
public:
    NGfc2Box3d();
    NGfc2Box3d(void* pEntity, bool bOwner);
    void setMin(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getMin();
    bool hasMin();
    NGfc2Vector3d^ getMinPtr();
    void setMax(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getMax();
    bool hasMax();
    NGfc2Vector3d^ getMaxPtr();

};
#endif
