#ifndef GFC2ELEMENT_H
#define GFC2ELEMENT_H

#include "GfcClasses.h"
#include "Gfc2Object.h"
#include "Gfc2Representation.h"
#include "Gfc2ElementShape.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

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
#endif
