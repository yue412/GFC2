#ifndef NGFC2FACE_H
#define NGFC2FACE_H

#include "NGfc2CommonPolygonEx.h"
#include "Gfc2Face.h"
#include "NGfc2Surface.h"
#include "NGfc2Box3d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Face: public NGfc2CommonPolygonEx
{
public:
    NGfc2Face();
    NGfc2Face(void* pEntity, bool bOwner);
    void setSurface(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getSurface();
    bool hasSurface();
    NGfc2Surface^ getSurfacePtr();
    void setBox(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getBox();
    bool hasBox();
    NGfc2Box3d^ getBoxPtr();
    void setSameDir(NGfc2Boolean bValue);
    NGfc2Boolean getSameDir();
    bool hasSameDir();
    void setIndex(NGfc2Integer nValue);
    NGfc2Integer getIndex();
    bool hasIndex();

};
#endif
