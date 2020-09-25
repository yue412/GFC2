#ifndef GFC2ELEMENT_H
#define GFC2ELEMENT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Object.h"
#include "GfcClasses/x3/Gfc2Representation.h"
#include "GfcClasses/x3/Gfc2ElementShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Element: public Gfc2Object
{
GFCENGINE_DEC_OBJECT(Gfc2Element, gfc::engine::CEntity)
public:
    Gfc2Element();
    Gfc2Element(bool bSetSchema);
    void setEType(const Gfc2Label& sValue);
    Gfc2Label getEType() const;
    bool hasEType() const;
    int getRepresentationsCount() const;
    void clearRepresentations();
    void addRepresentations(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRepresentations(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2Representation> getRepresentationsPtr(int nIndex);
    int getShapesCount() const;
    void clearShapes();
    void addShapes(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getShapes(int nIndex) const;
    gfc::engine::CEntityWrapPtr<Gfc2ElementShape> getShapesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
