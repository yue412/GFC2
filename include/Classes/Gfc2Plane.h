#ifndef GFC2PLANE_H
#define GFC2PLANE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Intervald.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Plane: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2Plane,glodon::objectbuf::Entity)
public:
    Gfc2Plane();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPos(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPos = nValue;
        setHasPos();
    }
    glodon::objectbuf::EntityRef getPos() const {return m_nPos;}
    bool hasPos() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector3d* getPosPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getPos());}
    void setDirU(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirU = nValue;
        setHasDirU();
    }
    glodon::objectbuf::EntityRef getDirU() const {return m_nDirU;}
    bool hasDirU() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector3d* getDirUPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getDirU());}
    void setDirV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirV = nValue;
        setHasDirV();
    }
    glodon::objectbuf::EntityRef getDirV() const {return m_nDirV;}
    bool hasDirV() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Vector3d* getDirVPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getDirV());}
    void setRangeU(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeU = nValue;
        setHasRangeU();
    }
    glodon::objectbuf::EntityRef getRangeU() const {return m_nRangeU;}
    bool hasRangeU() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Intervald* getRangeUPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeU());}
    void setRangeV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeV = nValue;
        setHasRangeV();
    }
    glodon::objectbuf::EntityRef getRangeV() const {return m_nRangeV;}
    bool hasRangeV() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Intervald* getRangeVPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeV());}

private:
    void setHasPos() {_has_bits_[0] |= 0x1u;}
    void setHasDirU() {_has_bits_[0] |= 0x2u;}
    void setHasDirV() {_has_bits_[0] |= 0x4u;}
    void setHasRangeU() {_has_bits_[0] |= 0x8u;}
    void setHasRangeV() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nPos;
    glodon::objectbuf::EntityRef m_nDirU;
    glodon::objectbuf::EntityRef m_nDirV;
    glodon::objectbuf::EntityRef m_nRangeU;
    glodon::objectbuf::EntityRef m_nRangeV;
};

class GFCCLASSES_API Gfc2PlaneFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PlaneFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
