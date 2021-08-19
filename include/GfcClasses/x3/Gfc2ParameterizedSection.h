#ifndef GFC2PARAMETERIZEDSECTION_H
#define GFC2PARAMETERIZEDSECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Section.h"
#include "GfcClasses/x3/Gfc2Coordinates2d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ParameterizedSection: public Gfc2Section
{
GFCENGINE_DEC_OBJECT(Gfc2ParameterizedSection, gfc::engine::CEntity)
public:
    Gfc2ParameterizedSection();
    Gfc2ParameterizedSection(bool bSetSchema);
    void setPosition(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPosition() const;
    bool hasPosition() const;
    std::shared_ptr<Gfc2Coordinates2d> getPositionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
