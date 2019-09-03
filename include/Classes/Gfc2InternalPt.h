#ifndef GFC2INTERNALPT_H
#define GFC2INTERNALPT_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2InternalPt: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2InternalPt,glodon::objectbuf::Entity)
public:
    Gfc2InternalPt();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setP(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nP = nValue;
        setHasP();
    }
    glodon::objectbuf::EntityRef getP() const {return m_nP;}
    bool hasP() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector3d* getPPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getP());}
    void setTVec(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nTVec = nValue;
        setHasTVec();
    }
    glodon::objectbuf::EntityRef getTVec() const {return m_nTVec;}
    bool hasTVec() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector3d* getTVecPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getTVec());}
    void setT(const Gfc2Double& dValue)
    {
        m_dT = dValue;
        setHasT();
    }
    Gfc2Double getT() const {return m_dT;}
    bool hasT() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setUV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nUV = nValue;
        setHasUV();
    }
    glodon::objectbuf::EntityRef getUV() const {return m_nUV;}
    bool hasUV() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Vector2d* getUVPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getUV());}
    void setST(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nST = nValue;
        setHasST();
    }
    glodon::objectbuf::EntityRef getST() const {return m_nST;}
    bool hasST() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Vector2d* getSTPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getST());}
    void setUVDir(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nUVDir = nValue;
        setHasUVDir();
    }
    glodon::objectbuf::EntityRef getUVDir() const {return m_nUVDir;}
    bool hasUVDir() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2Vector2d* getUVDirPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getUVDir());}
    void setSTDir(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSTDir = nValue;
        setHasSTDir();
    }
    glodon::objectbuf::EntityRef getSTDir() const {return m_nSTDir;}
    bool hasSTDir() const {return (_has_bits_[0] & 0x40u) != 0;}
    Gfc2Vector2d* getSTDirPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getSTDir());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasP() {_has_bits_[0] |= 0x1u;}
    void setHasTVec() {_has_bits_[0] |= 0x2u;}
    void setHasT() {_has_bits_[0] |= 0x4u;}
    void setHasUV() {_has_bits_[0] |= 0x8u;}
    void setHasST() {_has_bits_[0] |= 0x10u;}
    void setHasUVDir() {_has_bits_[0] |= 0x20u;}
    void setHasSTDir() {_has_bits_[0] |= 0x40u;}

    glodon::objectbuf::EntityRef m_nP;
    glodon::objectbuf::EntityRef m_nTVec;
    Gfc2Double m_dT;
    glodon::objectbuf::EntityRef m_nUV;
    glodon::objectbuf::EntityRef m_nST;
    glodon::objectbuf::EntityRef m_nUVDir;
    glodon::objectbuf::EntityRef m_nSTDir;
};

class GFCCLASSES_API Gfc2InternalPtFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2InternalPtFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
