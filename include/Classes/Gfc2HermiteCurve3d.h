#ifndef GFC2HERMITECURVE3D_H
#define GFC2HERMITECURVE3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve3d.h"
#include "Gfc2HermiteCtrlPt3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2HermiteCurve3d: public Gfc2Curve3d
{
OBJECTBUF_DEC_OBJECT(Gfc2HermiteCurve3d,glodon::objectbuf::Entity)
public:
    Gfc2HermiteCurve3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getCtrlPtsCount() const {return (int)m_oCtrlPts.size();}
    void clearCtrlPts() {m_oCtrlPts.clear();}
    void addCtrlPts(const glodon::objectbuf::EntityRef& nValue) {m_oCtrlPts.push_back(nValue);}
    glodon::objectbuf::EntityRef getCtrlPts(int nIndex) const {return m_oCtrlPts[nIndex];}
    Gfc2HermiteCtrlPt3d* getCtrlPtsPtr(int nIndex) const {return (Gfc2HermiteCtrlPt3d*)m_pDocument->find(getCtrlPts(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oCtrlPts;
};

class GFCCLASSES_API Gfc2HermiteCurve3dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2HermiteCurve3dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
