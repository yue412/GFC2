#ifndef NGFCPARAMETERIZEDSECTION_H
#define NGFCPARAMETERIZEDSECTION_H

#include "NGfcSection.h"
#include "GfcClasses\x3\GfcParameterizedSection.h"
#include "NGfcCoordinates2d.h"

public ref class NGfcParameterizedSection: public NGfcSection
{
public:
    NGfcParameterizedSection();
    NGfcParameterizedSection(gfc::engine::CEntity* pEntity, bool bOwner);
    void setPosition(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPosition();
    bool hasPosition();

};
#endif
