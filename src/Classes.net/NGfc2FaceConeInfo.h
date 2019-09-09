#ifndef NGFC2FACECONEINFO_H
#define NGFC2FACECONEINFO_H

#include "NGfc2FaceInfo.h"
#include "Gfc2FaceConeInfo.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2FaceConeInfo: public NGfc2FaceInfo
{
public:
    NGfc2FaceConeInfo();
    NGfc2FaceConeInfo(void* pEntity, bool bOwner);
    void setHeight(NGfc2Double dValue);
    NGfc2Double getHeight();
    bool hasHeight();
    void setChord(NGfc2Double dValue);
    NGfc2Double getChord();
    bool hasChord();
    void setCenterPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCenterPoint();
    bool hasCenterPoint();
    NGfc2Vector2d^ getCenterPointPtr();
    void setCheckInnerChord(NGfc2Boolean bValue);
    NGfc2Boolean getCheckInnerChord();
    bool hasCheckInnerChord();

};
#endif
