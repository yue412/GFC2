#ifndef GFC2INTEGERLISTPROPERTY_H
#define GFC2INTEGERLISTPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ListProperty.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2IntegerListProperty: public Gfc2ListProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2IntegerListProperty,glodon::objectbuf::Entity)
public:
    Gfc2IntegerListProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getValuesCount() const {return (int)m_oValues.size();}
    void clearValues() {m_oValues.clear();}
    void addValues(const Gfc2Integer& nValue) {m_oValues.push_back(nValue);}
    Gfc2Integer getValues(int nIndex) const {return m_oValues[nIndex];}

private:
    std::vector<Gfc2Integer> m_oValues;
};
#endif
