#ifndef GFCOBJECT_H
#define GFCOBJECT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcObject: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcObject, gfc::engine::CEntity)
public:
    GfcObject();
    GfcObject(bool bSetSchema);
    void setID(const GfcIdentity& sValue);
    GfcIdentity getID() const;
    bool hasID() const;
    void setName(const GfcLabel& sValue);
    GfcLabel getName() const;
    bool hasName() const;

};

GFCCLASSES_NAMESPACE_END

#endif
