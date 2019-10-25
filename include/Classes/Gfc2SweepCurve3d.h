#ifndef GFC2SWEEPCURVE3D_H
#define GFC2SWEEPCURVE3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector2d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SweepCurve3d: public Gfc2Curve3d
{
OBJECTBUF_DEC_OBJECT(Gfc2SweepCurve3d,glodon::objectbuf::Entity)
public:
    Gfc2SweepCurve3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setSpine3d(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSpine3d = nValue;
        setHasSpine3d();
    }
    glodon::objectbuf::EntityRef getSpine3d() const {return m_nSpine3d;}
    bool hasSpine3d() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Curve3d* getSpine3dPtr() const {return (Gfc2Curve3d*)m_pDocument->find(getSpine3d());}
    void setReferenceVector(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nReferenceVector = nValue;
        setHasReferenceVector();
    }
    glodon::objectbuf::EntityRef getReferenceVector() const {return m_nReferenceVector;}
    bool hasReferenceVector() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector3d* getReferenceVectorPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getReferenceVector());}
    void setPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPoint = nValue;
        setHasPoint();
    }
    glodon::objectbuf::EntityRef getPoint() const {return m_nPoint;}
    bool hasPoint() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Vector2d* getPointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getPoint());}
    void setSweepType(const Gfc2SweepType& nValue)
    {
        m_nSweepType = nValue;
        setHasSweepType();
    }
    Gfc2SweepType getSweepType() const {return m_nSweepType;}
    bool hasSweepType() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasSpine3d() {_has_bits_[0] |= 0x1u;}
    void setHasReferenceVector() {_has_bits_[0] |= 0x2u;}
    void setHasPoint() {_has_bits_[0] |= 0x4u;}
    void setHasSweepType() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nSpine3d;
    glodon::objectbuf::EntityRef m_nReferenceVector;
    glodon::objectbuf::EntityRef m_nPoint;
    Gfc2SweepType m_nSweepType;
};
#endif
