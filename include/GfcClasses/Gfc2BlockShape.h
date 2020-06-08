#ifndef GFC2BLOCKSHAPE_H
#define GFC2BLOCKSHAPE_H

#include "GfcClasses.h"
#include "Gfc2PrimitiveShape.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BlockShape: public Gfc2PrimitiveShape
{
GFCENGINE_DEC_OBJECT(Gfc2BlockShape, gfc::engine::CEntity)
public:
    Gfc2BlockShape();
    Gfc2BlockShape(bool bSetSchema);
    void setXLength(const Gfc2Double& dValue);
    Gfc2Double getXLength() const;
    bool hasXLength() const;
    void setYLength(const Gfc2Double& dValue);
    Gfc2Double getYLength() const;
    bool hasYLength() const;
    void setZLength(const Gfc2Double& dValue);
    Gfc2Double getZLength() const;
    bool hasZLength() const;

};
#endif
