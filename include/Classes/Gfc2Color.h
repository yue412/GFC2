#ifndef GFC2COLOR_H
#define GFC2COLOR_H

#include "GfcClasses.h"
#include <vector>
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Color: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2Color,glodon::objectbuf::Entity)
public:
    Gfc2Color();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRed(const Gfc2Integer& nValue)
    {
        m_nRed = nValue;
        setHasRed();
    }
    Gfc2Integer getRed() const {return m_nRed;}
    bool hasRed() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setGreen(const Gfc2Integer& nValue)
    {
        m_nGreen = nValue;
        setHasGreen();
    }
    Gfc2Integer getGreen() const {return m_nGreen;}
    bool hasGreen() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setBlue(const Gfc2Integer& nValue)
    {
        m_nBlue = nValue;
        setHasBlue();
    }
    Gfc2Integer getBlue() const {return m_nBlue;}
    bool hasBlue() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setAlpha(const Gfc2Integer& nValue)
    {
        m_nAlpha = nValue;
        setHasAlpha();
    }
    Gfc2Integer getAlpha() const {return m_nAlpha;}
    bool hasAlpha() const {return (_has_bits_[0] & 0x8u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasRed() {_has_bits_[0] |= 0x1u;}
    void setHasGreen() {_has_bits_[0] |= 0x2u;}
    void setHasBlue() {_has_bits_[0] |= 0x4u;}
    void setHasAlpha() {_has_bits_[0] |= 0x8u;}

    Gfc2Integer m_nRed;
    Gfc2Integer m_nGreen;
    Gfc2Integer m_nBlue;
    Gfc2Integer m_nAlpha;
};
#endif
