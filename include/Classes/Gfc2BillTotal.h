#ifndef GFC2BILLTOTAL_H
#define GFC2BILLTOTAL_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2BillTotal: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2BillTotal,glodon::objectbuf::Entity)
public:
    Gfc2BillTotal();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCode(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCode = nValue;
        setHasCode();
    }
    glodon::objectbuf::EntityRef getCode() const {return m_nCode;}
    bool hasCode() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2String* getCodePtr() const {return (Gfc2String*)m_pDocument->find(getCode());}
    void setName(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nName = nValue;
        setHasName();
    }
    glodon::objectbuf::EntityRef getName() const {return m_nName;}
    bool hasName() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2String* getNamePtr() const {return (Gfc2String*)m_pDocument->find(getName());}
    void setAttr(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nAttr = nValue;
        setHasAttr();
    }
    glodon::objectbuf::EntityRef getAttr() const {return m_nAttr;}
    bool hasAttr() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2String* getAttrPtr() const {return (Gfc2String*)m_pDocument->find(getAttr());}
    void setQuantityType(const Gfc2Integer& nValue)
    {
        m_nQuantityType = nValue;
        setHasQuantityType();
    }
    Gfc2Integer getQuantityType() const {return m_nQuantityType;}
    bool hasQuantityType() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setUnit(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nUnit = nValue;
        setHasUnit();
    }
    glodon::objectbuf::EntityRef getUnit() const {return m_nUnit;}
    bool hasUnit() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2String* getUnitPtr() const {return (Gfc2String*)m_pDocument->find(getUnit());}
    void setQuantity(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nQuantity = nValue;
        setHasQuantity();
    }
    glodon::objectbuf::EntityRef getQuantity() const {return m_nQuantity;}
    bool hasQuantity() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2String* getQuantityPtr() const {return (Gfc2String*)m_pDocument->find(getQuantity());}
    void setMemo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nMemo = nValue;
        setHasMemo();
    }
    glodon::objectbuf::EntityRef getMemo() const {return m_nMemo;}
    bool hasMemo() const {return (_has_bits_[0] & 0x40u) != 0;}
    Gfc2String* getMemoPtr() const {return (Gfc2String*)m_pDocument->find(getMemo());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasCode() {_has_bits_[0] |= 0x1u;}
    void setHasName() {_has_bits_[0] |= 0x2u;}
    void setHasAttr() {_has_bits_[0] |= 0x4u;}
    void setHasQuantityType() {_has_bits_[0] |= 0x8u;}
    void setHasUnit() {_has_bits_[0] |= 0x10u;}
    void setHasQuantity() {_has_bits_[0] |= 0x20u;}
    void setHasMemo() {_has_bits_[0] |= 0x40u;}

    glodon::objectbuf::EntityRef m_nCode;
    glodon::objectbuf::EntityRef m_nName;
    glodon::objectbuf::EntityRef m_nAttr;
    Gfc2Integer m_nQuantityType;
    glodon::objectbuf::EntityRef m_nUnit;
    glodon::objectbuf::EntityRef m_nQuantity;
    glodon::objectbuf::EntityRef m_nMemo;
};

class GFCCLASSES_API Gfc2BillTotalFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2BillTotalFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
