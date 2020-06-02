#ifndef GFC2ELEMENTTYPE_H
#define GFC2ELEMENTTYPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Object.h"
#include "TypeDef.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ElementType: public Gfc2Object
{
GFCENGINE_DEC_OBJECT(Gfc2ElementType,gfc2::engine::EntityFactory)
public:
    Gfc2ElementType();
    Gfc2ElementType(bool bSetSchema);
    void setType(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getType() const;
    bool hasType() const;
    std::shared_ptr<Gfc2Label> getTypePtr();

};
#endif
