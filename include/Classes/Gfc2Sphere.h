#ifndef GFC2SPHERE_H
#define GFC2SPHERE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Intervald.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Sphere: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2Sphere,glodon::objectbuf::Entity)
public:
    Gfc2Sphere();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setCoords(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCoords = nValue;
        setHasCoords();
    }
    glodon::objectbuf::EntityRef getCoords() const {return m_nCoords;}
    bool hasCoords() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Coordinates3d* getCoordsPtr() const {return (Gfc2Coordinates3d*)m_pDocument->find(getCoords());}
    void setRangeU(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeU = nValue;
        setHasRangeU();
    }
    glodon::objectbuf::EntityRef getRangeU() const {return m_nRangeU;}
    bool hasRangeU() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Intervald* getRangeUPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeU());}
    void setRangeV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeV = nValue;
        setHasRangeV();
    }
    glodon::objectbuf::EntityRef getRangeV() const {return m_nRangeV;}
    bool hasRangeV() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Intervald* getRangeVPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeV());}

private:
    void setHasRadius() {_has_bits_[0] |= 0x1u;}
    void setHasCoords() {_has_bits_[0] |= 0x2u;}
    void setHasRangeU() {_has_bits_[0] |= 0x4u;}
    void setHasRangeV() {_has_bits_[0] |= 0x8u;}

    Gfc2Double m_dRadius;
    glodon::objectbuf::EntityRef m_nCoords;
    glodon::objectbuf::EntityRef m_nRangeU;
    glodon::objectbuf::EntityRef m_nRangeV;
};
#endif
