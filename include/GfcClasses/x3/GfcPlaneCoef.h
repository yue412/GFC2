#ifndef GFCPLANECOEF_H
#define GFCPLANECOEF_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcRoot.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcPlaneCoef: public GfcRoot
{
GFCENGINE_DEC_OBJECT(GfcPlaneCoef, gfc::engine::CEntity)
public:
    GfcPlaneCoef();
    GfcPlaneCoef(bool bSetSchema);
    void setA(const GfcDouble& dValue);
    GfcDouble getA() const;
    bool hasA() const;
    void setB(const GfcDouble& dValue);
    GfcDouble getB() const;
    bool hasB() const;
    void setC(const GfcDouble& dValue);
    GfcDouble getC() const;
    bool hasC() const;
    void setD(const GfcDouble& dValue);
    GfcDouble getD() const;
    bool hasD() const;

};

GFCCLASSES_NAMESPACE_END

#endif
