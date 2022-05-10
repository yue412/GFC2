#ifndef GFCELEMENTTYPE_H
#define GFCELEMENTTYPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcObject.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcElementType: public GfcObject
{
GFCENGINE_DEC_OBJECT(GfcElementType, gfc::engine::CEntity)
public:
    GfcElementType();
    GfcElementType(bool bSetSchema);
    void setEType(const GfcLabel& sValue);
    GfcLabel getEType() const;
    bool hasEType() const;

};

GFCCLASSES_NAMESPACE_END

#endif
