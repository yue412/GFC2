#ifndef GFC2PROPERTYSET_H
#define GFC2PROPERTYSET_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Root.h"
#include "Gfc2Property.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PropertySet: public Gfc2Root
{
OBJECTBUF_DEC_OBJECT(Gfc2PropertySet,glodon::objectbuf::Entity)
public:
    Gfc2PropertySet();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getHasPropertiesCount() const {return (int)m_oHasProperties.size();}
    void clearHasProperties() {m_oHasProperties.clear();}
    void addHasProperties(const glodon::objectbuf::EntityRef& nValue) {m_oHasProperties.push_back(nValue);}
    glodon::objectbuf::EntityRef getHasProperties(int nIndex) const {return m_oHasProperties[nIndex];}
    Gfc2Property* getHasPropertiesPtr(int nIndex) const {return (Gfc2Property*)m_pDocument->find(getHasProperties(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oHasProperties;
};
#endif
