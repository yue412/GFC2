#ifndef NGFC2RELDEFINESBYTYPE_H
#define NGFC2RELDEFINESBYTYPE_H

#include "NGfc2RelDefines.h"
#include "Gfc2RelDefinesByType.h"
#include "NGfc2ElementType.h"
#include "NGfc2Element.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2RelDefinesByType: public NGfc2RelDefines
{
public:
    NGfc2RelDefinesByType();
    NGfc2RelDefinesByType(void* pEntity, bool bOwner);
    void setRelatingType(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingType();
    bool hasRelatingType();
    NGfc2ElementType^ getRelatingTypePtr();
    int getRelatingElementCount();
    void clearRelatingElement();
    void addRelatingElement(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRelatingElement(int nIndex);
    NGfc2Element^ getRelatingElementPtr(int nIndex);

};
#endif
