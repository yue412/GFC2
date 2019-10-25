#ifndef GFC2ASSITAXIS_H
#define GFC2ASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Entity.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2AssitAxis: public Gfc2Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2AssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2AssitAxis();
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
    bool hasAxisNo() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2Label* getAxisNoPtr() const {return (Gfc2Label*)m_pDocument->find(getAxisNo());}
    void setAxisNoPos(const Gfc2AxisNoPosEnum& nValue)
    {
        m_nAxisNoPos = nValue;
        setHasAxisNoPos();
    }
    Gfc2AxisNoPosEnum getAxisNoPos() const {return m_nAxisNoPos;}
    bool hasAxisNoPos() const {return (_has_bits_[0] & 0x40u) != 0;}
    int getTrimPointsCount() const {return (int)m_oTrimPoints.size();}
    void clearTrimPoints() {m_oTrimPoints.clear();}
    void addTrimPoints(const glodon::objectbuf::EntityRef& nValue) {m_oTrimPoints.push_back(nValue);}
    glodon::objectbuf::EntityRef getTrimPoints(int nIndex) const {return m_oTrimPoints[nIndex];}
    Gfc2Vector2d* getTrimPointsPtr(int nIndex) const {return (Gfc2Vector2d*)m_pDocument->find(getTrimPoints(nIndex));}

private:
    void setHasAxisNo() {_has_bits_[0] |= 0x20u;}
    void setHasAxisNoPos() {_has_bits_[0] |= 0x40u;}

    glodon::objectbuf::EntityRef m_nAxisNo;
    Gfc2AxisNoPosEnum m_nAxisNoPos;
    std::vector<glodon::objectbuf::EntityRef> m_oTrimPoints;
};
#endif
