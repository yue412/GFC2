#ifndef NGFC2SOLIDSHAPE_H
#define NGFC2SOLIDSHAPE_H

#include "NGfc2Shape3d.h"
#include "Gfc2SolidShape.h"
#include "NGfc2Body.h"
#include "NGfc2EdgeData.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SolidShape: public NGfc2Shape3d
{
public:
    NGfc2SolidShape();
    NGfc2SolidShape(void* pEntity, bool bOwner);
    void setBody(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getBody();
    bool hasBody();
    NGfc2Body^ getBodyPtr();
    int getEdgeDatasCount();
    void clearEdgeDatas();
    void addEdgeDatas(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getEdgeDatas(int nIndex);
    NGfc2EdgeData^ getEdgeDatasPtr(int nIndex);

};
#endif
