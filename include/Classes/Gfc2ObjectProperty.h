#ifndef GFC2OBJECTPROPERTY_H
#define GFC2OBJECTPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Property.h"
#include "Gfc2Object.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ObjectProperty: public Gfc2Property
{
OBJECTBUF_DEC_OBJECT(Gfc2ObjectProperty,glodon::objectbuf::Entity)
public:
    Gfc2ObjectProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setValue(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nValue = nValue;
        setHasValue();
    }
    glodon::objectbuf::EntityRef getValue() const {return m_nValue;}
    bool hasValue() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Object* getValuePtr() const {return (Gfc2Object*)m_pDocument->find(getValue());}

private:
    void setHasValue() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nValue;
};
#endif
