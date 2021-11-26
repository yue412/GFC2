#ifndef NGFC2FLOOR_H
#define NGFC2FLOOR_H

#include "NGfc2SpatialStructureElement.h"
#include "GfcClasses\x3\Gfc2Floor.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2Floor: public NGfc2SpatialStructureElement
{
public:
    NGfc2Floor();
    NGfc2Floor(gfc::engine::CEntity* pEntity, bool bOwner);
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setStdFloorCount(NGfc2Integer nValue);
    NGfc2Integer getStdFloorCount();
    bool hasStdFloorCount();
    void setStructuralElevation(NGfc2Double dValue);
    NGfc2Double getStructuralElevation();
    bool hasStructuralElevation();
    void setStartFloorNo(NGfc2Integer nValue);
    NGfc2Integer getStartFloorNo();
    bool hasStartFloorNo();
    void setRemark(NGfc2Text sValue);
    NGfc2Text getRemark();
    bool hasRemark();

};
#endif
