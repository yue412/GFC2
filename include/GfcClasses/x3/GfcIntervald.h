#ifndef GFCINTERVALD_H
#define GFCINTERVALD_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcGeometry.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcIntervald: public GfcGeometry
{
GFCENGINE_DEC_OBJECT(GfcIntervald, gfc::engine::CEntity)
public:
    GfcIntervald();
    GfcIntervald(bool bSetSchema);
    void setMin(const GfcDouble& dValue);
    GfcDouble getMin() const;
    bool hasMin() const;
    void setMax(const GfcDouble& dValue);
    GfcDouble getMax() const;
    bool hasMax() const;

};

GFCCLASSES_NAMESPACE_END

#endif
