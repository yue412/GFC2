#ifndef GFC2COORDINATES3D_H
#define GFC2COORDINATES3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Geometry.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Coordinates3d: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Coordinates3d,glodon::objectbuf::Entity)
public:
    Gfc2Coordinates3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setOrigin(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nOrigin = nValue;
        setHasOrigin();
    }
    glodon::objectbuf::EntityRef getOrigin() const {return m_nOrigin;}
    bool hasOrigin() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector3d* getOriginPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getOrigin());}
    void setX(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nX = nValue;
        setHasX();
    }
    glodon::objectbuf::EntityRef getX() const {return m_nX;}
    bool hasX() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector3d* getXPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getX());}
    void setY(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nY = nValue;
        setHasY();
    }
    glodon::objectbuf::EntityRef getY() const {return m_nY;}
    bool hasY() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Vector3d* getYPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getY());}
    void setZ(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nZ = nValue;
        setHasZ();
    }
    glodon::objectbuf::EntityRef getZ() const {return m_nZ;}
    bool hasZ() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Vector3d* getZPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getZ());}

private:
    void setHasOrigin() {_has_bits_[0] |= 0x1u;}
    void setHasX() {_has_bits_[0] |= 0x2u;}
    void setHasY() {_has_bits_[0] |= 0x4u;}
    void setHasZ() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nOrigin;
    glodon::objectbuf::EntityRef m_nX;
    glodon::objectbuf::EntityRef m_nY;
    glodon::objectbuf::EntityRef m_nZ;
};

class GFCCLASSES_API Gfc2Coordinates3dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Coordinates3dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
