#ifndef GFCINDEXEDCOLOURMAP_H
#define GFCINDEXEDCOLOURMAP_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/GfcColor.h"
#include "GfcClasses/x3/GfcTriangulatedFaceSet.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcIndexedColourMap: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcIndexedColourMap, gfc::engine::CEntity)
public:
    GfcIndexedColourMap();
    GfcIndexedColourMap(bool bSetSchema);
    void setOpacity(const GfcDouble& dValue);
    GfcDouble getOpacity() const;
    bool hasOpacity() const;
    void setColor(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getColor() const;
    bool hasColor() const;
    std::shared_ptr<GfcColor> getColorPtr();
    void setMappedTo(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getMappedTo() const;
    bool hasMappedTo() const;
    std::shared_ptr<GfcTriangulatedFaceSet> getMappedToPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
