#ifndef NGFC2RELDEFINESBYPROPERTIES_H
#define NGFC2RELDEFINESBYPROPERTIES_H

#include "NGfc2RelDefines.h"
#include "GfcClasses\x3\Gfc2RelDefinesByProperties.h"
#include "NGfc2PropertySet.h"
#include "NGfc2Object.h"

public ref class NGfc2RelDefinesByProperties: public NGfc2RelDefines
{
public:
    NGfc2RelDefinesByProperties();
    NGfc2RelDefinesByProperties(void* pEntity, bool bOwner);
    void setRelatingPropertySet(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingPropertySet();
    bool hasRelatingPropertySet();
    int getRelatedObjectsCount();
    void clearRelatedObjects();
    void addRelatedObjects(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatedObjects(int nIndex);

};
#endif
