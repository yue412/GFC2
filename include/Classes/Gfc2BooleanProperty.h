#ifndef GFC2BOOLEANPROPERTY_H
#define GFC2BOOLEANPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SingleProperty.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2BooleanProperty: public Gfc2SingleProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2BooleanProperty,glodon::objectbuf::Entity)
public:
    Gfc2BooleanProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setValue(const Gfc2Boolean& bValue)
    {
        m_bValue = bValue;
        setHasValue();
    }
    Gfc2Boolean getValue() const {return m_bValue;}
    bool hasValue() const {return (_has_bits_[0] & 0x2u) != 0;}

private:
    void setHasValue() {_has_bits_[0] |= 0x2u;}

    Gfc2Boolean m_bValue;
};
#endif
