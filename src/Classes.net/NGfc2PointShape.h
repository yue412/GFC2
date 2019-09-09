#ifndef NGFC2POINTSHAPE_H
#define NGFC2POINTSHAPE_H

#include "NGfc2SectionPointShape.h"
#include "Gfc2PointShape.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Polygon.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PointShape: public NGfc2SectionPointShape
{
public:
    NGfc2PointShape();
    NGfc2PointShape(void* pEntity, bool bOwner);
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setObliqueDir(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getObliqueDir();
    bool hasObliqueDir();
    NGfc2Vector3d^ getObliqueDirPtr();
    void setTopPoly(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getTopPoly();
    bool hasTopPoly();
    NGfc2Polygon^ getTopPolyPtr();

};
#endif
