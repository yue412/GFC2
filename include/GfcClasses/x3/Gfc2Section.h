#ifndef GFC2SECTION_H
#define GFC2SECTION_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2Root.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2Section: public Gfc2Root
{
GFCENGINE_DEC_OBJECT(Gfc2Section, gfc::engine::CEntity)
public:
    Gfc2Section();
    Gfc2Section(bool bSetSchema);

};

GFCCLASSES_NAMESPACE_END

#endif
