#ifndef GFCREPRESENTATION_H
#define GFCREPRESENTATION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcRepresentationItem.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRepresentation: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcRepresentation, gfc::engine::CEntity)
public:
    GfcRepresentation();
    GfcRepresentation(bool bSetSchema);
    void setIdentifier(const GfcString& sValue);
    GfcString getIdentifier() const;
    bool hasIdentifier() const;
    int getitemsCount() const;
    void clearitems();
    void additems(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getitems(int nIndex) const;
    std::shared_ptr<GfcRepresentationItem> getitemsPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
