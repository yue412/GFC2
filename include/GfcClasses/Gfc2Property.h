#ifndef GFC2PROPERTY_H
#define GFC2PROPERTY_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Property: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2Property, gfc::engine::CEntity)
public:
    Gfc2Property();
    Gfc2Property(bool bSetSchema);
    void setName(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getName() const;
    bool hasName() const;
    gfc::engine::CEntityWrapPtr<Gfc2Label> getNamePtr();
    void setCode(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCode() const;
    bool hasCode() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getCodePtr();

};
#endif
