#ifndef GFC2GEOLISTPROPERTY_H
#define GFC2GEOLISTPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ListProperty.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2GeoListProperty: public Gfc2ListProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2GeoListProperty,glodon::objectbuf::Entity)
public:
    Gfc2GeoListProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getValueCount() const {return (int)m_oValue.size();}
    void clearValue() {m_oValue.clear();}
    void addValue(const glodon::objectbuf::EntityRef& nValue) {m_oValue.push_back(nValue);}
    glodon::objectbuf::EntityRef getValue(int nIndex) const {return m_oValue[nIndex];}
    Gfc2Geometry* getValuePtr(int nIndex) const {return (Gfc2Geometry*)m_pDocument->find(getValue(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oValue;
};
#endif
