#ifndef GFC2EDGE_H
#define GFC2EDGE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Edge: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2Edge,glodon::objectbuf::Entity)
public:
    Gfc2Edge();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurve = nValue;
        setHasCurve();
    }
    glodon::objectbuf::EntityRef getCurve() const {return m_nCurve;}
    bool hasCurve() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Curve3d* getCurvePtr() const {return (Gfc2Curve3d*)m_pDocument->find(getCurve());}
    void setFaceIndex1(const Gfc2Integer& nValue)
    {
        m_nFaceIndex1 = nValue;
        setHasFaceIndex1();
    }
    Gfc2Integer getFaceIndex1() const {return m_nFaceIndex1;}
    bool hasFaceIndex1() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setFaceIndex2(const Gfc2Integer& nValue)
    {
        m_nFaceIndex2 = nValue;
        setHasFaceIndex2();
    }
    Gfc2Integer getFaceIndex2() const {return m_nFaceIndex2;}
    bool hasFaceIndex2() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setLoopIndex1(const Gfc2Integer& nValue)
    {
        m_nLoopIndex1 = nValue;
        setHasLoopIndex1();
    }
    Gfc2Integer getLoopIndex1() const {return m_nLoopIndex1;}
    bool hasLoopIndex1() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setLoopIndex2(const Gfc2Integer& nValue)
    {
        m_nLoopIndex2 = nValue;
        setHasLoopIndex2();
    }
    Gfc2Integer getLoopIndex2() const {return m_nLoopIndex2;}
    bool hasLoopIndex2() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setCoedgeIndex1(const Gfc2Integer& nValue)
    {
        m_nCoedgeIndex1 = nValue;
        setHasCoedgeIndex1();
    }
    Gfc2Integer getCoedgeIndex1() const {return m_nCoedgeIndex1;}
    bool hasCoedgeIndex1() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setCoedgeIndex2(const Gfc2Integer& nValue)
    {
        m_nCoedgeIndex2 = nValue;
        setHasCoedgeIndex2();
    }
    Gfc2Integer getCoedgeIndex2() const {return m_nCoedgeIndex2;}
    bool hasCoedgeIndex2() const {return (_has_bits_[0] & 0x40u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasCurve() {_has_bits_[0] |= 0x1u;}
    void setHasFaceIndex1() {_has_bits_[0] |= 0x2u;}
    void setHasFaceIndex2() {_has_bits_[0] |= 0x4u;}
    void setHasLoopIndex1() {_has_bits_[0] |= 0x8u;}
    void setHasLoopIndex2() {_has_bits_[0] |= 0x10u;}
    void setHasCoedgeIndex1() {_has_bits_[0] |= 0x20u;}
    void setHasCoedgeIndex2() {_has_bits_[0] |= 0x40u;}

    glodon::objectbuf::EntityRef m_nCurve;
    Gfc2Integer m_nFaceIndex1;
    Gfc2Integer m_nFaceIndex2;
    Gfc2Integer m_nLoopIndex1;
    Gfc2Integer m_nLoopIndex2;
    Gfc2Integer m_nCoedgeIndex1;
    Gfc2Integer m_nCoedgeIndex2;
};

class GFCCLASSES_API Gfc2EdgeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2EdgeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
