#ifndef GFC2PROPERTYSET_H
#define GFC2PROPERTYSET_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Root.h"
#include "Gfc2Property.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2PropertySet: public Gfc2Root
{
OBJECTBUF_DEC_OBJECT(Gfc2PropertySet,glodon::objectbuf::Entity)
public:
    Gfc2PropertySet();
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
    Gfc2Label* getIdentifierPtr() const {return (Gfc2Label*)m_pDocument->find(getIdentifier());}
    int getHasPropertiesCount() const {return (int)m_oHasProperties.size();}
    void clearHasProperties() {m_oHasProperties.clear();}
    void addHasProperties(const glodon::objectbuf::EntityRef& nValue) {m_oHasProperties.push_back(nValue);}
    glodon::objectbuf::EntityRef getHasProperties(int nIndex) const {return m_oHasProperties[nIndex];}
    Gfc2Property* getHasPropertiesPtr(int nIndex) const {return (Gfc2Property*)m_pDocument->find(getHasProperties(nIndex));}

private:
    void setHasIdentifier() {_has_bits_[0] |= 0x1u;}

    glodon::objectbuf::EntityRef m_nIdentifier;
    std::vector<glodon::objectbuf::EntityRef> m_oHasProperties;
};

class GFCCLASSES_API Gfc2PropertySetFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PropertySetFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
