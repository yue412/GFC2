#ifndef GFC2CYLINDER_H
#define GFC2CYLINDER_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Cylinder: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2Cylinder,glodon::objectbuf::Entity)
public:
    Gfc2Cylinder();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRangeV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeV = nValue;
        setHasRangeV();
    }
    glodon::objectbuf::EntityRef getRangeV() const {return m_nRangeV;}
    bool hasRangeV() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Intervald* getRangeVPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeV());}
    void setCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurve = nValue;
        setHasCurve();
    }
    glodon::objectbuf::EntityRef getCurve() const {return m_nCurve;}
    bool hasCurve() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Curve2d* getCurvePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getCurve());}
    void setDirX(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirX = nValue;
        setHasDirX();
    }
    glodon::objectbuf::EntityRef getDirX() const {return m_nDirX;}
    bool hasDirX() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Vector3d* getDirXPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getDirX());}
    void setDirY(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirY = nValue;
        setHasDirY();
    }
    glodon::objectbuf::EntityRef getDirY() const {return m_nDirY;}
    bool hasDirY() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Vector3d* getDirYPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getDirY());}
    void setDirZ(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirZ = nValue;
        setHasDirZ();
    }
    glodon::objectbuf::EntityRef getDirZ() const {return m_nDirZ;}
    bool hasDirZ() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Vector3d* getDirZPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getDirZ());}
    void setPos(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPos = nValue;
        setHasPos();
    }
    glodon::objectbuf::EntityRef getPos() const {return m_nPos;}
    bool hasPos() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2Vector3d* getPosPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getPos());}

private:
    void setHasRangeV() {_has_bits_[0] |= 0x1u;}
    void setHasCurve() {_has_bits_[0] |= 0x2u;}
    void setHasDirX() {_has_bits_[0] |= 0x4u;}
    void setHasDirY() {_has_bits_[0] |= 0x8u;}
    void setHasDirZ() {_has_bits_[0] |= 0x10u;}
    void setHasPos() {_has_bits_[0] |= 0x20u;}

    glodon::objectbuf::EntityRef m_nRangeV;
    glodon::objectbuf::EntityRef m_nCurve;
    glodon::objectbuf::EntityRef m_nDirX;
    glodon::objectbuf::EntityRef m_nDirY;
    glodon::objectbuf::EntityRef m_nDirZ;
    glodon::objectbuf::EntityRef m_nPos;
};
#endif
