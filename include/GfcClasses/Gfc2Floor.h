#ifndef GFC2FLOOR_H
#define GFC2FLOOR_H

#include "GfcClasses.h"
#include "Gfc2SpatialStructureElement.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Floor: public Gfc2SpatialStructureElement
{
GFCENGINE_DEC_OBJECT(Gfc2Floor, gfc2::engine::Entity)
public:
    Gfc2Floor();
    Gfc2Floor(bool bSetSchema);
    void setHeight(const Gfc2Double& dValue);
    Gfc2Double getHeight() const;
    bool hasHeight() const;
    void setStdFloorCount(const Gfc2Integer& nValue);
    Gfc2Integer getStdFloorCount() const;
    bool hasStdFloorCount() const;
    void setStructuralElevation(const Gfc2Double& dValue);
    Gfc2Double getStructuralElevation() const;
    bool hasStructuralElevation() const;
    void setStartFloorNo(const Gfc2Integer& nValue);
    Gfc2Integer getStartFloorNo() const;
    bool hasStartFloorNo() const;
    void setRemark(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getRemark() const;
    bool hasRemark() const;
    std::shared_ptr<Gfc2Text> getRemarkPtr();

};
#endif
