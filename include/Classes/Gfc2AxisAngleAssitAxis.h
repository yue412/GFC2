#ifndef GFC2AXISANGLEASSITAXIS_H
#define GFC2AXISANGLEASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AssitAxis.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2AxisAngleAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2AxisAngleAssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2AxisAngleAssitAxis();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRefAxisNo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRefAxisNo = nValue;
        setHasRefAxisNo();
    }
    glodon::objectbuf::EntityRef getRefAxisNo() const {return m_nRefAxisNo;}
    bool hasRefAxisNo() const {return (_has_bits_[0] & 0x100u) != 0;}
    Gfc2Label* getRefAxisNoPtr() const {return (Gfc2Label*)m_pDocument->find(getRefAxisNo());}
    void setRefPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRefPoint = nValue;
        setHasRefPoint();
    }
    glodon::objectbuf::EntityRef getRefPoint() const {return m_nRefPoint;}
    bool hasRefPoint() const {return (_has_bits_[0] & 0x200u) != 0;}
    Gfc2Vector2d* getRefPointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getRefPoint());}
    void setAngle(const Gfc2Double& dValue)
    {
        m_dAngle = dValue;
        setHasAngle();
    }
    Gfc2Double getAngle() const {return m_dAngle;}
    bool hasAngle() const {return (_has_bits_[0] & 0x400u) != 0;}
    void setRefAxisIndex(const Gfc2Integer& nValue)
    {
        m_nRefAxisIndex = nValue;
        setHasRefAxisIndex();
    }
    Gfc2Integer getRefAxisIndex() const {return m_nRefAxisIndex;}
    bool hasRefAxisIndex() const {return (_has_bits_[0] & 0x800u) != 0;}
    void setRefAxisType(const Gfc2AxisType& nValue)
    {
        m_nRefAxisType = nValue;
        setHasRefAxisType();
    }
    Gfc2AxisType getRefAxisType() const {return m_nRefAxisType;}
    bool hasRefAxisType() const {return (_has_bits_[0] & 0x1000u) != 0;}

private:
    void setHasRefAxisNo() {_has_bits_[0] |= 0x100u;}
    void setHasRefPoint() {_has_bits_[0] |= 0x200u;}
    void setHasAngle() {_has_bits_[0] |= 0x400u;}
    void setHasRefAxisIndex() {_has_bits_[0] |= 0x800u;}
    void setHasRefAxisType() {_has_bits_[0] |= 0x1000u;}

    glodon::objectbuf::EntityRef m_nRefAxisNo;
    glodon::objectbuf::EntityRef m_nRefPoint;
    Gfc2Double m_dAngle;
    Gfc2Integer m_nRefAxisIndex;
    Gfc2AxisType m_nRefAxisType;
};

class GFCCLASSES_API Gfc2AxisAngleAssitAxisFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2AxisAngleAssitAxisFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
