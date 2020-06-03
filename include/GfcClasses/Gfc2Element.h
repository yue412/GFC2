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
GFCENGINE_DEC_OBJECT(Gfc2Element, gfc2::engine::Entity)
public:
    Gfc2Element();
    Gfc2Element(bool bSetSchema);
    void setType(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getType() const;
    bool hasType() const;
    std::shared_ptr<Gfc2Label> getTypePtr();
    int getRepresentationsCount() const;
    void clearRepresentations();
    void addRepresentations(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRepresentations(int nIndex) const;
    std::shared_ptr<Gfc2Representation> getRepresentationsPtr(int nIndex);
    int getShapesCount() const;
    void clearShapes();
    void addShapes(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getShapes(int nIndex) const;
    std::shared_ptr<Gfc2ElementShape> getShapesPtr(int nIndex);

};
#endif
