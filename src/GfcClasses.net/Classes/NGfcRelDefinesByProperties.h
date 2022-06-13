#ifndef NGFCRELDEFINESBYPROPERTIES_H
#define NGFCRELDEFINESBYPROPERTIES_H

#include "NGfcRelDefines.h"
#include "GfcClasses\x3\GfcRelDefinesByProperties.h"
#include "NGfcPropertySet.h"
#include "NGfcObject.h"

public ref class NGfcRelDefinesByProperties: public NGfcRelDefines
{
public:
    NGfcRelDefinesByProperties();
    NGfcRelDefinesByProperties(bool bNoCreate);
    void setRelatingPropertySet(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingPropertySet();
    bool hasRelatingPropertySet();
    int getRelatedObjectsCount();
    void clearRelatedObjects();
    void addRelatedObjects(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex);

};
#endif
