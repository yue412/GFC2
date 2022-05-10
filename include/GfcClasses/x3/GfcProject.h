#ifndef GFCPROJECT_H
#define GFCPROJECT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcObject.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcProject: public GfcObject
{
GFCENGINE_DEC_OBJECT(GfcProject, gfc::engine::CEntity)
public:
    GfcProject();
    GfcProject(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
