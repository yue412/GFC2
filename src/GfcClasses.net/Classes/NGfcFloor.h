#ifndef NGFCFLOOR_H
#define NGFCFLOOR_H

#include "NGfcSpatialStructureElement.h"
#include "GfcClasses\x3\GfcFloor.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcFloor: public NGfcSpatialStructureElement
{
public:
    NGfcFloor();
    NGfcFloor(bool bNoCreate);
    void setHeight(NGfcDouble dValue);
    NGfcDouble getHeight();
    bool hasHeight();
    void setStdFloorCount(NGfcInteger nValue);
    NGfcInteger getStdFloorCount();
    bool hasStdFloorCount();
    void setStructuralElevation(NGfcDouble dValue);
    NGfcDouble getStructuralElevation();
    bool hasStructuralElevation();
    void setStartFloorNo(NGfcInteger nValue);
    NGfcInteger getStartFloorNo();
    bool hasStartFloorNo();
    void setRemark(NGfcText sValue);
    NGfcText getRemark();
    bool hasRemark();

};
#endif
