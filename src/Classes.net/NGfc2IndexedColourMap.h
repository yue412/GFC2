#ifndef NGFC2INDEXEDCOLOURMAP_H
#define NGFC2INDEXEDCOLOURMAP_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2IndexedColourMap.h"
#include "NGfc2Color.h"
#include "NGfc2PrimitiveRenderable.h"
#include "NTypeDef.h"

public ref class NGfc2IndexedColourMap: public NGfc2Root
{
public:
    NGfc2IndexedColourMap();
    NGfc2IndexedColourMap(void* pEntity, bool bOwner);
    void setTransparency(NGfc2Double dValue);
    NGfc2Double getTransparency();
    bool hasTransparency();
    int getColoursCount();
    void clearColours();
    void addColours(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getColours(int nIndex);
    int getColourIndexCount();
    void clearColourIndex();
    void addColourIndex(NGfc2Integer nValue);
    NGfc2Integer getColourIndex(int nIndex);
    void setMappedTo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMappedTo();
    bool hasMappedTo();

};
#endif
