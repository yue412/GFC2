#ifndef GFC2STRINGPROPERTY_H
#define GFC2STRINGPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SingleProperty.h"
#include "Gfc2String.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2StringProperty: public Gfc2SingleProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2StringProperty,glodon::objectbuf::Entity)
public:
    Gfc2StringProperty();
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
    Gfc2String* getValuePtr() const {return (Gfc2String*)m_pDocument->find(getValue());}

private:
    void setHasValue() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nValue;
};
#endif
