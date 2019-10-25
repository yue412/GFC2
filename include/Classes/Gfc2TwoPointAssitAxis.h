#ifndef GFC2TWOPOINTASSITAXIS_H
#define GFC2TWOPOINTASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AssitAxis.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2TwoPointAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2TwoPointAssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2TwoPointAssitAxis();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setStartPt(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nStartPt = nValue;
        setHasStartPt();
    }
    glodon::objectbuf::EntityRef getStartPt() const {return m_nStartPt;}
    bool hasStartPt() const {return (_has_bits_[0] & 0x100u) != 0;}
    Gfc2Vector2d* getStartPtPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getStartPt());}
    void setEndPt(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nEndPt = nValue;
        setHasEndPt();
    }
    glodon::objectbuf::EntityRef getEndPt() const {return m_nEndPt;}
    bool hasEndPt() const {return (_has_bits_[0] & 0x200u) != 0;}
    Gfc2Vector2d* getEndPtPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getEndPt());}

private:
    void setHasStartPt() {_has_bits_[0] |= 0x100u;}
    void setHasEndPt() {_has_bits_[0] |= 0x200u;}

    glodon::objectbuf::EntityRef m_nStartPt;
    glodon::objectbuf::EntityRef m_nEndPt;
};
#endif
