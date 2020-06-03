#ifndef GFC2OBJECT_H
#define GFC2OBJECT_H

#include "GfcClasses.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Object: public gfc::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Object, gfc::engine::Entity)
public:
    Gfc2Object();
    Gfc2Object(bool bSetSchema);
    void setID(const Gfc2Identity& sValue);
    Gfc2Identity getID() const;
    bool hasID() const;
    void setName(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getName() const;
    bool hasName() const;
    std::shared_ptr<Gfc2Label> getNamePtr();

};
#endif
