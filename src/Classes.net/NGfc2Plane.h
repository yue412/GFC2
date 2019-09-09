#ifndef NGFC2PLANE_H
#define NGFC2PLANE_H

#include "NGfc2Surface.h"
#include "Gfc2Plane.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Intervald.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Plane: public NGfc2Surface
{
public:
    NGfc2Plane();
    NGfc2Plane(void* pEntity, bool bOwner);
    void setPos(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPos();
    bool hasPos();
    NGfc2Vector3d^ getPosPtr();
    void setDirU(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirU();
    bool hasDirU();
    NGfc2Vector3d^ getDirUPtr();
    void setDirV(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDirV();
    bool hasDirV();
    NGfc2Vector3d^ getDirVPtr();
    void setRangeU(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeU();
    bool hasRangeU();
    NGfc2Intervald^ getRangeUPtr();
    void setRangeV(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRangeV();
    bool hasRangeV();
    NGfc2Intervald^ getRangeVPtr();

};
#endif
