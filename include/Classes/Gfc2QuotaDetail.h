#ifndef GFC2QUOTADETAIL_H
#define GFC2QUOTADETAIL_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2QuotaDetail: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2QuotaDetail,glodon::objectbuf::Entity)
public:
    Gfc2QuotaDetail();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setFloorNum(const Gfc2Integer& nValue)
    {
        m_nFloorNum = nValue;
        setHasFloorNum();
    }
    Gfc2Integer getFloorNum() const {return m_nFloorNum;}
    bool hasFloorNum() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setEntityID(const Gfc2Integer& nValue)
    {
        m_nEntityID = nValue;
        setHasEntityID();
    }
    Gfc2Integer getEntityID() const {return m_nEntityID;}
    bool hasEntityID() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setUnit(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nUnit = nValue;
        setHasUnit();
    }
    glodon::objectbuf::EntityRef getUnit() const {return m_nUnit;}
    bool hasUnit() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2String* getUnitPtr() const {return (Gfc2String*)m_pDocument->find(getUnit());}
    void setExpress(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nExpress = nValue;
        setHasExpress();
    }
    glodon::objectbuf::EntityRef getExpress() const {return m_nExpress;}
    bool hasExpress() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2String* getExpressPtr() const {return (Gfc2String*)m_pDocument->find(getExpress());}
    void setQuantity(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nQuantity = nValue;
        setHasQuantity();
    }
    glodon::objectbuf::EntityRef getQuantity() const {return m_nQuantity;}
    bool hasQuantity() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2String* getQuantityPtr() const {return (Gfc2String*)m_pDocument->find(getQuantity());}
    void setMemo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nMemo = nValue;
        setHasMemo();
    }
    glodon::objectbuf::EntityRef getMemo() const {return m_nMemo;}
    bool hasMemo() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2String* getMemoPtr() const {return (Gfc2String*)m_pDocument->find(getMemo());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasFloorNum() {_has_bits_[0] |= 0x1u;}
    void setHasEntityID() {_has_bits_[0] |= 0x2u;}
    void setHasUnit() {_has_bits_[0] |= 0x4u;}
    void setHasExpress() {_has_bits_[0] |= 0x8u;}
    void setHasQuantity() {_has_bits_[0] |= 0x10u;}
    void setHasMemo() {_has_bits_[0] |= 0x20u;}

    Gfc2Integer m_nFloorNum;
    Gfc2Integer m_nEntityID;
    glodon::objectbuf::EntityRef m_nUnit;
    glodon::objectbuf::EntityRef m_nExpress;
    glodon::objectbuf::EntityRef m_nQuantity;
    glodon::objectbuf::EntityRef m_nMemo;
};
#endif
