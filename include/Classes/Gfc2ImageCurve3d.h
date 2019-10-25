#ifndef GFC2IMAGECURVE3D_H
#define GFC2IMAGECURVE3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve3d.h"
#include "Gfc2Curve2d.h"
#include "Gfc2Surface.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ImageCurve3d: public Gfc2Curve3d
{
OBJECTBUF_DEC_OBJECT(Gfc2ImageCurve3d,glodon::objectbuf::Entity)
public:
    Gfc2ImageCurve3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurve = nValue;
        setHasCurve();
    }
    glodon::objectbuf::EntityRef getCurve() const {return m_nCurve;}
    bool hasCurve() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Curve2d* getCurvePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getCurve());}
    void setSurface(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSurface = nValue;
        setHasSurface();
    }
    glodon::objectbuf::EntityRef getSurface() const {return m_nSurface;}
    bool hasSurface() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Surface* getSurfacePtr() const {return (Gfc2Surface*)m_pDocument->find(getSurface());}

private:
    void setHasCurve() {_has_bits_[0] |= 0x1u;}
    void setHasSurface() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nCurve;
    glodon::objectbuf::EntityRef m_nSurface;
};
#endif
