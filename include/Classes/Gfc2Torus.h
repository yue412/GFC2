#ifndef GFC2TORUS_H
#define GFC2TORUS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Torus: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2Torus,glodon::objectbuf::Entity)
public:
    Gfc2Torus();
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
    Gfc2Coordinates3d* getCoordPtr() const {return (Gfc2Coordinates3d*)m_pDocument->find(getCoord());}
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setClockSign(const Gfc2Integer& nValue)
    {
        m_nClockSign = nValue;
        setHasClockSign();
    }
    Gfc2Integer getClockSign() const {return m_nClockSign;}
    bool hasClockSign() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setRangeV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeV = nValue;
        setHasRangeV();
    }
    glodon::objectbuf::EntityRef getRangeV() const {return m_nRangeV;}
    bool hasRangeV() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Intervald* getRangeVPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeV());}
    void setCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurve = nValue;
        setHasCurve();
    }
    glodon::objectbuf::EntityRef getCurve() const {return m_nCurve;}
    bool hasCurve() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Curve2d* getCurvePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getCurve());}

private:
    void setHasCoord() {_has_bits_[0] |= 0x1u;}
    void setHasRadius() {_has_bits_[0] |= 0x2u;}
    void setHasClockSign() {_has_bits_[0] |= 0x4u;}
    void setHasRangeV() {_has_bits_[0] |= 0x8u;}
    void setHasCurve() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nCoord;
    Gfc2Double m_dRadius;
    Gfc2Integer m_nClockSign;
    glodon::objectbuf::EntityRef m_nRangeV;
    glodon::objectbuf::EntityRef m_nCurve;
};
#endif
