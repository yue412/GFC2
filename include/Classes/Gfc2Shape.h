#ifndef GFC2SHAPE_H
#define GFC2SHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Coordinates3d.h"
#include "Gfc2Box3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Shape: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2Shape,glodon::objectbuf::Entity)
public:
    Gfc2Shape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setLocalCoordinate(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nLocalCoordinate = nValue;
        setHasLocalCoordinate();
    }
    glodon::objectbuf::EntityRef getLocalCoordinate() const {return m_nLocalCoordinate;}
    bool hasLocalCoordinate() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Coordinates3d* getLocalCoordinatePtr() const {return (Gfc2Coordinates3d*)m_pDocument->find(getLocalCoordinate());}
    void setBoundingBox(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBoundingBox = nValue;
        setHasBoundingBox();
    }
    glodon::objectbuf::EntityRef getBoundingBox() const {return m_nBoundingBox;}
    bool hasBoundingBox() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Box3d* getBoundingBoxPtr() const {return (Gfc2Box3d*)m_pDocument->find(getBoundingBox());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasLocalCoordinate() {_has_bits_[0] |= 0x1u;}
    void setHasBoundingBox() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nLocalCoordinate;
    glodon::objectbuf::EntityRef m_nBoundingBox;
};

class GFCCLASSES_API Gfc2ShapeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2ShapeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
