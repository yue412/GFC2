#ifndef GFC2INTERVALD_H
#define GFC2INTERVALD_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Geometry.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Intervald: public Gfc2Geometry
{
GFCENGINE_DEC_OBJECT(Gfc2Intervald, gfc::engine::CEntity)
public:
    Gfc2Intervald();
    Gfc2Intervald(bool bSetSchema);
    void setMin(const Gfc2Double& dValue);
    Gfc2Double getMin() const;
    bool hasMin() const;
    void setMax(const Gfc2Double& dValue);
    Gfc2Double getMax() const;
    bool hasMax() const;

};

GFCCLASSES_NAMESPACE_END

#endif
