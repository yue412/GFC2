#ifndef GFC2CUSTOMPOINTSHAPE_H
#define GFC2CUSTOMPOINTSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SolidShape.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2CustomPointShape: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2CustomPointShape,glodon::objectbuf::Entity)
public:
    Gfc2CustomPointShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setInsertPt(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nInsertPt = nValue;
        setHasInsertPt();
    }
    glodon::objectbuf::EntityRef getInsertPt() const {return m_nInsertPt;}
    bool hasInsertPt() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Vector2d* getInsertPtPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getInsertPt());}
    void setBaseInsertPt(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBaseInsertPt = nValue;
        setHasBaseInsertPt();
    }
    glodon::objectbuf::EntityRef getBaseInsertPt() const {return m_nBaseInsertPt;}
    bool hasBaseInsertPt() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2Vector2d* getBaseInsertPtPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getBaseInsertPt());}
    void setAngle(const Gfc2Double& dValue)
    {
        m_dAngle = dValue;
        setHasAngle();
    }
    Gfc2Double getAngle() const {return m_dAngle;}
    bool hasAngle() const {return (_has_bits_[0] & 0x40u) != 0;}
    void setMirrorFlag(const Gfc2Boolean& bValue)
    {
        m_bMirrorFlag = bValue;
        setHasMirrorFlag();
    }
    Gfc2Boolean getMirrorFlag() const {return m_bMirrorFlag;}
    bool hasMirrorFlag() const {return (_has_bits_[0] & 0x80u) != 0;}

private:
    void setHasInsertPt() {_has_bits_[0] |= 0x10u;}
    void setHasBaseInsertPt() {_has_bits_[0] |= 0x20u;}
    void setHasAngle() {_has_bits_[0] |= 0x40u;}
    void setHasMirrorFlag() {_has_bits_[0] |= 0x80u;}

    glodon::objectbuf::EntityRef m_nInsertPt;
    glodon::objectbuf::EntityRef m_nBaseInsertPt;
    Gfc2Double m_dAngle;
    Gfc2Boolean m_bMirrorFlag;
};

class GFCCLASSES_API Gfc2CustomPointShapeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CustomPointShapeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
