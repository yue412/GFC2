#ifndef GFC2STRINGLISTPROPERTY_H
#define GFC2STRINGLISTPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ListProperty.h"
#include "Gfc2String.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2StringListProperty: public Gfc2ListProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2StringListProperty,glodon::objectbuf::Entity)
public:
    Gfc2StringListProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getValuesCount() const {return (int)m_oValues.size();}
    void clearValues() {m_oValues.clear();}
    void addValues(const glodon::objectbuf::EntityRef& nValue) {m_oValues.push_back(nValue);}
    glodon::objectbuf::EntityRef getValues(int nIndex) const {return m_oValues[nIndex];}
    Gfc2String* getValuesPtr(int nIndex) const {return (Gfc2String*)m_pDocument->find(getValues(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oValues;
};
#endif
