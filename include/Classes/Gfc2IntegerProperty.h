#ifndef GFC2INTEGERPROPERTY_H
#define GFC2INTEGERPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SingleProperty.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2IntegerProperty: public Gfc2SingleProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2IntegerProperty,glodon::objectbuf::Entity)
public:
    Gfc2IntegerProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setValue(const Gfc2Integer& nValue)
    {
        m_nValue = nValue;
        setHasValue();
    }
    Gfc2Integer getValue() const {return m_nValue;}
    bool hasValue() const {return (_has_bits_[0] & 0x2u) != 0;}

private:
    void setHasValue() {_has_bits_[0] |= 0x2u;}

    Gfc2Integer m_nValue;
};
#endif
