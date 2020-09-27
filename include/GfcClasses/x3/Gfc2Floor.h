#ifndef GFC2FLOOR_H
#define GFC2FLOOR_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SpatialStructureElement.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Floor: public Gfc2SpatialStructureElement
{
GFCENGINE_DEC_OBJECT(Gfc2Floor, gfc::engine::CEntity)
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
    void setRemark(const Gfc2Text& sValue);
    Gfc2Text getRemark() const;
    bool hasRemark() const;

};

GFCCLASSES_NAMESPACE_END

#endif
