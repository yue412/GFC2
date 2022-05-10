#ifndef GFCPARAMETERIZEDSECTION_H
#define GFCPARAMETERIZEDSECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSection.h"
#include "GfcClasses/x3/GfcCoordinates2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcParameterizedSection: public GfcSection
{
GFCENGINE_DEC_OBJECT(GfcParameterizedSection, gfc::engine::CEntity)
public:
    GfcParameterizedSection();
    GfcParameterizedSection(bool bSetSchema);
    void setPosition(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPosition() const;
    bool hasPosition() const;
    std::shared_ptr<GfcCoordinates2d> getPositionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
