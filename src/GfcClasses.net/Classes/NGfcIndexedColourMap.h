#ifndef NGFCINDEXEDCOLOURMAP_H
#define NGFCINDEXEDCOLOURMAP_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcIndexedColourMap.h"
#include "NGfcColor.h"
#include "NGfcTriangulatedFaceSet.h"
#include "NTypeDef.h"

public ref class NGfcIndexedColourMap: public NGfcRoot
{
public:
    NGfcIndexedColourMap();
    NGfcIndexedColourMap(bool bNoCreate);
    void setOpacity(NGfcDouble dValue);
    NGfcDouble getOpacity();
    bool hasOpacity();
    void setColor(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getColor();
    bool hasColor();
    void setMappedTo(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMappedTo();
    bool hasMappedTo();

};
#endif
