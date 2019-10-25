#ifndef GFC2PREIMAGECURVE2D_H
#define GFC2PREIMAGECURVE2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve2d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Surface.h"
#include "Gfc2Curve3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PreimageCurve2d: public Gfc2Curve2d
{
OBJECTBUF_DEC_OBJECT(Gfc2PreimageCurve2d,glodon::objectbuf::Entity)
public:
    Gfc2PreimageCurve2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRange(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRange = nValue;
        setHasRange();
    }
    glodon::objectbuf::EntityRef getRange() const {return m_nRange;}
    bool hasRange() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Intervald* getRangePtr() const {return (Gfc2Intervald*)m_pDocument->find(getRange());}
    void setReversed(const Gfc2Boolean& bValue)
    {
        m_bReversed = bValue;
        setHasReversed();
    }
    Gfc2Boolean getReversed() const {return m_bReversed;}
    bool hasReversed() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setBase(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBase = nValue;
        setHasBase();
    }
    glodon::objectbuf::EntityRef getBase() const {return m_nBase;}
    bool hasBase() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Surface* getBasePtr() const {return (Gfc2Surface*)m_pDocument->find(getBase());}
    void setCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurve = nValue;
        setHasCurve();
    }
    glodon::objectbuf::EntityRef getCurve() const {return m_nCurve;}
    bool hasCurve() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Curve3d* getCurvePtr() const {return (Gfc2Curve3d*)m_pDocument->find(getCurve());}
    void setTolerance(const Gfc2Double& dValue)
    {
        m_dTolerance = dValue;
        setHasTolerance();
    }
    Gfc2Double getTolerance() const {return m_dTolerance;}
    bool hasTolerance() const {return (_has_bits_[0] & 0x10u) != 0;}

private:
    void setHasRange() {_has_bits_[0] |= 0x1u;}
    void setHasReversed() {_has_bits_[0] |= 0x2u;}
    void setHasBase() {_has_bits_[0] |= 0x4u;}
    void setHasCurve() {_has_bits_[0] |= 0x8u;}
    void setHasTolerance() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nRange;
    Gfc2Boolean m_bReversed;
    glodon::objectbuf::EntityRef m_nBase;
    glodon::objectbuf::EntityRef m_nCurve;
    Gfc2Double m_dTolerance;
};
#endif
