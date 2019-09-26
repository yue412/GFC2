#ifndef NGFC2FACEARCHINFO_H
#define NGFC2FACEARCHINFO_H

#include "NGfc2FaceInfo.h"
#include "Gfc2FaceArchInfo.h"
#include "NGfc2Line2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2FaceArchInfo: public NGfc2FaceInfo
{
public:
    NGfc2FaceArchInfo();
    NGfc2FaceArchInfo(void* pEntity, bool bOwner);
    void setAxialLine(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getAxialLine();
    bool hasAxialLine();
    NGfc2Line2d^ getAxialLinePtr();
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setChord(NGfc2Double dValue);
    NGfc2Double getChord();
    bool hasChord();
    void setCheckInnerChord(NGfc2Boolean bValue);
    NGfc2Boolean getCheckInnerChord();
    bool hasCheckInnerChord();

};
#endif
