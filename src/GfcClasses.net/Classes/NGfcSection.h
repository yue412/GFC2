#ifndef NGFCSECTION_H
#define NGFCSECTION_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcSection.h"

public ref class NGfcSection: public NGfcEntity
{
public:
    NGfcSection();
    NGfcSection(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
