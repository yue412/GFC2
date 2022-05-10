#ifndef GFCFLOOR_H
#define GFCFLOOR_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSpatialStructureElement.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcFloor: public GfcSpatialStructureElement
{
GFCENGINE_DEC_OBJECT(GfcFloor, gfc::engine::CEntity)
public:
    GfcFloor();
    GfcFloor(bool bSetSchema);
    void setHeight(const GfcDouble& dValue);
    GfcDouble getHeight() const;
    bool hasHeight() const;
    void setStdFloorCount(const GfcInteger& nValue);
    GfcInteger getStdFloorCount() const;
    bool hasStdFloorCount() const;
    void setStructuralElevation(const GfcDouble& dValue);
    GfcDouble getStructuralElevation() const;
    bool hasStructuralElevation() const;
    void setStartFloorNo(const GfcInteger& nValue);
    GfcInteger getStartFloorNo() const;
    bool hasStartFloorNo() const;
    void setRemark(const GfcText& sValue);
    GfcText getRemark() const;
    bool hasRemark() const;

};

GFCCLASSES_NAMESPACE_END

#endif
