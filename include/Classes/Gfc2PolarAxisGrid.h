#ifndef GFC2POLARAXISGRID_H
#define GFC2POLARAXISGRID_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AxisGrid.h"
#include "Gfc2Vector2d.h"
#include "Gfc2AxisDataItem.h"
#include "Gfc2AxisDataItem.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PolarAxisGrid: public Gfc2AxisGrid
{
OBJECTBUF_DEC_OBJECT(Gfc2PolarAxisGrid,glodon::objectbuf::Entity)
public:
    Gfc2PolarAxisGrid();
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
    bool hasInsertPt() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2Vector2d* getInsertPtPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getInsertPt());}
    void setStartRadius(const Gfc2Double& dValue)
    {
        m_dStartRadius = dValue;
        setHasStartRadius();
    }
    Gfc2Double getStartRadius() const {return m_dStartRadius;}
    bool hasStartRadius() const {return (_has_bits_[0] & 0x40u) != 0;}
    void setClockwise(const Gfc2Boolean& bValue)
    {
        m_bClockwise = bValue;
        setHasClockwise();
    }
    Gfc2Boolean getClockwise() const {return m_bClockwise;}
    bool hasClockwise() const {return (_has_bits_[0] & 0x80u) != 0;}
    int getXKJCount() const {return (int)m_oXKJ.size();}
    void clearXKJ() {m_oXKJ.clear();}
    void addXKJ(const glodon::objectbuf::EntityRef& nValue) {m_oXKJ.push_back(nValue);}
    glodon::objectbuf::EntityRef getXKJ(int nIndex) const {return m_oXKJ[nIndex];}
    Gfc2AxisDataItem* getXKJPtr(int nIndex) const {return (Gfc2AxisDataItem*)m_pDocument->find(getXKJ(nIndex));}
    int getZJSCount() const {return (int)m_oZJS.size();}
    void clearZJS() {m_oZJS.clear();}
    void addZJS(const glodon::objectbuf::EntityRef& nValue) {m_oZJS.push_back(nValue);}
    glodon::objectbuf::EntityRef getZJS(int nIndex) const {return m_oZJS[nIndex];}
    Gfc2AxisDataItem* getZJSPtr(int nIndex) const {return (Gfc2AxisDataItem*)m_pDocument->find(getZJS(nIndex));}

private:
    void setHasInsertPt() {_has_bits_[0] |= 0x20u;}
    void setHasStartRadius() {_has_bits_[0] |= 0x40u;}
    void setHasClockwise() {_has_bits_[0] |= 0x80u;}

    glodon::objectbuf::EntityRef m_nInsertPt;
    Gfc2Double m_dStartRadius;
    Gfc2Boolean m_bClockwise;
    std::vector<glodon::objectbuf::EntityRef> m_oXKJ;
    std::vector<glodon::objectbuf::EntityRef> m_oZJS;
};
#endif
