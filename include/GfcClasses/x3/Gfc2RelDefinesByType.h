#ifndef GFC2RELDEFINESBYTYPE_H
#define GFC2RELDEFINESBYTYPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RelDefines.h"
#include "GfcClasses/x3/Gfc2ElementType.h"
#include "GfcClasses/x3/Gfc2Element.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RelDefinesByType: public Gfc2RelDefines
{
GFCENGINE_DEC_OBJECT(Gfc2RelDefinesByType, gfc::engine::CEntity)
public:
    Gfc2RelDefinesByType();
    Gfc2RelDefinesByType(bool bSetSchema);
    void setRelatingType(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingType() const;
    bool hasRelatingType() const;
    std::shared_ptr<Gfc2ElementType> getRelatingTypePtr();
    int getRelatingElementCount() const;
    void clearRelatingElement();
    void addRelatingElement(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRelatingElement(int nIndex) const;
    std::shared_ptr<Gfc2Element> getRelatingElementPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
