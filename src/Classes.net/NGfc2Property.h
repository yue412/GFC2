#ifndef NGFC2PROPERTY_H
#define NGFC2PROPERTY_H

#include "Gfc2Property.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Property: public glodon::objectbufnet::Entity
{
public:
    NGfc2Property();
    NGfc2Property(void* pEntity, bool bOwner);
    void setName(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getName();
    bool hasName();
    NGfc2Label^ getNamePtr();
    void setCode(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCode();
    bool hasCode();
    NGfc2String^ getCodePtr();

};
#endif
