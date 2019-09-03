#ifndef GFC2INTERSECTIONCURVE3D_H
#define GFC2INTERSECTIONCURVE3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve3d.h"
#include "Gfc2Surface.h"
#include "Gfc2Surface.h"
#include "Gfc2Intervald.h"
#include "Gfc2InternalChart.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2IntersectionCurve3d: public Gfc2Curve3d
{
OBJECTBUF_DEC_OBJECT(Gfc2IntersectionCurve3d,glodon::objectbuf::Entity)
public:
    Gfc2IntersectionCurve3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setBases1(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBases1 = nValue;
        setHasBases1();
    }
    glodon::objectbuf::EntityRef getBases1() const {return m_nBases1;}
    bool hasBases1() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Surface* getBases1Ptr() const {return (Gfc2Surface*)m_pDocument->find(getBases1());}
    void setBases2(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBases2 = nValue;
        setHasBases2();
    }
    glodon::objectbuf::EntityRef getBases2() const {return m_nBases2;}
    bool hasBases2() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Surface* getBases2Ptr() const {return (Gfc2Surface*)m_pDocument->find(getBases2());}
    void setRange(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRange = nValue;
        setHasRange();
    }
    glodon::objectbuf::EntityRef getRange() const {return m_nRange;}
    bool hasRange() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Intervald* getRangePtr() const {return (Gfc2Intervald*)m_pDocument->find(getRange());}
    void setChart(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nChart = nValue;
        setHasChart();
    }
    glodon::objectbuf::EntityRef getChart() const {return m_nChart;}
    bool hasChart() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2InternalChart* getChartPtr() const {return (Gfc2InternalChart*)m_pDocument->find(getChart());}

private:
    void setHasBases1() {_has_bits_[0] |= 0x1u;}
    void setHasBases2() {_has_bits_[0] |= 0x2u;}
    void setHasRange() {_has_bits_[0] |= 0x4u;}
    void setHasChart() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nBases1;
    glodon::objectbuf::EntityRef m_nBases2;
    glodon::objectbuf::EntityRef m_nRange;
    glodon::objectbuf::EntityRef m_nChart;
};

class GFCCLASSES_API Gfc2IntersectionCurve3dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2IntersectionCurve3dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
