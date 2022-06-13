#ifndef NGFCMANIFOLDSOLIDSHAPE_H
#define NGFCMANIFOLDSOLIDSHAPE_H

#include "NGfcSolidShape.h"
#include "GfcClasses\x3\GfcManifoldSolidShape.h"
#include "NGfcBody.h"

public ref class NGfcManifoldSolidShape: public NGfcSolidShape
{
public:
    NGfcManifoldSolidShape();
    NGfcManifoldSolidShape(bool bNoCreate);
    void setBody(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getBody();
    bool hasBody();

};
#endif
