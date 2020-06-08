#ifndef GFC2STRING_H
#define GFC2STRING_H

#include "GfcClasses.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2String: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2String, gfc::engine::CEntity)
public:
    Gfc2String();
    Gfc2String(bool bSetSchema);
    void setValue(const std::string& sValue);
    std::string getValue() const;
    bool hasValue() const;

};
#endif
