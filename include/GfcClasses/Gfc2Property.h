#ifndef GFC2PROPERTY_H
#define GFC2PROPERTY_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Property: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Property, gfc2::engine::Entity)
public:
    Gfc2Property();
    Gfc2Property(bool bSetSchema);
    void setName(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getName() const;
    bool hasName() const;
    std::shared_ptr<Gfc2Label> getNamePtr();
    void setCode(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getCode() const;
    bool hasCode() const;
    std::shared_ptr<Gfc2String> getCodePtr();

};
#endif
