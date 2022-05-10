#ifndef GFCSIMPLEVERTEX_H
#define GFCSIMPLEVERTEX_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcTopology.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSimpleVertex: public GfcTopology
{
GFCENGINE_DEC_OBJECT(GfcSimpleVertex, gfc::engine::CEntity)
public:
    GfcSimpleVertex();
    GfcSimpleVertex(bool bSetSchema);
    void setPoint(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPoint() const;
    bool hasPoint() const;
    std::shared_ptr<GfcVector2d> getPointPtr();
    void setRadius(const GfcDouble& dValue);
    GfcDouble getRadius() const;
    bool hasRadius() const;
    void setArcType(const GfcArcType& nValue);
    GfcArcType getArcType() const;
    bool hasArcType() const;

};

GFCCLASSES_NAMESPACE_END

#endif
