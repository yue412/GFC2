#ifndef NGFC2EXTRUDEDBODY_H
#define NGFC2EXTRUDEDBODY_H

#include "NGfc2PrimitiveBody.h"
#include "GfcClasses\x3\Gfc2ExtrudedBody.h"
#include "NGfc2Coordinates3d.h"
#include "NGfc2Polygon.h"
#include "NTypeDef.h"

public ref class NGfc2ExtrudedBody: public NGfc2PrimitiveBody
{
public:
    NGfc2ExtrudedBody();
    NGfc2ExtrudedBody(void* pEntity, bool bOwner);
    void setCoordinate(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoordinate();
    bool hasCoordinate();
    void setLen(NGfc2Double dValue);
    NGfc2Double getLen();
    bool hasLen();
    void setSection(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSection();
    bool hasSection();

};
#endif
