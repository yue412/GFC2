#ifndef GFC2CONNECTIONPOINTGEOMETRY_H
#define GFC2CONNECTIONPOINTGEOMETRY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ConnectionGeometry.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ConnectionPointGeometry: public Gfc2ConnectionGeometry
{
OBJECTBUF_DEC_OBJECT(Gfc2ConnectionPointGeometry,glodon::objectbuf::Entity)
public:
    Gfc2ConnectionPointGeometry();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPointOnRelatingElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPointOnRelatingElement = nValue;
        setHasPointOnRelatingElement();
    }
    glodon::objectbuf::EntityRef getPointOnRelatingElement() const {return m_nPointOnRelatingElement;}
    bool hasPointOnRelatingElement() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector3d* getPointOnRelatingElementPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getPointOnRelatingElement());}
    void setPointOnRelatedElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPointOnRelatedElement = nValue;
        setHasPointOnRelatedElement();
    }
    glodon::objectbuf::EntityRef getPointOnRelatedElement() const {return m_nPointOnRelatedElement;}
    bool hasPointOnRelatedElement() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector3d* getPointOnRelatedElementPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getPointOnRelatedElement());}

private:
    void setHasPointOnRelatingElement() {_has_bits_[0] |= 0x1u;}
    void setHasPointOnRelatedElement() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nPointOnRelatingElement;
    glodon::objectbuf::EntityRef m_nPointOnRelatedElement;
};
#endif
