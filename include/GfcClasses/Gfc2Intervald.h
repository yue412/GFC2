#ifndef GFC2INTERVALD_H
#define GFC2INTERVALD_H

#include "GfcClasses.h"
#include "Gfc2Geometry.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

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
#endif
