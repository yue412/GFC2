#ifndef GFC2EDGEDATA_H
#define GFC2EDGEDATA_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2String.h"
#include "Gfc2Polygon.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2EdgeData: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2EdgeData,glodon::objectbuf::Entity)
public:
    Gfc2EdgeData();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setEdgeIndex(const Gfc2Integer& nValue)
    {
        m_nEdgeIndex = nValue;
        setHasEdgeIndex();
    }
    Gfc2Integer getEdgeIndex() const {return m_nEdgeIndex;}
    bool hasEdgeIndex() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setLoopIndex(const Gfc2Integer& nValue)
    {
        m_nLoopIndex = nValue;
        setHasLoopIndex();
    }
    Gfc2Integer getLoopIndex() const {return m_nLoopIndex;}
    bool hasLoopIndex() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setType(const Gfc2Integer& nValue)
    {
        m_nType = nValue;
        setHasType();
    }
    Gfc2Integer getType() const {return m_nType;}
    bool hasType() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setEdgeInfo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nEdgeInfo = nValue;
        setHasEdgeInfo();
    }
    glodon::objectbuf::EntityRef getEdgeInfo() const {return m_nEdgeInfo;}
    bool hasEdgeInfo() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2String* getEdgeInfoPtr() const {return (Gfc2String*)m_pDocument->find(getEdgeInfo());}
    void setParam(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nParam = nValue;
        setHasParam();
    }
    glodon::objectbuf::EntityRef getParam() const {return m_nParam;}
    bool hasParam() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2String* getParamPtr() const {return (Gfc2String*)m_pDocument->find(getParam());}
    void setBaseType(const Gfc2Integer& nValue)
    {
        m_nBaseType = nValue;
        setHasBaseType();
    }
    Gfc2Integer getBaseType() const {return m_nBaseType;}
    bool hasBaseType() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setSlopePoly(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSlopePoly = nValue;
        setHasSlopePoly();
    }
    glodon::objectbuf::EntityRef getSlopePoly() const {return m_nSlopePoly;}
    bool hasSlopePoly() const {return (_has_bits_[0] & 0x40u) != 0;}
    Gfc2Polygon* getSlopePolyPtr() const {return (Gfc2Polygon*)m_pDocument->find(getSlopePoly());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasEdgeIndex() {_has_bits_[0] |= 0x1u;}
    void setHasLoopIndex() {_has_bits_[0] |= 0x2u;}
    void setHasType() {_has_bits_[0] |= 0x4u;}
    void setHasEdgeInfo() {_has_bits_[0] |= 0x8u;}
    void setHasParam() {_has_bits_[0] |= 0x10u;}
    void setHasBaseType() {_has_bits_[0] |= 0x20u;}
    void setHasSlopePoly() {_has_bits_[0] |= 0x40u;}

    Gfc2Integer m_nEdgeIndex;
    Gfc2Integer m_nLoopIndex;
    Gfc2Integer m_nType;
    glodon::objectbuf::EntityRef m_nEdgeInfo;
    glodon::objectbuf::EntityRef m_nParam;
    Gfc2Integer m_nBaseType;
    glodon::objectbuf::EntityRef m_nSlopePoly;
};

class GFCCLASSES_API Gfc2EdgeDataFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2EdgeDataFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
