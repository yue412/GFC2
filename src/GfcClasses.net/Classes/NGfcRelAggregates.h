#ifndef NGFCRELAGGREGATES_H
#define NGFCRELAGGREGATES_H

#include "NGfcRelDecomposes.h"
#include "GfcClasses\x3\GfcRelAggregates.h"
#include "NGfcObject.h"

public ref class NGfcRelAggregates: public NGfcRelDecomposes
{
public:
    NGfcRelAggregates();
    NGfcRelAggregates(bool bNoCreate);
    void setRelatingObject(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingObject();
    bool hasRelatingObject();
    int getRelatedObjectsCount();
    void clearRelatedObjects();
    void addRelatedObjects(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex);

};
#endif
