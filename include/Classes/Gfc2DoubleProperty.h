#ifndef GFC2DOUBLEPROPERTY_H
#define GFC2DOUBLEPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Property.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2DoubleProperty: public Gfc2Property
{
OBJECTBUF_DEC_OBJECT(Gfc2DoubleProperty,glodon::objectbuf::Entity)
public:
    Gfc2DoubleProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setValue(const Gfc2Double& dValue)
    {
        m_dValue = dValue;
        setHasValue();
    }
    Gfc2Double getValue() const {return m_dValue;}
    bool hasValue() const {return (_has_bits_[0] & 0x2u) != 0;}

private:
    void setHasValue() {_has_bits_[0] |= 0x2u;}

    Gfc2Double m_dValue;
};
#endif
