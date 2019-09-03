#ifndef GFC2HELICOID_H
#define GFC2HELICOID_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Helicoid: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2Helicoid,glodon::objectbuf::Entity)
public:
    Gfc2Helicoid();
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
    void setRangeV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeV = nValue;
        setHasRangeV();
    }
    glodon::objectbuf::EntityRef getRangeV() const {return m_nRangeV;}
    bool hasRangeV() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Intervald* getRangeVPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeV());}
    void setClockSign(const Gfc2Integer& nValue)
    {
        m_nClockSign = nValue;
        setHasClockSign();
    }
    Gfc2Integer getClockSign() const {return m_nClockSign;}
    bool hasClockSign() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setHeightCoef(const Gfc2Double& dValue)
    {
        m_dHeightCoef = dValue;
        setHasHeightCoef();
    }
    Gfc2Double getHeightCoef() const {return m_dHeightCoef;}
    bool hasHeightCoef() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setRadiusCoef(const Gfc2Double& dValue)
    {
        m_dRadiusCoef = dValue;
        setHasRadiusCoef();
    }
    Gfc2Double getRadiusCoef() const {return m_dRadiusCoef;}
    bool hasRadiusCoef() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurve = nValue;
        setHasCurve();
    }
    glodon::objectbuf::EntityRef getCurve() const {return m_nCurve;}
    bool hasCurve() const {return (_has_bits_[0] & 0x40u) != 0;}
    Gfc2Curve2d* getCurvePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getCurve());}

private:
    void setHasCoord() {_has_bits_[0] |= 0x1u;}
    void setHasRadius() {_has_bits_[0] |= 0x2u;}
    void setHasRangeV() {_has_bits_[0] |= 0x4u;}
    void setHasClockSign() {_has_bits_[0] |= 0x8u;}
    void setHasHeightCoef() {_has_bits_[0] |= 0x10u;}
    void setHasRadiusCoef() {_has_bits_[0] |= 0x20u;}
    void setHasCurve() {_has_bits_[0] |= 0x40u;}

    glodon::objectbuf::EntityRef m_nCoord;
    Gfc2Double m_dRadius;
    glodon::objectbuf::EntityRef m_nRangeV;
    Gfc2Integer m_nClockSign;
    Gfc2Double m_dHeightCoef;
    Gfc2Double m_dRadiusCoef;
    glodon::objectbuf::EntityRef m_nCurve;
};

class GFCCLASSES_API Gfc2HelicoidFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2HelicoidFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
