#ifndef GFC2FLOOR_H
#define GFC2FLOOR_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SpatialStructureElement.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Floor: public Gfc2SpatialStructureElement
{
OBJECTBUF_DEC_OBJECT(Gfc2Floor,glodon::objectbuf::Entity)
public:
    Gfc2Floor();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setFirstFloorFlag(const Gfc2Boolean& bValue)
    {
        m_bFirstFloorFlag = bValue;
        setHasFirstFloorFlag();
    }
    Gfc2Boolean getFirstFloorFlag() const {return m_bFirstFloorFlag;}
    bool hasFirstFloorFlag() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setHeight(const Gfc2Double& dValue)
    {
        m_dHeight = dValue;
        setHasHeight();
    }
    Gfc2Double getHeight() const {return m_dHeight;}
    bool hasHeight() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setStdFloorCount(const Gfc2Integer& nValue)
    {
        m_nStdFloorCount = nValue;
        setHasStdFloorCount();
    }
    Gfc2Integer getStdFloorCount() const {return m_nStdFloorCount;}
    bool hasStdFloorCount() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setStructuralElevation(const Gfc2Double& dValue)
    {
        m_dStructuralElevation = dValue;
        setHasStructuralElevation();
    }
    Gfc2Double getStructuralElevation() const {return m_dStructuralElevation;}
    bool hasStructuralElevation() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setStartFloorNo(const Gfc2Integer& nValue)
    {
        m_nStartFloorNo = nValue;
        setHasStartFloorNo();
    }
    Gfc2Integer getStartFloorNo() const {return m_nStartFloorNo;}
    bool hasStartFloorNo() const {return (_has_bits_[0] & 0x40u) != 0;}
    void setRemark(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRemark = nValue;
        setHasRemark();
    }
    glodon::objectbuf::EntityRef getRemark() const {return m_nRemark;}
    bool hasRemark() const {return (_has_bits_[0] & 0x80u) != 0;}
    Gfc2Text* getRemarkPtr() const {return (Gfc2Text*)m_pDocument->find(getRemark());}

private:
    void setHasFirstFloorFlag() {_has_bits_[0] |= 0x4u;}
    void setHasHeight() {_has_bits_[0] |= 0x8u;}
    void setHasStdFloorCount() {_has_bits_[0] |= 0x10u;}
    void setHasStructuralElevation() {_has_bits_[0] |= 0x20u;}
    void setHasStartFloorNo() {_has_bits_[0] |= 0x40u;}
    void setHasRemark() {_has_bits_[0] |= 0x80u;}

    Gfc2Boolean m_bFirstFloorFlag;
    Gfc2Double m_dHeight;
    Gfc2Integer m_nStdFloorCount;
    Gfc2Double m_dStructuralElevation;
    Gfc2Integer m_nStartFloorNo;
    glodon::objectbuf::EntityRef m_nRemark;
};

class GFCCLASSES_API Gfc2FloorFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FloorFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
