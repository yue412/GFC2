#include "StdAfx.h"
#include "NGfc2FaceInfo.h"
NGfc2FaceInfo::NGfc2FaceInfo()
{
    m_pEntity = new Gfc2FaceInfo;
    m_bOwner = true;
}

NGfc2FaceInfo::NGfc2FaceInfo(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

