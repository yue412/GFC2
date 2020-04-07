#ifndef GFC2GEOPROPERTY_H
#define GFC2GEOPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SingleProperty.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2GeoProperty: public Gfc2SingleProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2GeoProperty,glodon::objectbuf::Entity)
public:
    Gfc2GeoProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setGeo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nGeo = nValue;
        setHasGeo();
    }
    glodon::objectbuf::EntityRef getGeo() const {return m_nGeo;}
    bool hasGeo() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Geometry* getGeoPtr() const {return (Gfc2Geometry*)m_pDocument->find(getGeo());}

private:
    void setHasGeo() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nGeo;
};
#endif
