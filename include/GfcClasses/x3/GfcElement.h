#ifndef GFCELEMENT_H
#define GFCELEMENT_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcObject.h"
#include "GfcClasses/x3/GfcRepresentation.h"
#include "GfcClasses/x3/GfcElementShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcElement: public GfcObject
{
GFCENGINE_DEC_OBJECT(GfcElement, gfc::engine::CEntity)
public:
    GfcElement();
    GfcElement(bool bSetSchema);
    void setEType(const GfcLabel& sValue);
    GfcLabel getEType() const;
    bool hasEType() const;
    int getRepresentationsCount() const;
    void clearRepresentations();
    void addRepresentations(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getRepresentations(int nIndex) const;
    std::shared_ptr<GfcRepresentation> getRepresentationsPtr(int nIndex);
    int getShapesCount() const;
    void clearShapes();
    void addShapes(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getShapes(int nIndex) const;
    std::shared_ptr<GfcElementShape> getShapesPtr(int nIndex);

};

GFCCLASSES_NAMESPACE_END

#endif
