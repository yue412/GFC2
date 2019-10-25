#ifndef GFC2LINESHAPE_H
#define GFC2LINESHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2CustomLineShape.h"
#include "Gfc2LineArcInfo.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2LineShape: public Gfc2CustomLineShape
{
OBJECTBUF_DEC_OBJECT(Gfc2LineShape,glodon::objectbuf::Entity)
public:
    Gfc2LineShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setTilt(const Gfc2Double& dValue)
    {
        m_dTilt = dValue;
        setHasTilt();
    }
    Gfc2Double getTilt() const {return m_dTilt;}
    bool hasTilt() const {return (_has_bits_[0] & 0x100u) != 0;}
    void setStartPtHeight(const Gfc2Double& dValue)
    {
        m_dStartPtHeight = dValue;
        setHasStartPtHeight();
    }
    Gfc2Double getStartPtHeight() const {return m_dStartPtHeight;}
    bool hasStartPtHeight() const {return (_has_bits_[0] & 0x200u) != 0;}
    void setEndPtHeight(const Gfc2Double& dValue)
    {
        m_dEndPtHeight = dValue;
        setHasEndPtHeight();
    }
    Gfc2Double getEndPtHeight() const {return m_dEndPtHeight;}
    bool hasEndPtHeight() const {return (_has_bits_[0] & 0x400u) != 0;}
    void setArcInfo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nArcInfo = nValue;
        setHasArcInfo();
    }
    glodon::objectbuf::EntityRef getArcInfo() const {return m_nArcInfo;}
    bool hasArcInfo() const {return (_has_bits_[0] & 0x800u) != 0;}
    Gfc2LineArcInfo* getArcInfoPtr() const {return (Gfc2LineArcInfo*)m_pDocument->find(getArcInfo());}
    void setIsSpiralTop(const Gfc2Boolean& bValue)
    {
        m_bIsSpiralTop = bValue;
        setHasIsSpiralTop();
    }
    Gfc2Boolean getIsSpiralTop() const {return m_bIsSpiralTop;}
    bool hasIsSpiralTop() const {return (_has_bits_[0] & 0x1000u) != 0;}
    void setIsSpiralBtm(const Gfc2Boolean& bValue)
    {
        m_bIsSpiralBtm = bValue;
        setHasIsSpiralBtm();
    }
    Gfc2Boolean getIsSpiralBtm() const {return m_bIsSpiralBtm;}
    bool hasIsSpiralBtm() const {return (_has_bits_[0] & 0x2000u) != 0;}

private:
    void setHasTilt() {_has_bits_[0] |= 0x100u;}
    void setHasStartPtHeight() {_has_bits_[0] |= 0x200u;}
    void setHasEndPtHeight() {_has_bits_[0] |= 0x400u;}
    void setHasArcInfo() {_has_bits_[0] |= 0x800u;}
    void setHasIsSpiralTop() {_has_bits_[0] |= 0x1000u;}
    void setHasIsSpiralBtm() {_has_bits_[0] |= 0x2000u;}

    Gfc2Double m_dTilt;
    Gfc2Double m_dStartPtHeight;
    Gfc2Double m_dEndPtHeight;
    glodon::objectbuf::EntityRef m_nArcInfo;
    Gfc2Boolean m_bIsSpiralTop;
    Gfc2Boolean m_bIsSpiralBtm;
};
#endif
