#ifndef GFC2STRING_H
#define GFC2STRING_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2String: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2String,gfc2::engine::EntityFactory)
public:
    Gfc2String();
    Gfc2String(bool bSetSchema);
    void setValue(const std::string& sValue);
    std::string getValue() const;
    bool hasValue() const;

};
#endif
