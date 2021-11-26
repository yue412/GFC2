#ifndef NGFC2BOX3D_H
#define NGFC2BOX3D_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Box3d.h"
#include "NGfc2Vector3d.h"

public ref class NGfc2Box3d: public NGfc2Geometry
{
public:
    NGfc2Box3d();
    NGfc2Box3d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setMin(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMin();
    bool hasMin();
    void setMax(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMax();
    bool hasMax();

};
#endif
