#ifndef NGFC2FACE_H
#define NGFC2FACE_H

#include "NGfc2CommonPolygonEx.h"
#include "GfcClasses\x3\Gfc2Face.h"
#include "NGfc2Surface.h"
#include "NGfc2Box3d.h"
#include "NTypeDef.h"

public ref class NGfc2Face: public NGfc2CommonPolygonEx
{
public:
    NGfc2Face();
    NGfc2Face(void* pEntity, bool bOwner);
    void setSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSurface();
    bool hasSurface();
    void setBox(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBox();
    bool hasBox();
    void setSameDir(NGfc2Boolean bValue);
    NGfc2Boolean getSameDir();
    bool hasSameDir();
    void setIndex(NGfc2Integer nValue);
    NGfc2Integer getIndex();
    bool hasIndex();

};
#endif
