#ifndef GFC2ELEMENTTYPE_H
#define GFC2ELEMENTTYPE_H

#include "GfcClasses.h"
#include "Gfc2Object.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ElementType: public Gfc2Object
{
GFCENGINE_DEC_OBJECT(Gfc2ElementType, gfc::engine::CEntity)
public:
    Gfc2ElementType();
    Gfc2ElementType(bool bSetSchema);
    void setEType(const Gfc2Label& sValue);
    Gfc2Label getEType() const;
    bool hasEType() const;

};
#endif
