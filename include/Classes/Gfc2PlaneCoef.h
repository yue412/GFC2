#ifndef GFC2PLANECOEF_H
#define GFC2PLANECOEF_H

#include "GfcClasses.h"
#include <vector>
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2PlaneCoef: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2PlaneCoef,glodon::objectbuf::Entity)
public:
    Gfc2PlaneCoef();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setA(const Gfc2Double& dValue)
    {
        m_dA = dValue;
        setHasA();
    }
    Gfc2Double getA() const {return m_dA;}
    bool hasA() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setB(const Gfc2Double& dValue)
    {
        m_dB = dValue;
        setHasB();
    }
    Gfc2Double getB() const {return m_dB;}
    bool hasB() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setC(const Gfc2Double& dValue)
    {
        m_dC = dValue;
        setHasC();
    }
    Gfc2Double getC() const {return m_dC;}
    bool hasC() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setD(const Gfc2Double& dValue)
    {
        m_dD = dValue;
        setHasD();
    }
    Gfc2Double getD() const {return m_dD;}
    bool hasD() const {return (_has_bits_[0] & 0x8u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasA() {_has_bits_[0] |= 0x1u;}
    void setHasB() {_has_bits_[0] |= 0x2u;}
    void setHasC() {_has_bits_[0] |= 0x4u;}
    void setHasD() {_has_bits_[0] |= 0x8u;}

    Gfc2Double m_dA;
    Gfc2Double m_dB;
    Gfc2Double m_dC;
    Gfc2Double m_dD;
};

class GFCCLASSES_API Gfc2PlaneCoefFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PlaneCoefFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
