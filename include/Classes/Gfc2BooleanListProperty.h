#ifndef GFC2BOOLEANLISTPROPERTY_H
#define GFC2BOOLEANLISTPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ListProperty.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2BooleanListProperty: public Gfc2ListProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2BooleanListProperty,glodon::objectbuf::Entity)
public:
    Gfc2BooleanListProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getValuesCount() const {return (int)m_oValues.size();}
    void clearValues() {m_oValues.clear();}
    void addValues(const Gfc2Boolean& bValue) {m_oValues.push_back(bValue);}
    Gfc2Boolean getValues(int nIndex) const {return m_oValues[nIndex];}

private:
    std::vector<Gfc2Boolean> m_oValues;
};
#endif
