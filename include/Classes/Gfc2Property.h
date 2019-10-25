#ifndef GFC2PROPERTY_H
#define GFC2PROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Property: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2Property,glodon::objectbuf::Entity)
public:
    Gfc2Property();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setName(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nName = nValue;
        setHasName();
    }
    glodon::objectbuf::EntityRef getName() const {return m_nName;}
    bool hasName() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Label* getNamePtr() const {return (Gfc2Label*)m_pDocument->find(getName());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasName() {_has_bits_[0] |= 0x1u;}

    glodon::objectbuf::EntityRef m_nName;
};
#endif
