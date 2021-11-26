#ifndef NGFC2RELAGGREGATES_H
#define NGFC2RELAGGREGATES_H

#include "NGfc2RelDecomposes.h"
#include "GfcClasses\x3\Gfc2RelAggregates.h"
#include "NGfc2Object.h"

public ref class NGfc2RelAggregates: public NGfc2RelDecomposes
{
public:
    NGfc2RelAggregates();
    NGfc2RelAggregates(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRelatingObject(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingObject();
    bool hasRelatingObject();
    int getRelatedObjectsCount();
    void clearRelatedObjects();
    void addRelatedObjects(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex);

};
#endif
