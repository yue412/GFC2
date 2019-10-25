#ifndef GFC2STRING_H
#define GFC2STRING_H

#include "GfcClasses.h"
#include <vector>
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2String: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2String,glodon::objectbuf::Entity)
public:
    Gfc2String();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setValue(const std::string& sValue)
    {
        m_sValue = sValue;
        setHasValue();
    }
    std::string getValue() const {return m_sValue;}
    bool hasValue() const {return (_has_bits_[0] & 0x1u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasValue() {_has_bits_[0] |= 0x1u;}

    std::string m_sValue;
};
#endif
