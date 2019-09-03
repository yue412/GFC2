#ifndef GFC2NURBSCURVE3D_H
#define GFC2NURBSCURVE3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve3d.h"
#include "Gfc2NurbsCtrlPt3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2NurbsCurve3d: public Gfc2Curve3d
{
OBJECTBUF_DEC_OBJECT(Gfc2NurbsCurve3d,glodon::objectbuf::Entity)
public:
    Gfc2NurbsCurve3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setDegree(const Gfc2Integer& nValue)
    {
        m_nDegree = nValue;
        setHasDegree();
    }
    Gfc2Integer getDegree() const {return m_nDegree;}
    bool hasDegree() const {return (_has_bits_[0] & 0x1u) != 0;}
    int getCtrlPtsCount() const {return (int)m_oCtrlPts.size();}
    void clearCtrlPts() {m_oCtrlPts.clear();}
    void addCtrlPts(const glodon::objectbuf::EntityRef& nValue) {m_oCtrlPts.push_back(nValue);}
    glodon::objectbuf::EntityRef getCtrlPts(int nIndex) const {return m_oCtrlPts[nIndex];}
    Gfc2NurbsCtrlPt3d* getCtrlPtsPtr(int nIndex) const {return (Gfc2NurbsCtrlPt3d*)m_pDocument->find(getCtrlPts(nIndex));}
    int getKnotsCount() const {return (int)m_oKnots.size();}
    void clearKnots() {m_oKnots.clear();}
    void addKnots(const Gfc2Double& dValue) {m_oKnots.push_back(dValue);}
    Gfc2Double getKnots(int nIndex) const {return m_oKnots[nIndex];}

private:
    void setHasDegree() {_has_bits_[0] |= 0x1u;}

    Gfc2Integer m_nDegree;
    std::vector<glodon::objectbuf::EntityRef> m_oCtrlPts;
    std::vector<Gfc2Double> m_oKnots;
};

class GFCCLASSES_API Gfc2NurbsCurve3dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2NurbsCurve3dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
