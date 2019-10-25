#ifndef GFC2SPIRALLINE2D_H
#define GFC2SPIRALLINE2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve2d.h"
#include "Gfc2Coordinates2d.h"
#include "Gfc2Intervald.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SpiralLine2d: public Gfc2Curve2d
{
OBJECTBUF_DEC_OBJECT(Gfc2SpiralLine2d,glodon::objectbuf::Entity)
public:
    Gfc2SpiralLine2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCoord(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCoord = nValue;
        setHasCoord();
    }
    glodon::objectbuf::EntityRef getCoord() const {return m_nCoord;}
    bool hasCoord() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Coordinates2d* getCoordPtr() const {return (Gfc2Coordinates2d*)m_pDocument->find(getCoord());}
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setRange(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRange = nValue;
        setHasRange();
    }
    glodon::objectbuf::EntityRef getRange() const {return m_nRange;}
    bool hasRange() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Intervald* getRangePtr() const {return (Gfc2Intervald*)m_pDocument->find(getRange());}
    void setClockSign(const Gfc2Integer& nValue)
    {
        m_nClockSign = nValue;
        setHasClockSign();
    }
    Gfc2Integer getClockSign() const {return m_nClockSign;}
    bool hasClockSign() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setRadiusCoef(const Gfc2Double& dValue)
    {
        m_dRadiusCoef = dValue;
        setHasRadiusCoef();
    }
    Gfc2Double getRadiusCoef() const {return m_dRadiusCoef;}
    bool hasRadiusCoef() const {return (_has_bits_[0] & 0x10u) != 0;}

private:
    void setHasCoord() {_has_bits_[0] |= 0x1u;}
    void setHasRadius() {_has_bits_[0] |= 0x2u;}
    void setHasRange() {_has_bits_[0] |= 0x4u;}
    void setHasClockSign() {_has_bits_[0] |= 0x8u;}
    void setHasRadiusCoef() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nCoord;
    Gfc2Double m_dRadius;
    glodon::objectbuf::EntityRef m_nRange;
    Gfc2Integer m_nClockSign;
    Gfc2Double m_dRadiusCoef;
};
#endif
