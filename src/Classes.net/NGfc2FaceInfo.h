#ifndef NGFC2FACEINFO_H
#define NGFC2FACEINFO_H

#include "Gfc2FaceInfo.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2FaceInfo: public glodon::objectbufnet::Entity
{
public:
    NGfc2FaceInfo();
    NGfc2FaceInfo(void* pEntity, bool bOwner);

};
#endif
