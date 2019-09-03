#ifndef GFC2INTERNALCHART_H
#define GFC2INTERNALCHART_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2InternalPt.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2InternalChart: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2InternalChart,glodon::objectbuf::Entity)
public:
    Gfc2InternalChart();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setTra1(const Gfc2Double& dValue)
    {
        m_dTra1 = dValue;
        setHasTra1();
    }
    Gfc2Double getTra1() const {return m_dTra1;}
    bool hasTra1() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setTra2(const Gfc2Double& dValue)
    {
        m_dTra2 = dValue;
        setHasTra2();
    }
    Gfc2Double getTra2() const {return m_dTra2;}
    bool hasTra2() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setTra3(const Gfc2Double& dValue)
    {
        m_dTra3 = dValue;
        setHasTra3();
    }
    Gfc2Double getTra3() const {return m_dTra3;}
    bool hasTra3() const {return (_has_bits_[0] & 0x4u) != 0;}
    int getIPSCount() const {return (int)m_oIPS.size();}
    void clearIPS() {m_oIPS.clear();}
    void addIPS(const glodon::objectbuf::EntityRef& nValue) {m_oIPS.push_back(nValue);}
    glodon::objectbuf::EntityRef getIPS(int nIndex) const {return m_oIPS[nIndex];}
    Gfc2InternalPt* getIPSPtr(int nIndex) const {return (Gfc2InternalPt*)m_pDocument->find(getIPS(nIndex));}

protected:
    unsigned _has_bits_[1];
private:
    void setHasTra1() {_has_bits_[0] |= 0x1u;}
    void setHasTra2() {_has_bits_[0] |= 0x2u;}
    void setHasTra3() {_has_bits_[0] |= 0x4u;}

    Gfc2Double m_dTra1;
    Gfc2Double m_dTra2;
    Gfc2Double m_dTra3;
    std::vector<glodon::objectbuf::EntityRef> m_oIPS;
};

class GFCCLASSES_API Gfc2InternalChartFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2InternalChartFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
