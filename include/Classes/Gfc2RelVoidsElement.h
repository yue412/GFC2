#ifndef GFC2RELVOIDSELEMENT_H
#define GFC2RELVOIDSELEMENT_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelDecomposes.h"
#include "Gfc2Element.h"
#include "Gfc2Element.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelVoidsElement: public Gfc2RelDecomposes
{
OBJECTBUF_DEC_OBJECT(Gfc2RelVoidsElement,glodon::objectbuf::Entity)
public:
    Gfc2RelVoidsElement();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRelatedOpeningElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRelatedOpeningElement = nValue;
        setHasRelatedOpeningElement();
    }
    glodon::objectbuf::EntityRef getRelatedOpeningElement() const {return m_nRelatedOpeningElement;}
    bool hasRelatedOpeningElement() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Element* getRelatedOpeningElementPtr() const {return (Gfc2Element*)m_pDocument->find(getRelatedOpeningElement());}
    int getRelatingBuildingElementCount() const {return (int)m_oRelatingBuildingElement.size();}
    void clearRelatingBuildingElement() {m_oRelatingBuildingElement.clear();}
    void addRelatingBuildingElement(const glodon::objectbuf::EntityRef& nValue) {m_oRelatingBuildingElement.push_back(nValue);}
    glodon::objectbuf::EntityRef getRelatingBuildingElement(int nIndex) const {return m_oRelatingBuildingElement[nIndex];}
    Gfc2Element* getRelatingBuildingElementPtr(int nIndex) const {return (Gfc2Element*)m_pDocument->find(getRelatingBuildingElement(nIndex));}

private:
    void setHasRelatedOpeningElement() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nRelatedOpeningElement;
    std::vector<glodon::objectbuf::EntityRef> m_oRelatingBuildingElement;
};
#endif
