#ifndef GFC2HERMITECURVE2D_H
#define GFC2HERMITECURVE2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve2d.h"
#include "Gfc2HermiteCtrlPt2d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2HermiteCurve2d: public Gfc2Curve2d
{
OBJECTBUF_DEC_OBJECT(Gfc2HermiteCurve2d,glodon::objectbuf::Entity)
public:
    Gfc2HermiteCurve2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getCtrlPtsCount() const {return (int)m_oCtrlPts.size();}
    void clearCtrlPts() {m_oCtrlPts.clear();}
    void addCtrlPts(const glodon::objectbuf::EntityRef& nValue) {m_oCtrlPts.push_back(nValue);}
    glodon::objectbuf::EntityRef getCtrlPts(int nIndex) const {return m_oCtrlPts[nIndex];}
    Gfc2HermiteCtrlPt2d* getCtrlPtsPtr(int nIndex) const {return (Gfc2HermiteCtrlPt2d*)m_pDocument->find(getCtrlPts(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oCtrlPts;
};

class GFCCLASSES_API Gfc2HermiteCurve2dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2HermiteCurve2dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
