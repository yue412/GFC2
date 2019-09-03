#ifndef GFC2ELLIPSE2D_H
#define GFC2ELLIPSE2D_H

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

class GFCCLASSES_API Gfc2Ellipse2d: public Gfc2Curve2d
{
OBJECTBUF_DEC_OBJECT(Gfc2Ellipse2d,glodon::objectbuf::Entity)
public:
    Gfc2Ellipse2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCenterPt(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCenterPt = nValue;
        setHasCenterPt();
    }
    glodon::objectbuf::EntityRef getCenterPt() const {return m_nCenterPt;}
    bool hasCenterPt() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector2d* getCenterPtPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getCenterPt());}
    void setMajorAxis(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nMajorAxis = nValue;
        setHasMajorAxis();
    }
    glodon::objectbuf::EntityRef getMajorAxis() const {return m_nMajorAxis;}
    bool hasMajorAxis() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector2d* getMajorAxisPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getMajorAxis());}
    void setdMajorRad(const Gfc2Double& dValue)
    {
        m_ddMajorRad = dValue;
        setHasdMajorRad();
    }
    Gfc2Double getdMajorRad() const {return m_ddMajorRad;}
    bool hasdMajorRad() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setdMinorRad(const Gfc2Double& dValue)
    {
        m_ddMinorRad = dValue;
        setHasdMinorRad();
    }
    Gfc2Double getdMinorRad() const {return m_ddMinorRad;}
    bool hasdMinorRad() const {return (_has_bits_[0] & 0x8u) != 0;}
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
    void setHasCenterPt() {_has_bits_[0] |= 0x1u;}
    void setHasMajorAxis() {_has_bits_[0] |= 0x2u;}
    void setHasdMajorRad() {_has_bits_[0] |= 0x4u;}
    void setHasdMinorRad() {_has_bits_[0] |= 0x8u;}
    void setHasRange() {_has_bits_[0] |= 0x10u;}
    void setHasClockSign() {_has_bits_[0] |= 0x20u;}

    glodon::objectbuf::EntityRef m_nCenterPt;
    glodon::objectbuf::EntityRef m_nMajorAxis;
    Gfc2Double m_ddMajorRad;
    Gfc2Double m_ddMinorRad;
    glodon::objectbuf::EntityRef m_nRange;
    Gfc2Integer m_nClockSign;
};

class GFCCLASSES_API Gfc2Ellipse2dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Ellipse2dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
