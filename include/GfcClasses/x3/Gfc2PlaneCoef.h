#ifndef GFC2PLANECOEF_H
#define GFC2PLANECOEF_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2PlaneCoef: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2PlaneCoef, gfc::engine::CEntity)
public:
    Gfc2PlaneCoef();
    Gfc2PlaneCoef(bool bSetSchema);
    void setA(const Gfc2Double& dValue);
    Gfc2Double getA() const;
    bool hasA() const;
    void setB(const Gfc2Double& dValue);
    Gfc2Double getB() const;
    bool hasB() const;
    void setC(const Gfc2Double& dValue);
    Gfc2Double getC() const;
    bool hasC() const;
    void setD(const Gfc2Double& dValue);
    Gfc2Double getD() const;
    bool hasD() const;

};

GFCCLASSES_NAMESPACE_END

#endif
