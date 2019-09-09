#ifndef NGFC2REPRESENTATIONITEM_H
#define NGFC2REPRESENTATIONITEM_H

#include "Gfc2RepresentationItem.h"
#include "NGfc2Vector3d.h"
#include "NGfc2StateSet.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2RepresentationItem: public glodon::objectbufnet::Entity
{
public:
    NGfc2RepresentationItem();
    NGfc2RepresentationItem(void* pEntity, bool bOwner);
    void setPrimitiveType(NGfc2PrimitiveType nValue);
    NGfc2PrimitiveType getPrimitiveType();
    bool hasPrimitiveType();
    void setGeometryDataType(NGfc2GeometryDataType nValue);
    NGfc2GeometryDataType getGeometryDataType();
    bool hasGeometryDataType();
    int getVertexesCount();
    void clearVertexes();
    void addVertexes(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getVertexes(int nIndex);
    NGfc2Vector3d^ getVertexesPtr(int nIndex);
    int getNormalsCount();
    void clearNormals();
    void addNormals(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getNormals(int nIndex);
    NGfc2Vector3d^ getNormalsPtr(int nIndex);
    int getIndexesCount();
    void clearIndexes();
    void addIndexes(NGfc2Integer nValue);
    NGfc2Integer getIndexes(int nIndex);
    void setStateSet(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getStateSet();
    bool hasStateSet();
    NGfc2StateSet^ getStateSetPtr();

};
#endif
