#ifndef GFC2CYLINDERSHAPE_H
#define GFC2CYLINDERSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2PrimitiveShape.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CylinderShape: public Gfc2PrimitiveShape
{
OBJECTBUF_DEC_OBJECT(Gfc2CylinderShape,glodon::objectbuf::Entity)
public:
    Gfc2CylinderShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setHeight(const Gfc2Double& dValue)
    {
        m_dHeight = dValue;
        setHasHeight();
    }
    Gfc2Double getHeight() const {return m_dHeight;}
    bool hasHeight() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasHeight() {_has_bits_[0] |= 0x4u;}
    void setHasRadius() {_has_bits_[0] |= 0x8u;}

    Gfc2Double m_dHeight;
    Gfc2Double m_dRadius;
};
#endif
