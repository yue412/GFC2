#ifndef GFC2OBJECT_H
#define GFC2OBJECT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Object: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2Object, gfc::engine::CEntity)
public:
    Gfc2Object();
    Gfc2Object(bool bSetSchema);
    void setID(const Gfc2Identity& sValue);
    Gfc2Identity getID() const;
    bool hasID() const;
    void setName(const Gfc2Label& sValue);
    Gfc2Label getName() const;
    bool hasName() const;

};

GFCCLASSES_NAMESPACE_END

#endif
