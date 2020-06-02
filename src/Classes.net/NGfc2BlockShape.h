#ifndef NGFC2BLOCKSHAPE_H
#define NGFC2BLOCKSHAPE_H

#include "NGfc2PrimitiveShape.h"
#include "Gfc2BlockShape.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2BlockShape: public NGfc2PrimitiveShape
{
public:
    NGfc2BlockShape();
    NGfc2BlockShape(void* pEntity, bool bOwner);
    void setXLength(NGfc2Double dValue);
    NGfc2Double getXLength();
    bool hasXLength();
    void setYLength(NGfc2Double dValue);
    NGfc2Double getYLength();
    bool hasYLength();
    void setZLength(NGfc2Double dValue);
    NGfc2Double getZLength();
    bool hasZLength();

};
#endif
