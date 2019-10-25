#ifndef GFC2RELDEFINESBYELEMENT_H
#define GFC2RELDEFINESBYELEMENT_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelDefines.h"
#include "Gfc2Entity.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelDefinesByElement: public Gfc2RelDefines
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefinesByElement,glodon::objectbuf::Entity)
public:
    Gfc2RelDefinesByElement();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRelatingElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRelatingElement = nValue;
        setHasRelatingElement();
    }
    glodon::objectbuf::EntityRef getRelatingElement() const {return m_nRelatingElement;}
    bool hasRelatingElement() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Entity* getRelatingElementPtr() const {return (Gfc2Entity*)m_pDocument->find(getRelatingElement());}

private:
    void setHasRelatingElement() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nRelatingElement;
};
#endif
