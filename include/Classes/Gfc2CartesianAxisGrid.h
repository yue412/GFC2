#ifndef GFC2CARTESIANAXISGRID_H
#define GFC2CARTESIANAXISGRID_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AxisGrid.h"
#include "Gfc2Vector2d.h"
#include "Gfc2AxisDataItem.h"
#include "Gfc2AxisDataItem.h"
#include "Gfc2AxisDataItem.h"
#include "Gfc2AxisDataItem.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CartesianAxisGrid: public Gfc2AxisGrid
{
OBJECTBUF_DEC_OBJECT(Gfc2CartesianAxisGrid,glodon::objectbuf::Entity)
public:
    Gfc2CartesianAxisGrid();
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
    void setAxisAngle(const Gfc2Double& dValue)
    {
        m_dAxisAngle = dValue;
        setHasAxisAngle();
    }
    Gfc2Double getAxisAngle() const {return m_dAxisAngle;}
    bool hasAxisAngle() const {return (_has_bits_[0] & 0x40u) != 0;}
    int getSKJCount() const {return (int)m_oSKJ.size();}
    void clearSKJ() {m_oSKJ.clear();}
    void addSKJ(const glodon::objectbuf::EntityRef& nValue) {m_oSKJ.push_back(nValue);}
    glodon::objectbuf::EntityRef getSKJ(int nIndex) const {return m_oSKJ[nIndex];}
    Gfc2AxisDataItem* getSKJPtr(int nIndex) const {return (Gfc2AxisDataItem*)m_pDocument->find(getSKJ(nIndex));}
    int getZJSCount() const {return (int)m_oZJS.size();}
    void clearZJS() {m_oZJS.clear();}
    void addZJS(const glodon::objectbuf::EntityRef& nValue) {m_oZJS.push_back(nValue);}
    glodon::objectbuf::EntityRef getZJS(int nIndex) const {return m_oZJS[nIndex];}
    Gfc2AxisDataItem* getZJSPtr(int nIndex) const {return (Gfc2AxisDataItem*)m_pDocument->find(getZJS(nIndex));}
    int getYJSCount() const {return (int)m_oYJS.size();}
    void clearYJS() {m_oYJS.clear();}
    void addYJS(const glodon::objectbuf::EntityRef& nValue) {m_oYJS.push_back(nValue);}
    glodon::objectbuf::EntityRef getYJS(int nIndex) const {return m_oYJS[nIndex];}
    Gfc2AxisDataItem* getYJSPtr(int nIndex) const {return (Gfc2AxisDataItem*)m_pDocument->find(getYJS(nIndex));}
    int getXKJCount() const {return (int)m_oXKJ.size();}
    void clearXKJ() {m_oXKJ.clear();}
    void addXKJ(const glodon::objectbuf::EntityRef& nValue) {m_oXKJ.push_back(nValue);}
    glodon::objectbuf::EntityRef getXKJ(int nIndex) const {return m_oXKJ[nIndex];}
    Gfc2AxisDataItem* getXKJPtr(int nIndex) const {return (Gfc2AxisDataItem*)m_pDocument->find(getXKJ(nIndex));}

private:
    void setHasInsertPt() {_has_bits_[0] |= 0x20u;}
    void setHasAxisAngle() {_has_bits_[0] |= 0x40u;}

    glodon::objectbuf::EntityRef m_nInsertPt;
    Gfc2Double m_dAxisAngle;
    std::vector<glodon::objectbuf::EntityRef> m_oSKJ;
    std::vector<glodon::objectbuf::EntityRef> m_oZJS;
    std::vector<glodon::objectbuf::EntityRef> m_oYJS;
    std::vector<glodon::objectbuf::EntityRef> m_oXKJ;
};
#endif
