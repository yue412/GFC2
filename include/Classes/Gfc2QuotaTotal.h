#ifndef GFC2QUOTATOTAL_H
#define GFC2QUOTATOTAL_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2QuotaTotal: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2QuotaTotal,glodon::objectbuf::Entity)
public:
    Gfc2QuotaTotal();
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
    void setSubCode(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSubCode = nValue;
        setHasSubCode();
    }
    glodon::objectbuf::EntityRef getSubCode() const {return m_nSubCode;}
    bool hasSubCode() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2String* getSubCodePtr() const {return (Gfc2String*)m_pDocument->find(getSubCode());}
    void setName(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nName = nValue;
        setHasName();
    }
    glodon::objectbuf::EntityRef getName() const {return m_nName;}
    bool hasName() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2String* getNamePtr() const {return (Gfc2String*)m_pDocument->find(getName());}
    void setContent(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nContent = nValue;
        setHasContent();
    }
    glodon::objectbuf::EntityRef getContent() const {return m_nContent;}
    bool hasContent() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2String* getContentPtr() const {return (Gfc2String*)m_pDocument->find(getContent());}
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
    void setHasSubCode() {_has_bits_[0] |= 0x2u;}
    void setHasName() {_has_bits_[0] |= 0x4u;}
    void setHasContent() {_has_bits_[0] |= 0x8u;}
    void setHasUnit() {_has_bits_[0] |= 0x10u;}
    void setHasQuantity() {_has_bits_[0] |= 0x20u;}
    void setHasMemo() {_has_bits_[0] |= 0x40u;}

    glodon::objectbuf::EntityRef m_nCode;
    glodon::objectbuf::EntityRef m_nSubCode;
    glodon::objectbuf::EntityRef m_nName;
    glodon::objectbuf::EntityRef m_nContent;
    glodon::objectbuf::EntityRef m_nUnit;
    glodon::objectbuf::EntityRef m_nQuantity;
    glodon::objectbuf::EntityRef m_nMemo;
};
#endif
