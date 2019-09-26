#ifndef GFC2CUBOIDBODY_H
#define GFC2CUBOIDBODY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2PrimitiveBody.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2CuboidBody: public Gfc2PrimitiveBody
{
OBJECTBUF_DEC_OBJECT(Gfc2CuboidBody,glodon::objectbuf::Entity)
public:
    Gfc2CuboidBody();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCoordinate(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCoordinate = nValue;
        setHasCoordinate();
    }
    glodon::objectbuf::EntityRef getCoordinate() const {return m_nCoordinate;}
    bool hasCoordinate() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Coordinates3d* getCoordinatePtr() const {return (Gfc2Coordinates3d*)m_pDocument->find(getCoordinate());}
    void setDimension(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDimension = nValue;
        setHasDimension();
    }
    glodon::objectbuf::EntityRef getDimension() const {return m_nDimension;}
    bool hasDimension() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector3d* getDimensionPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getDimension());}

private:
    void setHasCoordinate() {_has_bits_[0] |= 0x1u;}
    void setHasDimension() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nCoordinate;
    glodon::objectbuf::EntityRef m_nDimension;
};

class GFCCLASSES_API Gfc2CuboidBodyFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CuboidBodyFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
