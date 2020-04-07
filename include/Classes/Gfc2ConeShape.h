#ifndef GFC2CONESHAPE_H
#define GFC2CONESHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2PrimitiveShape.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ConeShape: public Gfc2PrimitiveShape
{
OBJECTBUF_DEC_OBJECT(Gfc2ConeShape,glodon::objectbuf::Entity)
public:
    Gfc2ConeShape();
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
    void setBottomRadius(const Gfc2Double& dValue)
    {
        m_dBottomRadius = dValue;
        setHasBottomRadius();
    }
    Gfc2Double getBottomRadius() const {return m_dBottomRadius;}
    bool hasBottomRadius() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasHeight() {_has_bits_[0] |= 0x4u;}
    void setHasBottomRadius() {_has_bits_[0] |= 0x8u;}

    Gfc2Double m_dHeight;
    Gfc2Double m_dBottomRadius;
};
#endif
