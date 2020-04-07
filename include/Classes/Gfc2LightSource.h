#ifndef GFC2LIGHTSOURCE_H
#define GFC2LIGHTSOURCE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RepresentationItem.h"
#include "Gfc2Color.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2LightSource: public Gfc2RepresentationItem
{
OBJECTBUF_DEC_OBJECT(Gfc2LightSource,glodon::objectbuf::Entity)
public:
    Gfc2LightSource();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setName(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nName = nValue;
        setHasName();
    }
    glodon::objectbuf::EntityRef getName() const {return m_nName;}
    bool hasName() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Label* getNamePtr() const {return (Gfc2Label*)m_pDocument->find(getName());}
    void setLightColour(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nLightColour = nValue;
        setHasLightColour();
    }
    glodon::objectbuf::EntityRef getLightColour() const {return m_nLightColour;}
    bool hasLightColour() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Color* getLightColourPtr() const {return (Gfc2Color*)m_pDocument->find(getLightColour());}
    void setAmbientIntensity(const Gfc2Double& dValue)
    {
        m_dAmbientIntensity = dValue;
        setHasAmbientIntensity();
    }
    Gfc2Double getAmbientIntensity() const {return m_dAmbientIntensity;}
    bool hasAmbientIntensity() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setIntensity(const Gfc2Double& dValue)
    {
        m_dIntensity = dValue;
        setHasIntensity();
    }
    Gfc2Double getIntensity() const {return m_dIntensity;}
    bool hasIntensity() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasName() {_has_bits_[0] |= 0x1u;}
    void setHasLightColour() {_has_bits_[0] |= 0x2u;}
    void setHasAmbientIntensity() {_has_bits_[0] |= 0x4u;}
    void setHasIntensity() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nName;
    glodon::objectbuf::EntityRef m_nLightColour;
    Gfc2Double m_dAmbientIntensity;
    Gfc2Double m_dIntensity;
};
#endif
