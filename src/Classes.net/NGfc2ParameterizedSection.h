#ifndef NGFC2PARAMETERIZEDSECTION_H
#define NGFC2PARAMETERIZEDSECTION_H

#include "NGfc2Section.h"
#include "Gfc2ParameterizedSection.h"
#include "NGfc2Coordinates3d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ParameterizedSection: public NGfc2Section
{
public:
    NGfc2ParameterizedSection();
    NGfc2ParameterizedSection(void* pEntity, bool bOwner);
    void setPosition(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getPosition();
    bool hasPosition();
    NGfc2Coordinates3d^ getPositionPtr();

};
#endif
