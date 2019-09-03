#ifndef GFC2SINCURVE2D_H
#define GFC2SINCURVE2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Intervald.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2SinCurve2d: public Gfc2Curve2d
{
OBJECTBUF_DEC_OBJECT(Gfc2SinCurve2d,glodon::objectbuf::Entity)
public:
    Gfc2SinCurve2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPos(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPos = nValue;
        setHasPos();
    }
    glodon::objectbuf::EntityRef getPos() const {return m_nPos;}
    bool hasPos() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector2d* getPosPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getPos());}
    void setDirX(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirX = nValue;
        setHasDirX();
    }
    glodon::objectbuf::EntityRef getDirX() const {return m_nDirX;}
    bool hasDirX() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector2d* getDirXPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getDirX());}
    void setA(const Gfc2Double& dValue)
    {
        m_dA = dValue;
        setHasA();
    }
    Gfc2Double getA() const {return m_dA;}
    bool hasA() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setB(const Gfc2Double& dValue)
    {
        m_dB = dValue;
        setHasB();
    }
    Gfc2Double getB() const {return m_dB;}
    bool hasB() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setRange(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRange = nValue;
        setHasRange();
    }
    glodon::objectbuf::EntityRef getRange() const {return m_nRange;}
    bool hasRange() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Intervald* getRangePtr() const {return (Gfc2Intervald*)m_pDocument->find(getRange());}
    void setClockSign(const Gfc2Integer& nValue)
    {
        m_nClockSign = nValue;
        setHasClockSign();
    }
    Gfc2Integer getClockSign() const {return m_nClockSign;}
    bool hasClockSign() const {return (_has_bits_[0] & 0x20u) != 0;}

private:
    void setHasPos() {_has_bits_[0] |= 0x1u;}
    void setHasDirX() {_has_bits_[0] |= 0x2u;}
    void setHasA() {_has_bits_[0] |= 0x4u;}
    void setHasB() {_has_bits_[0] |= 0x8u;}
    void setHasRange() {_has_bits_[0] |= 0x10u;}
    void setHasClockSign() {_has_bits_[0] |= 0x20u;}

    glodon::objectbuf::EntityRef m_nPos;
    glodon::objectbuf::EntityRef m_nDirX;
    Gfc2Double m_dA;
    Gfc2Double m_dB;
    glodon::objectbuf::EntityRef m_nRange;
    Gfc2Integer m_nClockSign;
};

class GFCCLASSES_API Gfc2SinCurve2dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SinCurve2dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
