#ifndef NGFCFACE_H
#define NGFCFACE_H

#include "NGfcCommonPolygonEx.h"
#include "GfcClasses\x3\GfcFace.h"
#include "NGfcSurface.h"
#include "NGfcBox3d.h"
#include "NTypeDef.h"

public ref class NGfcFace: public NGfcCommonPolygonEx
{
public:
    NGfcFace();
    NGfcFace(bool bNoCreate);
    void setSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSurface();
    bool hasSurface();
    void setBox(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBox();
    bool hasBox();
    void setSameDir(NGfcBoolean bValue);
    NGfcBoolean getSameDir();
    bool hasSameDir();
    void setIndex(NGfcInteger nValue);
    NGfcInteger getIndex();
    bool hasIndex();

};
#endif
