#ifndef GFCINDEXEDCOLOURMAP_H
#define GFCINDEXEDCOLOURMAP_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/GfcColor.h"
#include "GfcClasses/x3/GfcPrimitiveRenderable.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcIndexedColourMap: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcIndexedColourMap, gfc::engine::CEntity)
public:
    GfcIndexedColourMap();
    GfcIndexedColourMap(bool bSetSchema);
    void setTransparency(const GfcDouble& dValue);
    GfcDouble getTransparency() const;
    bool hasTransparency() const;
    int getColoursCount() const;
    void clearColours();
    void addColours(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getColours(int nIndex) const;
    std::shared_ptr<GfcColor> getColoursPtr(int nIndex);
    int getColourIndexCount() const;
    void clearColourIndex();
    void addColourIndex(const GfcInteger& nValue);
    GfcInteger getColourIndex(int nIndex) const;
    void setMappedTo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMappedTo() const;
    bool hasMappedTo() const;
    std::shared_ptr<GfcPrimitiveRenderable> getMappedToPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
