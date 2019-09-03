#ifndef GFC2SECTIONLINESHAPE_H
#define GFC2SECTIONLINESHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2CustomLineShape.h"
#include "Gfc2Polygon.h"
#include "Gfc2Vector2d.h"
#include "Gfc2BaseLineArcInfo.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2SectionLineShape: public Gfc2CustomLineShape
{
OBJECTBUF_DEC_OBJECT(Gfc2SectionLineShape,glodon::objectbuf::Entity)
public:
    Gfc2SectionLineShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPoly(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPoly = nValue;
        setHasPoly();
    }
    glodon::objectbuf::EntityRef getPoly() const {return m_nPoly;}
    bool hasPoly() const {return (_has_bits_[0] & 0x100u) != 0;}
    Gfc2Polygon* getPolyPtr() const {return (Gfc2Polygon*)m_pDocument->find(getPoly());}
    void setBaseInsertPt(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBaseInsertPt = nValue;
        setHasBaseInsertPt();
    }
    glodon::objectbuf::EntityRef getBaseInsertPt() const {return m_nBaseInsertPt;}
    bool hasBaseInsertPt() const {return (_has_bits_[0] & 0x200u) != 0;}
    Gfc2Vector2d* getBaseInsertPtPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getBaseInsertPt());}
    void setAngle(const Gfc2Double& dValue)
    {
        m_dAngle = dValue;
        setHasAngle();
    }
    Gfc2Double getAngle() const {return m_dAngle;}
    bool hasAngle() const {return (_has_bits_[0] & 0x400u) != 0;}
    void setMirrorFlag(const Gfc2Boolean& bValue)
    {
        m_bMirrorFlag = bValue;
        setHasMirrorFlag();
    }
    Gfc2Boolean getMirrorFlag() const {return m_bMirrorFlag;}
    bool hasMirrorFlag() const {return (_has_bits_[0] & 0x800u) != 0;}
    void setArcInfo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nArcInfo = nValue;
        setHasArcInfo();
    }
    glodon::objectbuf::EntityRef getArcInfo() const {return m_nArcInfo;}
    bool hasArcInfo() const {return (_has_bits_[0] & 0x1000u) != 0;}
    Gfc2BaseLineArcInfo* getArcInfoPtr() const {return (Gfc2BaseLineArcInfo*)m_pDocument->find(getArcInfo());}
    void setIsSpiral(const Gfc2Boolean& bValue)
    {
        m_bIsSpiral = bValue;
        setHasIsSpiral();
    }
    Gfc2Boolean getIsSpiral() const {return m_bIsSpiral;}
    bool hasIsSpiral() const {return (_has_bits_[0] & 0x2000u) != 0;}

private:
    void setHasPoly() {_has_bits_[0] |= 0x100u;}
    void setHasBaseInsertPt() {_has_bits_[0] |= 0x200u;}
    void setHasAngle() {_has_bits_[0] |= 0x400u;}
    void setHasMirrorFlag() {_has_bits_[0] |= 0x800u;}
    void setHasArcInfo() {_has_bits_[0] |= 0x1000u;}
    void setHasIsSpiral() {_has_bits_[0] |= 0x2000u;}

    glodon::objectbuf::EntityRef m_nPoly;
    glodon::objectbuf::EntityRef m_nBaseInsertPt;
    Gfc2Double m_dAngle;
    Gfc2Boolean m_bMirrorFlag;
    glodon::objectbuf::EntityRef m_nArcInfo;
    Gfc2Boolean m_bIsSpiral;
};

class GFCCLASSES_API Gfc2SectionLineShapeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SectionLineShapeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
