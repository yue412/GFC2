#ifndef GFC2ELEMENTTYPE_H
#define GFC2ELEMENTTYPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Object.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ElementType: public Gfc2Object
{
OBJECTBUF_DEC_OBJECT(Gfc2ElementType,glodon::objectbuf::Entity)
public:
    Gfc2ElementType();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setType(const Gfc2Integer& nValue)
    {
        m_nType = nValue;
        setHasType();
    }
    Gfc2Integer getType() const {return m_nType;}
    bool hasType() const {return (_has_bits_[0] & 0x4u) != 0;}

private:
    void setHasType() {_has_bits_[0] |= 0x4u;}

    Gfc2Integer m_nType;
};
#endif
