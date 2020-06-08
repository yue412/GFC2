#ifndef NGFC2ELLIPSE2D_H
#define NGFC2ELLIPSE2D_H

#include "NGfc2Curve2d.h"
#include "Gfc2Ellipse2d.h"
#include "NGfc2Vector2d.h"
#include "NGfc2Intervald.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Ellipse2d: public NGfc2Curve2d
{
public:
    NGfc2Ellipse2d();
    NGfc2Ellipse2d(void* pEntity, bool bOwner);
    void setCenterPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCenterPt();
    bool hasCenterPt();
    NGfc2Vector2d^ getCenterPtPtr();
    void setMajorAxis(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMajorAxis();
    bool hasMajorAxis();
    NGfc2Vector2d^ getMajorAxisPtr();
    void setdMajorRad(NGfc2Double dValue);
    NGfc2Double getdMajorRad();
    bool hasdMajorRad();
    void setdMinorRad(NGfc2Double dValue);
    NGfc2Double getdMinorRad();
    bool hasdMinorRad();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    NGfc2Intervald^ getRangePtr();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();

};
#endif
