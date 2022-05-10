#ifndef GFCSECTION_H
#define GFCSECTION_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSection: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcSection, gfc::engine::CEntity)
public:
    GfcSection();
    GfcSection(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
