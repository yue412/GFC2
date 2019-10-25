#ifndef GFC2ARC2D_H
#define GFC2ARC2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Intervald.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Arc2d: public Gfc2Curve2d
{
OBJECTBUF_DEC_OBJECT(Gfc2Arc2d,glodon::objectbuf::Entity)
public:
    Gfc2Arc2d();
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

private:
    void setHasCenterPt() {_has_bits_[0] |= 0x1u;}
    void setHasRadius() {_has_bits_[0] |= 0x2u;}
    void setHasRange() {_has_bits_[0] |= 0x4u;}
    void setHasClockSign() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nCenterPt;
    Gfc2Double m_dRadius;
    glodon::objectbuf::EntityRef m_nRange;
    Gfc2Integer m_nClockSign;
};
#endif
