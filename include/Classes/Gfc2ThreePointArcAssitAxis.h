#ifndef GFC2THREEPOINTARCASSITAXIS_H
#define GFC2THREEPOINTARCASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AssitAxis.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2ThreePointArcAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2ThreePointArcAssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2ThreePointArcAssitAxis();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRefPoint1(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRefPoint1 = nValue;
        setHasRefPoint1();
    }
    glodon::objectbuf::EntityRef getRefPoint1() const {return m_nRefPoint1;}
    bool hasRefPoint1() const {return (_has_bits_[0] & 0x100u) != 0;}
    Gfc2Vector2d* getRefPoint1Ptr() const {return (Gfc2Vector2d*)m_pDocument->find(getRefPoint1());}
    void setRefPoint2(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRefPoint2 = nValue;
        setHasRefPoint2();
    }
    glodon::objectbuf::EntityRef getRefPoint2() const {return m_nRefPoint2;}
    bool hasRefPoint2() const {return (_has_bits_[0] & 0x200u) != 0;}
    Gfc2Vector2d* getRefPoint2Ptr() const {return (Gfc2Vector2d*)m_pDocument->find(getRefPoint2());}
    void setRefPoint3(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRefPoint3 = nValue;
        setHasRefPoint3();
    }
    glodon::objectbuf::EntityRef getRefPoint3() const {return m_nRefPoint3;}
    bool hasRefPoint3() const {return (_has_bits_[0] & 0x400u) != 0;}
    Gfc2Vector2d* getRefPoint3Ptr() const {return (Gfc2Vector2d*)m_pDocument->find(getRefPoint3());}

private:
    void setHasRefPoint1() {_has_bits_[0] |= 0x100u;}
    void setHasRefPoint2() {_has_bits_[0] |= 0x200u;}
    void setHasRefPoint3() {_has_bits_[0] |= 0x400u;}

    glodon::objectbuf::EntityRef m_nRefPoint1;
    glodon::objectbuf::EntityRef m_nRefPoint2;
    glodon::objectbuf::EntityRef m_nRefPoint3;
};

class GFCCLASSES_API Gfc2ThreePointArcAssitAxisFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2ThreePointArcAssitAxisFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
