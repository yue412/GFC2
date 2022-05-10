#ifndef GFCPROPERTY_H
#define GFCPROPERTY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcProperty: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcProperty, gfc::engine::CEntity)
public:
    GfcProperty();
    GfcProperty(bool bSetSchema);
    void setName(const GfcLabel& sValue);
    GfcLabel getName() const;
    bool hasName() const;
    void setCode(const GfcString& sValue);
    GfcString getCode() const;
    bool hasCode() const;
    void setExtension(const GfcString& sValue);
    GfcString getExtension() const;
    bool hasExtension() const;

};

GFCCLASSES_NAMESPACE_END

#endif
