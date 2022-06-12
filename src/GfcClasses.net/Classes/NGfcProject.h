#ifndef NGFCPROJECT_H
#define NGFCPROJECT_H

#include "NGfcObject.h"
#include "GfcClasses\x3\GfcProject.h"

public ref class NGfcProject: public NGfcObject
{
public:
    NGfcProject();
    NGfcProject(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
