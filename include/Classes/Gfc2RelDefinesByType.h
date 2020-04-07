#ifndef GFC2RELDEFINESBYTYPE_H
#define GFC2RELDEFINESBYTYPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelDefines.h"
#include "Gfc2ElementType.h"
#include "Gfc2Element.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelDefinesByType: public Gfc2RelDefines
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefinesByType,glodon::objectbuf::Entity)
public:
    Gfc2RelDefinesByType();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRelatingType(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRelatingType = nValue;
        setHasRelatingType();
    }
    glodon::objectbuf::EntityRef getRelatingType() const {return m_nRelatingType;}
    bool hasRelatingType() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2ElementType* getRelatingTypePtr() const {return (Gfc2ElementType*)m_pDocument->find(getRelatingType());}
    int getRelatingElementCount() const {return (int)m_oRelatingElement.size();}
    void clearRelatingElement() {m_oRelatingElement.clear();}
    void addRelatingElement(const glodon::objectbuf::EntityRef& nValue) {m_oRelatingElement.push_back(nValue);}
    glodon::objectbuf::EntityRef getRelatingElement(int nIndex) const {return m_oRelatingElement[nIndex];}
    Gfc2Element* getRelatingElementPtr(int nIndex) const {return (Gfc2Element*)m_pDocument->find(getRelatingElement(nIndex));}

private:
    void setHasRelatingType() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nRelatingType;
    std::vector<glodon::objectbuf::EntityRef> m_oRelatingElement;
};
#endif
