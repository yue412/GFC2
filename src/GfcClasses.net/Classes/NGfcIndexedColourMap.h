#ifndef NGFCINDEXEDCOLOURMAP_H
#define NGFCINDEXEDCOLOURMAP_H

#include "NEntity.h"
#include "GfcClasses\x3\GfcIndexedColourMap.h"
#include "NGfcColor.h"
#include "NGfcPrimitiveRenderable.h"
#include "NTypeDef.h"

public ref class NGfcIndexedColourMap: public NEntity
{
public:
    NGfcIndexedColourMap();
    NGfcIndexedColourMap(bool bNoCreate);
    void setTransparency(NGfcDouble dValue);
    NGfcDouble getTransparency();
    bool hasTransparency();
    int getColoursCount();
    void clearColours();
    void addColours(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getColours(int nIndex);
    int getColourIndexCount();
    void clearColourIndex();
    void addColourIndex(NGfcInteger nValue);
    NGfcInteger getColourIndex(int nIndex);
    void setMappedTo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMappedTo();
    bool hasMappedTo();

};
#endif
