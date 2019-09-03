#ifndef GFC2GEOMETRYSHAPE_H
#define GFC2GEOMETRYSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Shape.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2GeometryShape: public Gfc2Shape
{
OBJECTBUF_DEC_OBJECT(Gfc2GeometryShape,glodon::objectbuf::Entity)
public:
    Gfc2GeometryShape();
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
    bool hasGeo() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Geometry* getGeoPtr() const {return (Gfc2Geometry*)m_pDocument->find(getGeo());}

private:
    void setHasGeo() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nGeo;
};

class GFCCLASSES_API Gfc2GeometryShapeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2GeometryShapeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
