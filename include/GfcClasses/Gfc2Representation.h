#ifndef GFC2REPRESENTATION_H
#define GFC2REPRESENTATION_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "Gfc2RepresentationItem.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Representation: public gfc::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Representation, gfc::engine::Entity)
public:
    Gfc2Representation();
    Gfc2Representation(bool bSetSchema);
    void setIdentifier(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getIdentifier() const;
    bool hasIdentifier() const;
    std::shared_ptr<Gfc2String> getIdentifierPtr();
    int getitemsCount() const;
    void clearitems();
    void additems(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getitems(int nIndex) const;
    std::shared_ptr<Gfc2RepresentationItem> getitemsPtr(int nIndex);

};
#endif
