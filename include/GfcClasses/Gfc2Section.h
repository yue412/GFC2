#ifndef GFC2SECTION_H
#define GFC2SECTION_H

#include "GfcClasses.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2Section: public gfc::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2Section, gfc::engine::Entity)
public:
    Gfc2Section();
    Gfc2Section(bool bSetSchema);

};
#endif
