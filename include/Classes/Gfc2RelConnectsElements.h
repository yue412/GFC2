#ifndef GFC2RELCONNECTSELEMENTS_H
#define GFC2RELCONNECTSELEMENTS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelConnects.h"
#include "Gfc2Element.h"
#include "Gfc2Element.h"
#include "Gfc2ConnectionGeometry.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelConnectsElements: public Gfc2RelConnects
{
OBJECTBUF_DEC_OBJECT(Gfc2RelConnectsElements,glodon::objectbuf::Entity)
public:
    Gfc2RelConnectsElements();
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
    Gfc2Element* getRelatingElementPtr() const {return (Gfc2Element*)m_pDocument->find(getRelatingElement());}
    void setRelatedElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRelatedElement = nValue;
        setHasRelatedElement();
    }
    glodon::objectbuf::EntityRef getRelatedElement() const {return m_nRelatedElement;}
    bool hasRelatedElement() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Element* getRelatedElementPtr() const {return (Gfc2Element*)m_pDocument->find(getRelatedElement());}
    void setConnectionGeometry(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nConnectionGeometry = nValue;
        setHasConnectionGeometry();
    }
    glodon::objectbuf::EntityRef getConnectionGeometry() const {return m_nConnectionGeometry;}
    bool hasConnectionGeometry() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2ConnectionGeometry* getConnectionGeometryPtr() const {return (Gfc2ConnectionGeometry*)m_pDocument->find(getConnectionGeometry());}

private:
    void setHasRelatingElement() {_has_bits_[0] |= 0x2u;}
    void setHasRelatedElement() {_has_bits_[0] |= 0x4u;}
    void setHasConnectionGeometry() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nRelatingElement;
    glodon::objectbuf::EntityRef m_nRelatedElement;
    glodon::objectbuf::EntityRef m_nConnectionGeometry;
};
#endif
