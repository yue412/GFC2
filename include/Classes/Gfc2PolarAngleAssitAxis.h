#ifndef GFC2POLARANGLEASSITAXIS_H
#define GFC2POLARANGLEASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AssitAxis.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2PolarAngleAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2PolarAngleAssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2PolarAngleAssitAxis();
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
    void setAngle(const Gfc2Double& dValue)
    {
        m_dAngle = dValue;
        setHasAngle();
    }
    Gfc2Double getAngle() const {return m_dAngle;}
    bool hasAngle() const {return (_has_bits_[0] & 0x200u) != 0;}
    void setRefAxisIndex(const Gfc2Integer& nValue)
    {
        m_nRefAxisIndex = nValue;
        setHasRefAxisIndex();
    }
    Gfc2Integer getRefAxisIndex() const {return m_nRefAxisIndex;}
    bool hasRefAxisIndex() const {return (_has_bits_[0] & 0x400u) != 0;}

private:
    void setHasRefAxisNo() {_has_bits_[0] |= 0x100u;}
    void setHasAngle() {_has_bits_[0] |= 0x200u;}
    void setHasRefAxisIndex() {_has_bits_[0] |= 0x400u;}

    glodon::objectbuf::EntityRef m_nRefAxisNo;
    Gfc2Double m_dAngle;
    Gfc2Integer m_nRefAxisIndex;
};

class GFCCLASSES_API Gfc2PolarAngleAssitAxisFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PolarAngleAssitAxisFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
