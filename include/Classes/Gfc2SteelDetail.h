#ifndef GFC2STEELDETAIL_H
#define GFC2STEELDETAIL_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2SteelDetail: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2SteelDetail,glodon::objectbuf::Entity)
public:
    Gfc2SteelDetail();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setEntityID(const Gfc2Integer& nValue)
    {
        m_nEntityID = nValue;
        setHasEntityID();
    }
    Gfc2Integer getEntityID() const {return m_nEntityID;}
    bool hasEntityID() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setName(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nName = nValue;
        setHasName();
    }
    glodon::objectbuf::EntityRef getName() const {return m_nName;}
    bool hasName() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2String* getNamePtr() const {return (Gfc2String*)m_pDocument->find(getName());}
    void setDesc(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDesc = nValue;
        setHasDesc();
    }
    glodon::objectbuf::EntityRef getDesc() const {return m_nDesc;}
    bool hasDesc() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2String* getDescPtr() const {return (Gfc2String*)m_pDocument->find(getDesc());}
    void setLevel(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nLevel = nValue;
        setHasLevel();
    }
    glodon::objectbuf::EntityRef getLevel() const {return m_nLevel;}
    bool hasLevel() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2String* getLevelPtr() const {return (Gfc2String*)m_pDocument->find(getLevel());}
    void setDia(const Gfc2Integer& nValue)
    {
        m_nDia = nValue;
        setHasDia();
    }
    Gfc2Integer getDia() const {return m_nDia;}
    bool hasDia() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setNum(const Gfc2Integer& nValue)
    {
        m_nNum = nValue;
        setHasNum();
    }
    Gfc2Integer getNum() const {return m_nNum;}
    bool hasNum() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setLength(const Gfc2Integer& nValue)
    {
        m_nLength = nValue;
        setHasLength();
    }
    Gfc2Integer getLength() const {return m_nLength;}
    bool hasLength() const {return (_has_bits_[0] & 0x40u) != 0;}
    void setSingleWeight(const Gfc2Double& dValue)
    {
        m_dSingleWeight = dValue;
        setHasSingleWeight();
    }
    Gfc2Double getSingleWeight() const {return m_dSingleWeight;}
    bool hasSingleWeight() const {return (_has_bits_[0] & 0x80u) != 0;}
    void setTotalWeight(const Gfc2Double& dValue)
    {
        m_dTotalWeight = dValue;
        setHasTotalWeight();
    }
    Gfc2Double getTotalWeight() const {return m_dTotalWeight;}
    bool hasTotalWeight() const {return (_has_bits_[0] & 0x100u) != 0;}
    void setTieinNum(const Gfc2Integer& nValue)
    {
        m_nTieinNum = nValue;
        setHasTieinNum();
    }
    Gfc2Integer getTieinNum() const {return m_nTieinNum;}
    bool hasTieinNum() const {return (_has_bits_[0] & 0x200u) != 0;}
    void setTieinType(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nTieinType = nValue;
        setHasTieinType();
    }
    glodon::objectbuf::EntityRef getTieinType() const {return m_nTieinType;}
    bool hasTieinType() const {return (_has_bits_[0] & 0x400u) != 0;}
    Gfc2String* getTieinTypePtr() const {return (Gfc2String*)m_pDocument->find(getTieinType());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasEntityID() {_has_bits_[0] |= 0x1u;}
    void setHasName() {_has_bits_[0] |= 0x2u;}
    void setHasDesc() {_has_bits_[0] |= 0x4u;}
    void setHasLevel() {_has_bits_[0] |= 0x8u;}
    void setHasDia() {_has_bits_[0] |= 0x10u;}
    void setHasNum() {_has_bits_[0] |= 0x20u;}
    void setHasLength() {_has_bits_[0] |= 0x40u;}
    void setHasSingleWeight() {_has_bits_[0] |= 0x80u;}
    void setHasTotalWeight() {_has_bits_[0] |= 0x100u;}
    void setHasTieinNum() {_has_bits_[0] |= 0x200u;}
    void setHasTieinType() {_has_bits_[0] |= 0x400u;}

    Gfc2Integer m_nEntityID;
    glodon::objectbuf::EntityRef m_nName;
    glodon::objectbuf::EntityRef m_nDesc;
    glodon::objectbuf::EntityRef m_nLevel;
    Gfc2Integer m_nDia;
    Gfc2Integer m_nNum;
    Gfc2Integer m_nLength;
    Gfc2Double m_dSingleWeight;
    Gfc2Double m_dTotalWeight;
    Gfc2Integer m_nTieinNum;
    glodon::objectbuf::EntityRef m_nTieinType;
};

class GFCCLASSES_API Gfc2SteelDetailFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SteelDetailFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
