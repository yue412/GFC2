#ifndef GFC2RELCOVERSBLDGELEMENTS_H
#define GFC2RELCOVERSBLDGELEMENTS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelConnects.h"
#include "Gfc2Element.h"
#include "Gfc2Element.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelCoversBldgElements: public Gfc2RelConnects
{
OBJECTBUF_DEC_OBJECT(Gfc2RelCoversBldgElements,glodon::objectbuf::Entity)
public:
    Gfc2RelCoversBldgElements();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRelatingBuildingElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRelatingBuildingElement = nValue;
        setHasRelatingBuildingElement();
    }
    glodon::objectbuf::EntityRef getRelatingBuildingElement() const {return m_nRelatingBuildingElement;}
    bool hasRelatingBuildingElement() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Element* getRelatingBuildingElementPtr() const {return (Gfc2Element*)m_pDocument->find(getRelatingBuildingElement());}
    int getRelatedCoveringsCount() const {return (int)m_oRelatedCoverings.size();}
    void clearRelatedCoverings() {m_oRelatedCoverings.clear();}
    void addRelatedCoverings(const glodon::objectbuf::EntityRef& nValue) {m_oRelatedCoverings.push_back(nValue);}
    glodon::objectbuf::EntityRef getRelatedCoverings(int nIndex) const {return m_oRelatedCoverings[nIndex];}
    Gfc2Element* getRelatedCoveringsPtr(int nIndex) const {return (Gfc2Element*)m_pDocument->find(getRelatedCoverings(nIndex));}

private:
    void setHasRelatingBuildingElement() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nRelatingBuildingElement;
    std::vector<glodon::objectbuf::EntityRef> m_oRelatedCoverings;
};
#endif
