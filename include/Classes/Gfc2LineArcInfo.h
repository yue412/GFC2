#ifndef GFC2LINEARCINFO_H
#define GFC2LINEARCINFO_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2BaseLineArcInfo.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2LineArcInfo: public Gfc2BaseLineArcInfo
{
OBJECTBUF_DEC_OBJECT(Gfc2LineArcInfo,glodon::objectbuf::Entity)
public:
    Gfc2LineArcInfo();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setBasePoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBasePoint = nValue;
        setHasBasePoint();
    }
    glodon::objectbuf::EntityRef getBasePoint() const {return m_nBasePoint;}
    bool hasBasePoint() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector2d* getBasePointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getBasePoint());}
    void setArchHeight(const Gfc2Double& dValue)
    {
        m_dArchHeight = dValue;
        setHasArchHeight();
    }
    Gfc2Double getArchHeight() const {return m_dArchHeight;}
    bool hasArchHeight() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setHalfChordLength(const Gfc2Double& dValue)
    {
        m_dHalfChordLength = dValue;
        setHasHalfChordLength();
    }
    Gfc2Double getHalfChordLength() const {return m_dHalfChordLength;}
    bool hasHalfChordLength() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setDefineByRadius(const Gfc2Boolean& bValue)
    {
        m_bDefineByRadius = bValue;
        setHasDefineByRadius();
    }
    Gfc2Boolean getDefineByRadius() const {return m_bDefineByRadius;}
    bool hasDefineByRadius() const {return (_has_bits_[0] & 0x10u) != 0;}

private:
    void setHasBasePoint() {_has_bits_[0] |= 0x1u;}
    void setHasArchHeight() {_has_bits_[0] |= 0x2u;}
    void setHasHalfChordLength() {_has_bits_[0] |= 0x4u;}
    void setHasRadius() {_has_bits_[0] |= 0x8u;}
    void setHasDefineByRadius() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nBasePoint;
    Gfc2Double m_dArchHeight;
    Gfc2Double m_dHalfChordLength;
    Gfc2Double m_dRadius;
    Gfc2Boolean m_bDefineByRadius;
};

class GFCCLASSES_API Gfc2LineArcInfoFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2LineArcInfoFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
