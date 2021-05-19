#ifndef GFC2PROPERTY_H
#define GFC2PROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Property: public Gfc2Root
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

GFCCLASSES_NAMESPACE_END

#endif
