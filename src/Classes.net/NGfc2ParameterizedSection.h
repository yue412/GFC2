#ifndef NGFC2PARAMETERIZEDSECTION_H
#define NGFC2PARAMETERIZEDSECTION_H

#include "NGfc2Section.h"
#include "Gfc2ParameterizedSection.h"
#include "NGfc2Coordinates2d.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ParameterizedSection: public NGfc2Section
{
public:
    NGfc2ParameterizedSection();
    NGfc2ParameterizedSection(void* pEntity, bool bOwner);
    void setPosition(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPosition();
    bool hasPosition();
    NGfc2Coordinates2d^ getPositionPtr();

};
#endif
