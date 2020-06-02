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
    void setName(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getName();
    bool hasName();
    NGfc2Label^ getNamePtr();
    void setCode(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getCode();
    bool hasCode();
    NGfc2String^ getCodePtr();

};
#endif
