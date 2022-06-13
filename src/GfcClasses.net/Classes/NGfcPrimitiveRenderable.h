#ifndef NGFCPRIMITIVERENDERABLE_H
#define NGFCPRIMITIVERENDERABLE_H

#include "NGfcRepresentationItem.h"
#include "GfcClasses\x3\GfcPrimitiveRenderable.h"
#include "NGfcVector3d.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcPrimitiveRenderable: public NGfcRepresentationItem
{
public:
    NGfcPrimitiveRenderable();
    NGfcPrimitiveRenderable(bool bNoCreate);
    void setPrimitiveType(NGfcPrimitiveType nValue);
    NGfcPrimitiveType getPrimitiveType();
    bool hasPrimitiveType();
    void setGeometryDataType(NGfcGeometryDataType nValue);
    NGfcGeometryDataType getGeometryDataType();
    bool hasGeometryDataType();
    void setExtension(NGfcString sValue);
    NGfcString getExtension();
    bool hasExtension();
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVertexes(int nIndex);
    int getNormalsCount();
    void clearNormals();
    void addNormals(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getNormals(int nIndex);
    int getIndexesCount();
    void clearIndexes();
    void addIndexes(NGfcInteger nValue);
    NGfcInteger getIndexes(int nIndex);

};
#endif
