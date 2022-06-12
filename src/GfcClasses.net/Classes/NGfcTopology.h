#ifndef NGFCTOPOLOGY_H
#define NGFCTOPOLOGY_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcTopology.h"

public ref class NGfcTopology: public NGfcGeometry
{
public:
    NGfcTopology();
    NGfcTopology(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
