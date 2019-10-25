#ifndef GFC2AXISDATAITEM_H
#define GFC2AXISDATAITEM_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2AxisDataItem: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2AxisDataItem,glodon::objectbuf::Entity)
public:
    Gfc2AxisDataItem();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setAxisNo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nAxisNo = nValue;
        setHasAxisNo();
    }
    glodon::objectbuf::EntityRef getAxisNo() const {return m_nAxisNo;}
    bool hasAxisNo() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Label* getAxisNoPtr() const {return (Gfc2Label*)m_pDocument->find(getAxisNo());}
    void setDistance(const Gfc2Double& dValue)
    {
        m_dDistance = dValue;
        setHasDistance();
    }
    Gfc2Double getDistance() const {return m_dDistance;}
    bool hasDistance() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setLevel(const Gfc2Integer& nValue)
    {
        m_nLevel = nValue;
        setHasLevel();
    }
    Gfc2Integer getLevel() const {return m_nLevel;}
    bool hasLevel() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setAxisNoPos(const Gfc2AxisNoPosEnum& nValue)
    {
        m_nAxisNoPos = nValue;
        setHasAxisNoPos();
    }
    Gfc2AxisNoPosEnum getAxisNoPos() const {return m_nAxisNoPos;}
    bool hasAxisNoPos() const {return (_has_bits_[0] & 0x8u) != 0;}
    int getTrimPointsCount() const {return (int)m_oTrimPoints.size();}
    void clearTrimPoints() {m_oTrimPoints.clear();}
    void addTrimPoints(const glodon::objectbuf::EntityRef& nValue) {m_oTrimPoints.push_back(nValue);}
    glodon::objectbuf::EntityRef getTrimPoints(int nIndex) const {return m_oTrimPoints[nIndex];}
    Gfc2Vector2d* getTrimPointsPtr(int nIndex) const {return (Gfc2Vector2d*)m_pDocument->find(getTrimPoints(nIndex));}

protected:
    unsigned _has_bits_[1];
private:
    void setHasAxisNo() {_has_bits_[0] |= 0x1u;}
    void setHasDistance() {_has_bits_[0] |= 0x2u;}
    void setHasLevel() {_has_bits_[0] |= 0x4u;}
    void setHasAxisNoPos() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nAxisNo;
    Gfc2Double m_dDistance;
    Gfc2Integer m_nLevel;
    Gfc2AxisNoPosEnum m_nAxisNoPos;
    std::vector<glodon::objectbuf::EntityRef> m_oTrimPoints;
};
#endif
