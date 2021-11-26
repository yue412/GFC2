#ifndef NGFC2ELLIPSE2D_H
#define NGFC2ELLIPSE2D_H

#include "NGfc2Curve2d.h"
#include "GfcClasses\x3\Gfc2Ellipse2d.h"
#include "NGfc2Vector2d.h"
#include "NGfc2Intervald.h"
#include "NTypeDef.h"

public ref class NGfc2Ellipse2d: public NGfc2Curve2d
{
public:
    NGfc2Ellipse2d();
    NGfc2Ellipse2d(void* pEntity, bool bOwner);
    void setCenterPt(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCenterPt();
    bool hasCenterPt();
    void setMajorAxis(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getMajorAxis();
    bool hasMajorAxis();
    void setdMajorRad(NGfc2Double dValue);
    NGfc2Double getdMajorRad();
    bool hasdMajorRad();
    void setdMinorRad(NGfc2Double dValue);
    NGfc2Double getdMinorRad();
    bool hasdMinorRad();
    void setRange(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRange();
    bool hasRange();
    void setClockSign(NGfc2Integer nValue);
    NGfc2Integer getClockSign();
    bool hasClockSign();

};
#endif
