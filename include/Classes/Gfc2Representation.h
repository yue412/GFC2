#ifndef GFC2REPRESENTATION_H
#define GFC2REPRESENTATION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2RepresentationItem.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Representation: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2Representation,glodon::objectbuf::Entity)
public:
    Gfc2Representation();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setIdentifier(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nIdentifier = nValue;
        setHasIdentifier();
    }
    glodon::objectbuf::EntityRef getIdentifier() const {return m_nIdentifier;}
    bool hasIdentifier() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2String* getIdentifierPtr() const {return (Gfc2String*)m_pDocument->find(getIdentifier());}
    int getitemsCount() const {return (int)m_oitems.size();}
    void clearitems() {m_oitems.clear();}
    void additems(const glodon::objectbuf::EntityRef& nValue) {m_oitems.push_back(nValue);}
    glodon::objectbuf::EntityRef getitems(int nIndex) const {return m_oitems[nIndex];}
    Gfc2RepresentationItem* getitemsPtr(int nIndex) const {return (Gfc2RepresentationItem*)m_pDocument->find(getitems(nIndex));}

protected:
    unsigned _has_bits_[1];
private:
    void setHasIdentifier() {_has_bits_[0] |= 0x1u;}

    glodon::objectbuf::EntityRef m_nIdentifier;
    std::vector<glodon::objectbuf::EntityRef> m_oitems;
};
#endif
