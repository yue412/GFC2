#ifndef GFC2DOUBLELISTPROPERTY_H
#define GFC2DOUBLELISTPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ListProperty.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2DoubleListProperty: public Gfc2ListProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2DoubleListProperty,glodon::objectbuf::Entity)
public:
    Gfc2DoubleListProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getValuesCount() const {return (int)m_oValues.size();}
    void clearValues() {m_oValues.clear();}
    void addValues(const Gfc2Double& dValue) {m_oValues.push_back(dValue);}
    Gfc2Double getValues(int nIndex) const {return m_oValues[nIndex];}

private:
    std::vector<Gfc2Double> m_oValues;
};
#endif
