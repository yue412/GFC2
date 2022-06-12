#ifndef NGFCEXTRUDEDBODY_H
#define NGFCEXTRUDEDBODY_H

#include "NGfcPrimitiveBody.h"
#include "GfcClasses\x3\GfcExtrudedBody.h"
#include "NGfcCoordinates3d.h"
#include "NGfcPolygon.h"
#include "NTypeDef.h"

public ref class NGfcExtrudedBody: public NGfcPrimitiveBody
{
public:
    NGfcExtrudedBody();
    NGfcExtrudedBody(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCoordinate(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCoordinate();
    bool hasCoordinate();
    void setLen(NGfcDouble dValue);
    NGfcDouble getLen();
    bool hasLen();
    void setSection(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSection();
    bool hasSection();

};
#endif
