#ifndef NGFC2FACESHAPE_H
#define NGFC2FACESHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2FaceShape.h"
#include "NGfc2Polygon.h"
#include "NGfc2FaceInfo.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2FaceShape: public NGfc2SolidShape
{
public:
    NGfc2FaceShape();
    NGfc2FaceShape(void* pEntity, bool bOwner);
    void setThickness(NGfc2Double dValue);
    NGfc2Double getThickness();
    bool hasThickness();
    void setPoly(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPoly();
    bool hasPoly();
    NGfc2Polygon^ getPolyPtr();
    void setMirrorFlag(NGfc2Boolean bValue);
    NGfc2Boolean getMirrorFlag();
    bool hasMirrorFlag();
    void setFaceInfo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getFaceInfo();
    bool hasFaceInfo();
    NGfc2FaceInfo^ getFaceInfoPtr();

};
#endif
