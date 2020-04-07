#ifndef NGFC2PARAMETERIZEDSECTION_H
#define NGFC2PARAMETERIZEDSECTION_H

#include "NGfc2Section.h"
#include "Gfc2ParameterizedSection.h"
#include "NGfc2Coordinates3d.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ParameterizedSection: public NGfc2Section
{
public:
    NGfc2ParameterizedSection();
    NGfc2ParameterizedSection(void* pEntity, bool bOwner);
    void setPosition(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getPosition();
    bool hasPosition();
    NGfc2Coordinates3d^ getPositionPtr();

};
#endif
