#ifndef GFC2POINTSHAPE2D_H
#define GFC2POINTSHAPE2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Shape2d.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PointShape2d: public Gfc2Shape2d
{
OBJECTBUF_DEC_OBJECT(Gfc2PointShape2d,glodon::objectbuf::Entity)
public:
    Gfc2PointShape2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setInsertPt(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nInsertPt = nValue;
        setHasInsertPt();
    }
    glodon::objectbuf::EntityRef getInsertPt() const {return m_nInsertPt;}
    bool hasInsertPt() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Vector2d* getInsertPtPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getInsertPt());}
    void setAngle(const Gfc2Double& dValue)
    {
        m_dAngle = dValue;
        setHasAngle();
    }
    Gfc2Double getAngle() const {return m_dAngle;}
    bool hasAngle() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setMirrorFlag(const Gfc2Boolean& bValue)
    {
        m_bMirrorFlag = bValue;
        setHasMirrorFlag();
    }
    Gfc2Boolean getMirrorFlag() const {return m_bMirrorFlag;}
    bool hasMirrorFlag() const {return (_has_bits_[0] & 0x20u) != 0;}

private:
    void setHasInsertPt() {_has_bits_[0] |= 0x8u;}
    void setHasAngle() {_has_bits_[0] |= 0x10u;}
    void setHasMirrorFlag() {_has_bits_[0] |= 0x20u;}

    glodon::objectbuf::EntityRef m_nInsertPt;
    Gfc2Double m_dAngle;
    Gfc2Boolean m_bMirrorFlag;
};
#endif
