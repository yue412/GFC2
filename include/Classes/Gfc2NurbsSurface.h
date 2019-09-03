#ifndef GFC2NURBSSURFACE_H
#define GFC2NURBSSURFACE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2NurbsCtrlPt3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2NurbsSurface: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2NurbsSurface,glodon::objectbuf::Entity)
public:
    Gfc2NurbsSurface();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setDegreeU(const Gfc2Integer& nValue)
    {
        m_nDegreeU = nValue;
        setHasDegreeU();
    }
    Gfc2Integer getDegreeU() const {return m_nDegreeU;}
    bool hasDegreeU() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setDegreeV(const Gfc2Integer& nValue)
    {
        m_nDegreeV = nValue;
        setHasDegreeV();
    }
    Gfc2Integer getDegreeV() const {return m_nDegreeV;}
    bool hasDegreeV() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setCtrlPtCountU(const Gfc2Integer& nValue)
    {
        m_nCtrlPtCountU = nValue;
        setHasCtrlPtCountU();
    }
    Gfc2Integer getCtrlPtCountU() const {return m_nCtrlPtCountU;}
    bool hasCtrlPtCountU() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setCtrlPtCountV(const Gfc2Integer& nValue)
    {
        m_nCtrlPtCountV = nValue;
        setHasCtrlPtCountV();
    }
    Gfc2Integer getCtrlPtCountV() const {return m_nCtrlPtCountV;}
    bool hasCtrlPtCountV() const {return (_has_bits_[0] & 0x8u) != 0;}
    int getCtrlPtsCount() const {return (int)m_oCtrlPts.size();}
    void clearCtrlPts() {m_oCtrlPts.clear();}
    void addCtrlPts(const glodon::objectbuf::EntityRef& nValue) {m_oCtrlPts.push_back(nValue);}
    glodon::objectbuf::EntityRef getCtrlPts(int nIndex) const {return m_oCtrlPts[nIndex];}
    Gfc2NurbsCtrlPt3d* getCtrlPtsPtr(int nIndex) const {return (Gfc2NurbsCtrlPt3d*)m_pDocument->find(getCtrlPts(nIndex));}
    int getKnotsUCount() const {return (int)m_oKnotsU.size();}
    void clearKnotsU() {m_oKnotsU.clear();}
    void addKnotsU(const Gfc2Double& dValue) {m_oKnotsU.push_back(dValue);}
    Gfc2Double getKnotsU(int nIndex) const {return m_oKnotsU[nIndex];}
    int getKnotsVCount() const {return (int)m_oKnotsV.size();}
    void clearKnotsV() {m_oKnotsV.clear();}
    void addKnotsV(const Gfc2Double& dValue) {m_oKnotsV.push_back(dValue);}
    Gfc2Double getKnotsV(int nIndex) const {return m_oKnotsV[nIndex];}

private:
    void setHasDegreeU() {_has_bits_[0] |= 0x1u;}
    void setHasDegreeV() {_has_bits_[0] |= 0x2u;}
    void setHasCtrlPtCountU() {_has_bits_[0] |= 0x4u;}
    void setHasCtrlPtCountV() {_has_bits_[0] |= 0x8u;}

    Gfc2Integer m_nDegreeU;
    Gfc2Integer m_nDegreeV;
    Gfc2Integer m_nCtrlPtCountU;
    Gfc2Integer m_nCtrlPtCountV;
    std::vector<glodon::objectbuf::EntityRef> m_oCtrlPts;
    std::vector<Gfc2Double> m_oKnotsU;
    std::vector<Gfc2Double> m_oKnotsV;
};

class GFCCLASSES_API Gfc2NurbsSurfaceFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2NurbsSurfaceFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
