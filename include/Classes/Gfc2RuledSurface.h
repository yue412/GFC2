#ifndef GFC2RULEDSURFACE_H
#define GFC2RULEDSURFACE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2Intervald.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Curve3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2RuledSurface: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2RuledSurface,glodon::objectbuf::Entity)
public:
    Gfc2RuledSurface();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setApexIndex(const Gfc2Integer& nValue)
    {
        m_nApexIndex = nValue;
        setHasApexIndex();
    }
    Gfc2Integer getApexIndex() const {return m_nApexIndex;}
    bool hasApexIndex() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setRangeV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeV = nValue;
        setHasRangeV();
    }
    glodon::objectbuf::EntityRef getRangeV() const {return m_nRangeV;}
    bool hasRangeV() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Intervald* getRangeVPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeV());}
    void setRangeU(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeU = nValue;
        setHasRangeU();
    }
    glodon::objectbuf::EntityRef getRangeU() const {return m_nRangeU;}
    bool hasRangeU() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Intervald* getRangeUPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeU());}
    void setDirectrix1(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirectrix1 = nValue;
        setHasDirectrix1();
    }
    glodon::objectbuf::EntityRef getDirectrix1() const {return m_nDirectrix1;}
    bool hasDirectrix1() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Curve3d* getDirectrix1Ptr() const {return (Gfc2Curve3d*)m_pDocument->find(getDirectrix1());}
    void setDirectrix2(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirectrix2 = nValue;
        setHasDirectrix2();
    }
    glodon::objectbuf::EntityRef getDirectrix2() const {return m_nDirectrix2;}
    bool hasDirectrix2() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Curve3d* getDirectrix2Ptr() const {return (Gfc2Curve3d*)m_pDocument->find(getDirectrix2());}

private:
    void setHasApexIndex() {_has_bits_[0] |= 0x1u;}
    void setHasRangeV() {_has_bits_[0] |= 0x2u;}
    void setHasRangeU() {_has_bits_[0] |= 0x4u;}
    void setHasDirectrix1() {_has_bits_[0] |= 0x8u;}
    void setHasDirectrix2() {_has_bits_[0] |= 0x10u;}

    Gfc2Integer m_nApexIndex;
    glodon::objectbuf::EntityRef m_nRangeV;
    glodon::objectbuf::EntityRef m_nRangeU;
    glodon::objectbuf::EntityRef m_nDirectrix1;
    glodon::objectbuf::EntityRef m_nDirectrix2;
};

class GFCCLASSES_API Gfc2RuledSurfaceFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2RuledSurfaceFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
