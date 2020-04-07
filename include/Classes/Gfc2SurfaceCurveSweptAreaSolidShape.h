#ifndef GFC2SURFACECURVESWEPTAREASOLIDSHAPE_H
#define GFC2SURFACECURVESWEPTAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Surface.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SurfaceCurveSweptAreaSolidShape: public Gfc2SweptAreaSolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2SurfaceCurveSweptAreaSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2SurfaceCurveSweptAreaSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setDirectrix(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nDirectrix = nValue;
        setHasDirectrix();
    }
    glodon::objectbuf::EntityRef getDirectrix() const {return m_nDirectrix;}
    bool hasDirectrix() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Curve3d* getDirectrixPtr() const {return (Gfc2Curve3d*)m_pDocument->find(getDirectrix());}
    void setReferenceSurface(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nReferenceSurface = nValue;
        setHasReferenceSurface();
    }
    glodon::objectbuf::EntityRef getReferenceSurface() const {return m_nReferenceSurface;}
    bool hasReferenceSurface() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Surface* getReferenceSurfacePtr() const {return (Gfc2Surface*)m_pDocument->find(getReferenceSurface());}

private:
    void setHasDirectrix() {_has_bits_[0] |= 0x8u;}
    void setHasReferenceSurface() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nDirectrix;
    glodon::objectbuf::EntityRef m_nReferenceSurface;
};
#endif
