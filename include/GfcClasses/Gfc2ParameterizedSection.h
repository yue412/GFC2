#ifndef GFC2PARAMETERIZEDSECTION_H
#define GFC2PARAMETERIZEDSECTION_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2Section.h"
#include "Gfc2Coordinates3d.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ParameterizedSection: public Gfc2Section
{
GFCENGINE_DEC_OBJECT(Gfc2ParameterizedSection,gfc2::engine::EntityFactory)
public:
    Gfc2ParameterizedSection();
    Gfc2ParameterizedSection(bool bSetSchema);
    void setPosition(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getPosition() const;
    bool hasPosition() const;
    std::shared_ptr<Gfc2Coordinates3d> getPositionPtr();

};
#endif
