#ifndef GFC2PROPERTY_H
#define GFC2PROPERTY_H

#include "GfcClasses.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Property: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2Property, gfc::engine::CEntity)
public:
    Gfc2Property();
    Gfc2Property(bool bSetSchema);
    void setName(const Gfc2Label& sValue);
    Gfc2Label getName() const;
    bool hasName() const;
    void setCode(const Gfc2String& sValue);
    Gfc2String getCode() const;
    bool hasCode() const;
    void setExtension(const Gfc2String& sValue);
    Gfc2String getExtension() const;
    bool hasExtension() const;

};
#endif
