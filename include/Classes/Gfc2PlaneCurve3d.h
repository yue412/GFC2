#ifndef GFC2PLANECURVE3D_H
#define GFC2PLANECURVE3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve3d.h"
#include "Gfc2Curve2d.h"
#include "Gfc2PlaneInfo.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2PlaneCurve3d: public Gfc2Curve3d
{
OBJECTBUF_DEC_OBJECT(Gfc2PlaneCurve3d,glodon::objectbuf::Entity)
public:
    Gfc2PlaneCurve3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPlaneCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPlaneCurve = nValue;
        setHasPlaneCurve();
    }
    glodon::objectbuf::EntityRef getPlaneCurve() const {return m_nPlaneCurve;}
    bool hasPlaneCurve() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Curve2d* getPlaneCurvePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getPlaneCurve());}
    void setPlane(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPlane = nValue;
        setHasPlane();
    }
    glodon::objectbuf::EntityRef getPlane() const {return m_nPlane;}
    bool hasPlane() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2PlaneInfo* getPlanePtr() const {return (Gfc2PlaneInfo*)m_pDocument->find(getPlane());}

private:
    void setHasPlaneCurve() {_has_bits_[0] |= 0x1u;}
    void setHasPlane() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nPlaneCurve;
    glodon::objectbuf::EntityRef m_nPlane;
};

class GFCCLASSES_API Gfc2PlaneCurve3dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PlaneCurve3dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
