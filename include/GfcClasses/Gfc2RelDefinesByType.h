#ifndef GFC2RELDEFINESBYTYPE_H
#define GFC2RELDEFINESBYTYPE_H

#include "GfcClasses.h"
#include "Gfc2RelDefines.h"
#include "Gfc2ElementType.h"
#include "Gfc2Element.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RelDefinesByType: public Gfc2RelDefines
{
GFCENGINE_DEC_OBJECT(Gfc2RelDefinesByType, gfc2::engine::Entity)
public:
    Gfc2RelDefinesByType();
    Gfc2RelDefinesByType(bool bSetSchema);
    void setRelatingType(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatingType() const;
    bool hasRelatingType() const;
    std::shared_ptr<Gfc2ElementType> getRelatingTypePtr();
    int getRelatingElementCount() const;
    void clearRelatingElement();
    void addRelatingElement(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRelatingElement(int nIndex) const;
    std::shared_ptr<Gfc2Element> getRelatingElementPtr(int nIndex);

};
#endif
