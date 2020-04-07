#ifndef GFC2COMPLEXPROPERTY_H
#define GFC2COMPLEXPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Property.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ComplexProperty: public Gfc2Property
{
OBJECTBUF_DEC_OBJECT(Gfc2ComplexProperty,glodon::objectbuf::Entity)
public:
    Gfc2ComplexProperty();
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
