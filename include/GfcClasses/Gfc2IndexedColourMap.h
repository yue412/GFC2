#ifndef GFC2INDEXEDCOLOURMAP_H
#define GFC2INDEXEDCOLOURMAP_H

#include "GfcClasses.h"
#include "Gfc2Color.h"
#include "Gfc2PrimitiveRenderable.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2IndexedColourMap: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2IndexedColourMap, gfc::engine::CEntity)
public:
    Gfc2IndexedColourMap();
    Gfc2IndexedColourMap(bool bSetSchema);
    void setTransparency(const Gfc2Double& dValue);
    Gfc2Double getTransparency() const;
    bool hasTransparency() const;
    int getColoursCount() const;
    void clearColours();
    void addColours(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getColours(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Color> getColoursPtr(int nIndex);
    int getColourIndexCount() const;
    void clearColourIndex();
    void addColourIndex(const Gfc2Integer& nValue);
    Gfc2Integer getColourIndex(int nIndex) const;
    void setMappedTo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMappedTo() const;
    bool hasMappedTo() const;
    gfc::engine::CEntityWrapPtr<Gfc2PrimitiveRenderable> getMappedToPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
