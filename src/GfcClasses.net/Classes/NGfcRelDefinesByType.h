#ifndef NGFCRELDEFINESBYTYPE_H
#define NGFCRELDEFINESBYTYPE_H

#include "NGfcRelDefines.h"
#include "GfcClasses\x3\GfcRelDefinesByType.h"
#include "NGfcElementType.h"
#include "NGfcElement.h"

public ref class NGfcRelDefinesByType: public NGfcRelDefines
{
public:
    NGfcRelDefinesByType();
    NGfcRelDefinesByType(bool bNoCreate);
    void setRelatingType(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingType();
    bool hasRelatingType();
    int getRelatingElementCount();
    void clearRelatingElement();
    void addRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingElement(int nIndex);

};
#endif
