#ifndef GFC2REPRESENTATION_H
#define GFC2REPRESENTATION_H

#include "GfcClasses.h"
#include "Gfc2RepresentationItem.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Representation: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2Representation, gfc::engine::CEntity)
public:
    Gfc2Representation();
    Gfc2Representation(bool bSetSchema);
    void setIdentifier(const Gfc2String& sValue);
    Gfc2String getIdentifier() const;
    bool hasIdentifier() const;
    int getitemsCount() const;
    void clearitems();
    void additems(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getitems(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2RepresentationItem> getitemsPtr(int nIndex);

};
#endif
