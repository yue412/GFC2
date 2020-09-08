#ifndef NGFC2PRIMITIVERENDERABLE_H
#define NGFC2PRIMITIVERENDERABLE_H

#include "NGfc2RepresentationItem.h"
#include "Gfc2PrimitiveRenderable.h"
#include "NGfc2Vector3d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2PrimitiveRenderable: public NGfc2RepresentationItem
{
public:
    NGfc2PrimitiveRenderable();
    NGfc2PrimitiveRenderable(void* pEntity, bool bOwner);
    void setPrimitiveType(NGfc2PrimitiveType nValue);
    NGfc2PrimitiveType getPrimitiveType();
    bool hasPrimitiveType();
    void setGeometryDataType(NGfc2GeometryDataType nValue);
    NGfc2GeometryDataType getGeometryDataType();
    bool hasGeometryDataType();
    void setExtension(NGfc2String sValue);
    NGfc2String getExtension();
    bool hasExtension();
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getVertexes(int nIndex);
    NGfc2Vector3d^ getVertexesPtr(int nIndex);
    int getNormalsCount();
    void clearNormals();
    void addNormals(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getNormals(int nIndex);
    NGfc2Vector3d^ getNormalsPtr(int nIndex);
    int getIndexesCount();
    void clearIndexes();
    void addIndexes(NGfc2Integer nValue);
    NGfc2Integer getIndexes(int nIndex);

};
#endif
