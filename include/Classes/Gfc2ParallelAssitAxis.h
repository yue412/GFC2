#ifndef GFC2PARALLELASSITAXIS_H
#define GFC2PARALLELASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AssitAxis.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2ParallelAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2ParallelAssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2ParallelAssitAxis();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRefAxisNo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRefAxisNo = nValue;
        setHasRefAxisNo();
    }
    glodon::objectbuf::EntityRef getRefAxisNo() const {return m_nRefAxisNo;}
    bool hasRefAxisNo() const {return (_has_bits_[0] & 0x100u) != 0;}
    Gfc2Label* getRefAxisNoPtr() const {return (Gfc2Label*)m_pDocument->find(getRefAxisNo());}
    void setOffset(const Gfc2Double& dValue)
    {
        m_dOffset = dValue;
        setHasOffset();
    }
    Gfc2Double getOffset() const {return m_dOffset;}
    bool hasOffset() const {return (_has_bits_[0] & 0x200u) != 0;}
    void setRefAxisIndex(const Gfc2Integer& nValue)
    {
        m_nRefAxisIndex = nValue;
        setHasRefAxisIndex();
    }
    Gfc2Integer getRefAxisIndex() const {return m_nRefAxisIndex;}
    bool hasRefAxisIndex() const {return (_has_bits_[0] & 0x400u) != 0;}
    void setRefAxisType(const Gfc2AxisType& nValue)
    {
        m_nRefAxisType = nValue;
        setHasRefAxisType();
    }
    Gfc2AxisType getRefAxisType() const {return m_nRefAxisType;}
    bool hasRefAxisType() const {return (_has_bits_[0] & 0x800u) != 0;}

private:
    void setHasRefAxisNo() {_has_bits_[0] |= 0x100u;}
    void setHasOffset() {_has_bits_[0] |= 0x200u;}
    void setHasRefAxisIndex() {_has_bits_[0] |= 0x400u;}
    void setHasRefAxisType() {_has_bits_[0] |= 0x800u;}

    glodon::objectbuf::EntityRef m_nRefAxisNo;
    Gfc2Double m_dOffset;
    Gfc2Integer m_nRefAxisIndex;
    Gfc2AxisType m_nRefAxisType;
};

class GFCCLASSES_API Gfc2ParallelAssitAxisFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2ParallelAssitAxisFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
