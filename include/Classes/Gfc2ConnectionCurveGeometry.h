#ifndef GFC2CONNECTIONCURVEGEOMETRY_H
#define GFC2CONNECTIONCURVEGEOMETRY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ConnectionGeometry.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Curve3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ConnectionCurveGeometry: public Gfc2ConnectionGeometry
{
OBJECTBUF_DEC_OBJECT(Gfc2ConnectionCurveGeometry,glodon::objectbuf::Entity)
public:
    Gfc2ConnectionCurveGeometry();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCurveOnRelatingElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurveOnRelatingElement = nValue;
        setHasCurveOnRelatingElement();
    }
    glodon::objectbuf::EntityRef getCurveOnRelatingElement() const {return m_nCurveOnRelatingElement;}
    bool hasCurveOnRelatingElement() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Curve3d* getCurveOnRelatingElementPtr() const {return (Gfc2Curve3d*)m_pDocument->find(getCurveOnRelatingElement());}
    void setCurveOnRelatedElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurveOnRelatedElement = nValue;
        setHasCurveOnRelatedElement();
    }
    glodon::objectbuf::EntityRef getCurveOnRelatedElement() const {return m_nCurveOnRelatedElement;}
    bool hasCurveOnRelatedElement() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Curve3d* getCurveOnRelatedElementPtr() const {return (Gfc2Curve3d*)m_pDocument->find(getCurveOnRelatedElement());}

private:
    void setHasCurveOnRelatingElement() {_has_bits_[0] |= 0x1u;}
    void setHasCurveOnRelatedElement() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nCurveOnRelatingElement;
    glodon::objectbuf::EntityRef m_nCurveOnRelatedElement;
};
#endif
