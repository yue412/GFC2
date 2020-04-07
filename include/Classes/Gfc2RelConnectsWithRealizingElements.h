#ifndef GFC2RELCONNECTSWITHREALIZINGELEMENTS_H
#define GFC2RELCONNECTSWITHREALIZINGELEMENTS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelConnectsElements.h"
#include "Gfc2Element.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelConnectsWithRealizingElements: public Gfc2RelConnectsElements
{
OBJECTBUF_DEC_OBJECT(Gfc2RelConnectsWithRealizingElements,glodon::objectbuf::Entity)
public:
    Gfc2RelConnectsWithRealizingElements();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRealizingElements(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRealizingElements = nValue;
        setHasRealizingElements();
    }
    glodon::objectbuf::EntityRef getRealizingElements() const {return m_nRealizingElements;}
    bool hasRealizingElements() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Element* getRealizingElementsPtr() const {return (Gfc2Element*)m_pDocument->find(getRealizingElements());}

private:
    void setHasRealizingElements() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nRealizingElements;
};
#endif
