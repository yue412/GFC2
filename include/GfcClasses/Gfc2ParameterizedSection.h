#ifndef GFC2PARAMETERIZEDSECTION_H
#define GFC2PARAMETERIZEDSECTION_H

#include "GfcClasses.h"
#include "Gfc2Section.h"
#include "Gfc2Coordinates3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ParameterizedSection: public Gfc2Section
{
GFCENGINE_DEC_OBJECT(Gfc2ParameterizedSection, gfc::engine::CEntity)
public:
    Gfc2ParameterizedSection();
    Gfc2ParameterizedSection(bool bSetSchema);
    void setPosition(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getPosition() const;
    bool hasPosition() const;
    gfc::engine::CEntityWrapPtr<Gfc2Coordinates3d> getPositionPtr();

};
#endif
