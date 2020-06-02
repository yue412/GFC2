#ifndef GFC2INDEXEDCOLOURMAP_H
#define GFC2INDEXEDCOLOURMAP_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Color.h"
#include "Gfc2PrimitiveRenderable.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2IndexedColourMap: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2IndexedColourMap,gfc2::engine::EntityFactory)
public:
    Gfc2IndexedColourMap();
    Gfc2IndexedColourMap(bool bSetSchema);
    void setTransparency(const Gfc2Double& dValue);
    Gfc2Double getTransparency() const;
    bool hasTransparency() const;
    int getColoursCount() const;
    void clearColours();
    void addColours(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getColours(int nIndex) const;
    std::shared_ptr<Gfc2Color> getColoursPtr(int nIndex);
    int getColourIndexCount() const;
    void clearColourIndex();
    void addColourIndex(const Gfc2Integer& nValue);
    Gfc2Integer getColourIndex(int nIndex) const;
    void setMappedTo(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getMappedTo() const;
    bool hasMappedTo() const;
    std::shared_ptr<Gfc2PrimitiveRenderable> getMappedToPtr();

};
#endif
