#ifndef GFC2CONNECTIONSURFACEGEOMETRY_H
#define GFC2CONNECTIONSURFACEGEOMETRY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ConnectionGeometry.h"
#include "Gfc2Surface.h"
#include "Gfc2Surface.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ConnectionSurfaceGeometry: public Gfc2ConnectionGeometry
{
OBJECTBUF_DEC_OBJECT(Gfc2ConnectionSurfaceGeometry,glodon::objectbuf::Entity)
public:
    Gfc2ConnectionSurfaceGeometry();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setSurfaceOnRelatingElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSurfaceOnRelatingElement = nValue;
        setHasSurfaceOnRelatingElement();
    }
    glodon::objectbuf::EntityRef getSurfaceOnRelatingElement() const {return m_nSurfaceOnRelatingElement;}
    bool hasSurfaceOnRelatingElement() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Surface* getSurfaceOnRelatingElementPtr() const {return (Gfc2Surface*)m_pDocument->find(getSurfaceOnRelatingElement());}
    void setSurfaceOnRelatedElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSurfaceOnRelatedElement = nValue;
        setHasSurfaceOnRelatedElement();
    }
    glodon::objectbuf::EntityRef getSurfaceOnRelatedElement() const {return m_nSurfaceOnRelatedElement;}
    bool hasSurfaceOnRelatedElement() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Surface* getSurfaceOnRelatedElementPtr() const {return (Gfc2Surface*)m_pDocument->find(getSurfaceOnRelatedElement());}

private:
    void setHasSurfaceOnRelatingElement() {_has_bits_[0] |= 0x1u;}
    void setHasSurfaceOnRelatedElement() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nSurfaceOnRelatingElement;
    glodon::objectbuf::EntityRef m_nSurfaceOnRelatedElement;
};
#endif
