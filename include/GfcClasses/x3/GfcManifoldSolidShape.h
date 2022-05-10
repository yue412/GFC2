#ifndef GFCMANIFOLDSOLIDSHAPE_H
#define GFCMANIFOLDSOLIDSHAPE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSolidShape.h"
#include "GfcClasses/x3/GfcBody.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcManifoldSolidShape: public GfcSolidShape
{
GFCENGINE_DEC_OBJECT(GfcManifoldSolidShape, gfc::engine::CEntity)
public:
    GfcManifoldSolidShape();
    GfcManifoldSolidShape(bool bSetSchema);
    void setBody(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBody() const;
    bool hasBody() const;
    std::shared_ptr<GfcBody> getBodyPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
