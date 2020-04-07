#ifndef GFC2SPHERESHAPE_H
#define GFC2SPHERESHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2PrimitiveShape.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SphereShape: public Gfc2PrimitiveShape
{
OBJECTBUF_DEC_OBJECT(Gfc2SphereShape,glodon::objectbuf::Entity)
public:
    Gfc2SphereShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x4u) != 0;}

private:
    void setHasRadius() {_has_bits_[0] |= 0x4u;}

    Gfc2Double m_dRadius;
};
#endif
