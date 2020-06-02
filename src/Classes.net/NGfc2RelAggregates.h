#ifndef NGFC2RELAGGREGATES_H
#define NGFC2RELAGGREGATES_H

#include "NGfc2RelDecomposes.h"
#include "Gfc2RelAggregates.h"
#include "NGfc2Object.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RelAggregates: public NGfc2RelDecomposes
{
public:
    NGfc2RelAggregates();
    NGfc2RelAggregates(void* pEntity, bool bOwner);
    void setRelatingObject(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRelatingObject();
    bool hasRelatingObject();
    NGfc2Object^ getRelatingObjectPtr();
    int getRelatedObjectsCount();
    void clearRelatedObjects();
    void addRelatedObjects(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRelatedObjects(int nIndex);
    NGfc2Object^ getRelatedObjectsPtr(int nIndex);

};
#endif
