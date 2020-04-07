#ifndef GFC2LIGHTSOURCEPOSITIONAL_H
#define GFC2LIGHTSOURCEPOSITIONAL_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2LightSource.h"
#include "Gfc2Vector3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2LightSourcePositional: public Gfc2LightSource
{
OBJECTBUF_DEC_OBJECT(Gfc2LightSourcePositional,glodon::objectbuf::Entity)
public:
    Gfc2LightSourcePositional();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPosition(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPosition = nValue;
        setHasPosition();
    }
    glodon::objectbuf::EntityRef getPosition() const {return m_nPosition;}
    bool hasPosition() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Vector3d* getPositionPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getPosition());}
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setConstantAttenuation(const Gfc2Double& dValue)
    {
        m_dConstantAttenuation = dValue;
        setHasConstantAttenuation();
    }
    Gfc2Double getConstantAttenuation() const {return m_dConstantAttenuation;}
    bool hasConstantAttenuation() const {return (_has_bits_[0] & 0x40u) != 0;}
    void setDistanceAttenuation(const Gfc2Double& dValue)
    {
        m_dDistanceAttenuation = dValue;
        setHasDistanceAttenuation();
    }
    Gfc2Double getDistanceAttenuation() const {return m_dDistanceAttenuation;}
    bool hasDistanceAttenuation() const {return (_has_bits_[0] & 0x80u) != 0;}
    void setQuadricAttenuation(const Gfc2Double& dValue)
    {
        m_dQuadricAttenuation = dValue;
        setHasQuadricAttenuation();
    }
    Gfc2Double getQuadricAttenuation() const {return m_dQuadricAttenuation;}
    bool hasQuadricAttenuation() const {return (_has_bits_[0] & 0x100u) != 0;}

private:
    void setHasPosition() {_has_bits_[0] |= 0x10u;}
    void setHasRadius() {_has_bits_[0] |= 0x20u;}
    void setHasConstantAttenuation() {_has_bits_[0] |= 0x40u;}
    void setHasDistanceAttenuation() {_has_bits_[0] |= 0x80u;}
    void setHasQuadricAttenuation() {_has_bits_[0] |= 0x100u;}

    glodon::objectbuf::EntityRef m_nPosition;
    Gfc2Double m_dRadius;
    Gfc2Double m_dConstantAttenuation;
    Gfc2Double m_dDistanceAttenuation;
    Gfc2Double m_dQuadricAttenuation;
};
#endif
