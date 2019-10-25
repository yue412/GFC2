#ifndef GFC2PLANEINFO_H
#define GFC2PLANEINFO_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PlaneInfo: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2PlaneInfo,glodon::objectbuf::Entity)
public:
    Gfc2PlaneInfo();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setDirX(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirX = nValue;
        setHasDirX();
    }
    glodon::objectbuf::EntityRef getDirX() const {return m_nDirX;}
    bool hasDirX() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector3d* getDirXPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getDirX());}
    void setDirY(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirY = nValue;
        setHasDirY();
    }
    glodon::objectbuf::EntityRef getDirY() const {return m_nDirY;}
    bool hasDirY() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector3d* getDirYPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getDirY());}
    void setPos(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPos = nValue;
        setHasPos();
    }
    glodon::objectbuf::EntityRef getPos() const {return m_nPos;}
    bool hasPos() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Vector3d* getPosPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getPos());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasDirX() {_has_bits_[0] |= 0x1u;}
    void setHasDirY() {_has_bits_[0] |= 0x2u;}
    void setHasPos() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nDirX;
    glodon::objectbuf::EntityRef m_nDirY;
    glodon::objectbuf::EntityRef m_nPos;
};
#endif
