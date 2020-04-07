#ifndef NGFC2INDEXEDCOLOURMAP_H
#define NGFC2INDEXEDCOLOURMAP_H

#include "Gfc2IndexedColourMap.h"
#include "NGfc2Color.h"
#include "NGfc2PrimitiveRenderable.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2IndexedColourMap: public glodon::objectbufnet::Entity
{
public:
    NGfc2IndexedColourMap();
    NGfc2IndexedColourMap(void* pEntity, bool bOwner);
    void setTransparency(NGfc2Double dValue);
    NGfc2Double getTransparency();
    bool hasTransparency();
    int getColoursCount();
    void clearColours();
    void addColours(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getColours(int nIndex);
    NGfc2Color^ getColoursPtr(int nIndex);
    int getColourIndexCount();
    void clearColourIndex();
    void addColourIndex(NGfc2Integer nValue);
    NGfc2Integer getColourIndex(int nIndex);
    void setMappedTo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getMappedTo();
    bool hasMappedTo();
    NGfc2PrimitiveRenderable^ getMappedToPtr();

};
#endif
