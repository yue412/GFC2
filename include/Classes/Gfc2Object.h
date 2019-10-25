#ifndef GFC2OBJECT_H
#define GFC2OBJECT_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Root.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Object: public Gfc2Root
{
OBJECTBUF_DEC_OBJECT(Gfc2Object,glodon::objectbuf::Entity)
public:
    Gfc2Object();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setID(const Gfc2Identity& sValue)
    {
        m_sID = sValue;
        setHasID();
    }
    Gfc2Identity getID() const {return m_sID;}
    bool hasID() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setName(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nName = nValue;
        setHasName();
    }
    glodon::objectbuf::EntityRef getName() const {return m_nName;}
    bool hasName() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Label* getNamePtr() const {return (Gfc2Label*)m_pDocument->find(getName());}

private:
    void setHasID() {_has_bits_[0] |= 0x1u;}
    void setHasName() {_has_bits_[0] |= 0x2u;}

    Gfc2Identity m_sID;
    glodon::objectbuf::EntityRef m_nName;
};
#endif
