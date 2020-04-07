#ifndef GFC2SECTIONLISTPROPERTY_H
#define GFC2SECTIONLISTPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ListProperty.h"
#include "Gfc2Section.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SectionListProperty: public Gfc2ListProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2SectionListProperty,glodon::objectbuf::Entity)
public:
    Gfc2SectionListProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getValueCount() const {return (int)m_oValue.size();}
    void clearValue() {m_oValue.clear();}
    void addValue(const glodon::objectbuf::EntityRef& nValue) {m_oValue.push_back(nValue);}
    glodon::objectbuf::EntityRef getValue(int nIndex) const {return m_oValue[nIndex];}
    Gfc2Section* getValuePtr(int nIndex) const {return (Gfc2Section*)m_pDocument->find(getValue(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oValue;
};
#endif
