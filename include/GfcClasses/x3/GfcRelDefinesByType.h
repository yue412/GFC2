#ifndef GFCRELDEFINESBYTYPE_H
#define GFCRELDEFINESBYTYPE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRelDefines.h"
#include "GfcClasses/x3/GfcElementType.h"
#include "GfcClasses/x3/GfcElement.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRelDefinesByType: public GfcRelDefines
{
GFCENGINE_DEC_OBJECT(GfcRelDefinesByType, gfc::engine::CEntity)
public:
    GfcRelDefinesByType();
    GfcRelDefinesByType(bool bSetSchema);
    void setRelatingType(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingType() const;
    bool hasRelatingType() const;
    std::shared_ptr<GfcElementType> getRelatingTypePtr();
    int getRelatingElementCount() const;
    void clearRelatingElement();
    void addRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingElement(int nIndex) const;
    std::shared_ptr<GfcElement> getRelatingElementPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
