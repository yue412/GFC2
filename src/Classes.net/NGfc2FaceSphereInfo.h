#ifndef NGFC2FACESPHEREINFO_H
#define NGFC2FACESPHEREINFO_H

#include "NGfc2FaceInfo.h"
#include "Gfc2FaceSphereInfo.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2FaceSphereInfo: public NGfc2FaceInfo
{
public:
    NGfc2FaceSphereInfo();
    NGfc2FaceSphereInfo(void* pEntity, bool bOwner);
    void setCenterPoint(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCenterPoint();
    bool hasCenterPoint();
    NGfc2Vector2d^ getCenterPointPtr();
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
