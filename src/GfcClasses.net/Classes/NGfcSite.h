#ifndef NGFCSITE_H
#define NGFCSITE_H

#include "NGfcSpatialStructureElement.h"
#include "GfcClasses\x3\GfcSite.h"

public ref class NGfcSite: public NGfcSpatialStructureElement
{
public:
    NGfcSite();
    NGfcSite(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
