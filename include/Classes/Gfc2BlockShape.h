#ifndef GFC2BLOCKSHAPE_H
#define GFC2BLOCKSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2PrimitiveShape.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2BlockShape: public Gfc2PrimitiveShape
{
OBJECTBUF_DEC_OBJECT(Gfc2BlockShape,glodon::objectbuf::Entity)
public:
    Gfc2BlockShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setXLength(const Gfc2Double& dValue)
    {
        m_dXLength = dValue;
        setHasXLength();
    }
    Gfc2Double getXLength() const {return m_dXLength;}
    bool hasXLength() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setYLength(const Gfc2Double& dValue)
    {
        m_dYLength = dValue;
        setHasYLength();
    }
    Gfc2Double getYLength() const {return m_dYLength;}
    bool hasYLength() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setZLength(const Gfc2Double& dValue)
    {
        m_dZLength = dValue;
        setHasZLength();
    }
    Gfc2Double getZLength() const {return m_dZLength;}
    bool hasZLength() const {return (_has_bits_[0] & 0x10u) != 0;}

private:
    void setHasXLength() {_has_bits_[0] |= 0x4u;}
    void setHasYLength() {_has_bits_[0] |= 0x8u;}
    void setHasZLength() {_has_bits_[0] |= 0x10u;}

    Gfc2Double m_dXLength;
    Gfc2Double m_dYLength;
    Gfc2Double m_dZLength;
};
#endif
