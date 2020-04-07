#ifndef GFC2CONNECTIONVOLUMEGEOMETRY_H
#define GFC2CONNECTIONVOLUMEGEOMETRY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ConnectionGeometry.h"
#include "Gfc2Body.h"
#include "Gfc2Body.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ConnectionVolumeGeometry: public Gfc2ConnectionGeometry
{
OBJECTBUF_DEC_OBJECT(Gfc2ConnectionVolumeGeometry,glodon::objectbuf::Entity)
public:
    Gfc2ConnectionVolumeGeometry();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setVolumeOnRelatingElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nVolumeOnRelatingElement = nValue;
        setHasVolumeOnRelatingElement();
    }
    glodon::objectbuf::EntityRef getVolumeOnRelatingElement() const {return m_nVolumeOnRelatingElement;}
    bool hasVolumeOnRelatingElement() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Body* getVolumeOnRelatingElementPtr() const {return (Gfc2Body*)m_pDocument->find(getVolumeOnRelatingElement());}
    void setVolumeOnRelatedElement(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nVolumeOnRelatedElement = nValue;
        setHasVolumeOnRelatedElement();
    }
    glodon::objectbuf::EntityRef getVolumeOnRelatedElement() const {return m_nVolumeOnRelatedElement;}
    bool hasVolumeOnRelatedElement() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Body* getVolumeOnRelatedElementPtr() const {return (Gfc2Body*)m_pDocument->find(getVolumeOnRelatedElement());}

private:
    void setHasVolumeOnRelatingElement() {_has_bits_[0] |= 0x1u;}
    void setHasVolumeOnRelatedElement() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nVolumeOnRelatingElement;
    glodon::objectbuf::EntityRef m_nVolumeOnRelatedElement;
};
#endif
