#ifndef GFC2STEELTOTAL_H
#define GFC2STEELTOTAL_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SteelTotal: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2SteelTotal,glodon::objectbuf::Entity)
public:
    Gfc2SteelTotal();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCompType(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCompType = nValue;
        setHasCompType();
    }
    glodon::objectbuf::EntityRef getCompType() const {return m_nCompType;}
    bool hasCompType() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2String* getCompTypePtr() const {return (Gfc2String*)m_pDocument->find(getCompType());}
    void setLevel(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nLevel = nValue;
        setHasLevel();
    }
    glodon::objectbuf::EntityRef getLevel() const {return m_nLevel;}
    bool hasLevel() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2String* getLevelPtr() const {return (Gfc2String*)m_pDocument->find(getLevel());}
    void setDia(const Gfc2Integer& nValue)
    {
        m_nDia = nValue;
        setHasDia();
    }
    Gfc2Integer getDia() const {return m_nDia;}
    bool hasDia() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setWeight(const Gfc2Double& dValue)
    {
        m_dWeight = dValue;
        setHasWeight();
    }
    Gfc2Double getWeight() const {return m_dWeight;}
    bool hasWeight() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setUnit(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nUnit = nValue;
        setHasUnit();
    }
    glodon::objectbuf::EntityRef getUnit() const {return m_nUnit;}
    bool hasUnit() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2String* getUnitPtr() const {return (Gfc2String*)m_pDocument->find(getUnit());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasCompType() {_has_bits_[0] |= 0x1u;}
    void setHasLevel() {_has_bits_[0] |= 0x2u;}
    void setHasDia() {_has_bits_[0] |= 0x4u;}
    void setHasWeight() {_has_bits_[0] |= 0x8u;}
    void setHasUnit() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nCompType;
    glodon::objectbuf::EntityRef m_nLevel;
    Gfc2Integer m_nDia;
    Gfc2Double m_dWeight;
    glodon::objectbuf::EntityRef m_nUnit;
};
#endif
