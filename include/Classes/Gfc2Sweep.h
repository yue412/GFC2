#ifndef GFC2SWEEP_H
#define GFC2SWEEP_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Sweep: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2Sweep,glodon::objectbuf::Entity)
public:
    Gfc2Sweep();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setProfile(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nProfile = nValue;
        setHasProfile();
    }
    glodon::objectbuf::EntityRef getProfile() const {return m_nProfile;}
    bool hasProfile() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Curve2d* getProfilePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getProfile());}
    void setSpine3d(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSpine3d = nValue;
        setHasSpine3d();
    }
    glodon::objectbuf::EntityRef getSpine3d() const {return m_nSpine3d;}
    bool hasSpine3d() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Curve3d* getSpine3dPtr() const {return (Gfc2Curve3d*)m_pDocument->find(getSpine3d());}
    void setReferenceVector(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nReferenceVector = nValue;
        setHasReferenceVector();
    }
    glodon::objectbuf::EntityRef getReferenceVector() const {return m_nReferenceVector;}
    bool hasReferenceVector() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Vector3d* getReferenceVectorPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getReferenceVector());}
    void setSweepType(const Gfc2SweepType& nValue)
    {
        m_nSweepType = nValue;
        setHasSweepType();
    }
    Gfc2SweepType getSweepType() const {return m_nSweepType;}
    bool hasSweepType() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasProfile() {_has_bits_[0] |= 0x1u;}
    void setHasSpine3d() {_has_bits_[0] |= 0x2u;}
    void setHasReferenceVector() {_has_bits_[0] |= 0x4u;}
    void setHasSweepType() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nProfile;
    glodon::objectbuf::EntityRef m_nSpine3d;
    glodon::objectbuf::EntityRef m_nReferenceVector;
    Gfc2SweepType m_nSweepType;
};

class GFCCLASSES_API Gfc2SweepFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SweepFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
