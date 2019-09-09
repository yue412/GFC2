#ifndef NGFC2FACESHAPE2D_H
#define NGFC2FACESHAPE2D_H

#include "NGfc2Shape2d.h"
#include "Gfc2FaceShape2d.h"
#include "NGfc2Polygon.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2FaceShape2d: public NGfc2Shape2d
{
public:
    NGfc2FaceShape2d();
    NGfc2FaceShape2d(void* pEntity, bool bOwner);
    void setPoly(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoly();
    bool hasPoly();
    NGfc2Polygon^ getPolyPtr();

};
#endif
