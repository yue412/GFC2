#ifndef GFC2STATESET_H
#define GFC2STATESET_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2StateSet: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2StateSet,glodon::objectbuf::Entity)
public:
    Gfc2StateSet();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setAmbient(const Gfc2Integer& nValue)
    {
        m_nAmbient = nValue;
        setHasAmbient();
    }
    Gfc2Integer getAmbient() const {return m_nAmbient;}
    bool hasAmbient() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setDiffuse(const Gfc2Integer& nValue)
    {
        m_nDiffuse = nValue;
        setHasDiffuse();
    }
    Gfc2Integer getDiffuse() const {return m_nDiffuse;}
    bool hasDiffuse() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setSourceBlendFactor(const Gfc2SceneBlendFactor& nValue)
    {
        m_nSourceBlendFactor = nValue;
        setHasSourceBlendFactor();
    }
    Gfc2SceneBlendFactor getSourceBlendFactor() const {return m_nSourceBlendFactor;}
    bool hasSourceBlendFactor() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setDestBlendFactor(const Gfc2SceneBlendFactor& nValue)
    {
        m_nDestBlendFactor = nValue;
        setHasDestBlendFactor();
    }
    Gfc2SceneBlendFactor getDestBlendFactor() const {return m_nDestBlendFactor;}
    bool hasDestBlendFactor() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setDepthTestEnabled(const Gfc2Boolean& bValue)
    {
        m_bDepthTestEnabled = bValue;
        setHasDepthTestEnabled();
    }
    Gfc2Boolean getDepthTestEnabled() const {return m_bDepthTestEnabled;}
    bool hasDepthTestEnabled() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setDepthWriteEnabled(const Gfc2Boolean& bValue)
    {
        m_bDepthWriteEnabled = bValue;
        setHasDepthWriteEnabled();
    }
    Gfc2Boolean getDepthWriteEnabled() const {return m_bDepthWriteEnabled;}
    bool hasDepthWriteEnabled() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setDepthTestFunction(const Gfc2FragTestFunc& nValue)
    {
        m_nDepthTestFunction = nValue;
        setHasDepthTestFunction();
    }
    Gfc2FragTestFunc getDepthTestFunction() const {return m_nDepthTestFunction;}
    bool hasDepthTestFunction() const {return (_has_bits_[0] & 0x40u) != 0;}
    void setPolygonOffsetFactor(const Gfc2Double& dValue)
    {
        m_dPolygonOffsetFactor = dValue;
        setHasPolygonOffsetFactor();
    }
    Gfc2Double getPolygonOffsetFactor() const {return m_dPolygonOffsetFactor;}
    bool hasPolygonOffsetFactor() const {return (_has_bits_[0] & 0x80u) != 0;}
    void setPolygonOffsetUnits(const Gfc2Double& dValue)
    {
        m_dPolygonOffsetUnits = dValue;
        setHasPolygonOffsetUnits();
    }
    Gfc2Double getPolygonOffsetUnits() const {return m_dPolygonOffsetUnits;}
    bool hasPolygonOffsetUnits() const {return (_has_bits_[0] & 0x100u) != 0;}
    void setPolygonStipple(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPolygonStipple = nValue;
        setHasPolygonStipple();
    }
    glodon::objectbuf::EntityRef getPolygonStipple() const {return m_nPolygonStipple;}
    bool hasPolygonStipple() const {return (_has_bits_[0] & 0x200u) != 0;}
    Gfc2String* getPolygonStipplePtr() const {return (Gfc2String*)m_pDocument->find(getPolygonStipple());}
    void setLineStipplePattern(const Gfc2Integer& nValue)
    {
        m_nLineStipplePattern = nValue;
        setHasLineStipplePattern();
    }
    Gfc2Integer getLineStipplePattern() const {return m_nLineStipplePattern;}
    bool hasLineStipplePattern() const {return (_has_bits_[0] & 0x400u) != 0;}
    void setLineStippleFactor(const Gfc2Integer& nValue)
    {
        m_nLineStippleFactor = nValue;
        setHasLineStippleFactor();
    }
    Gfc2Integer getLineStippleFactor() const {return m_nLineStippleFactor;}
    bool hasLineStippleFactor() const {return (_has_bits_[0] & 0x800u) != 0;}
    void setFaceMode(const Gfc2FaceMode& nValue)
    {
        m_nFaceMode = nValue;
        setHasFaceMode();
    }
    Gfc2FaceMode getFaceMode() const {return m_nFaceMode;}
    bool hasFaceMode() const {return (_has_bits_[0] & 0x1000u) != 0;}
    void setLightingEnabled(const Gfc2Boolean& bValue)
    {
        m_bLightingEnabled = bValue;
        setHasLightingEnabled();
    }
    Gfc2Boolean getLightingEnabled() const {return m_bLightingEnabled;}
    bool hasLightingEnabled() const {return (_has_bits_[0] & 0x2000u) != 0;}
    void setLightModelTwoSided(const Gfc2Boolean& bValue)
    {
        m_bLightModelTwoSided = bValue;
        setHasLightModelTwoSided();
    }
    Gfc2Boolean getLightModelTwoSided() const {return m_bLightModelTwoSided;}
    bool hasLightModelTwoSided() const {return (_has_bits_[0] & 0x4000u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasAmbient() {_has_bits_[0] |= 0x1u;}
    void setHasDiffuse() {_has_bits_[0] |= 0x2u;}
    void setHasSourceBlendFactor() {_has_bits_[0] |= 0x4u;}
    void setHasDestBlendFactor() {_has_bits_[0] |= 0x8u;}
    void setHasDepthTestEnabled() {_has_bits_[0] |= 0x10u;}
    void setHasDepthWriteEnabled() {_has_bits_[0] |= 0x20u;}
    void setHasDepthTestFunction() {_has_bits_[0] |= 0x40u;}
    void setHasPolygonOffsetFactor() {_has_bits_[0] |= 0x80u;}
    void setHasPolygonOffsetUnits() {_has_bits_[0] |= 0x100u;}
    void setHasPolygonStipple() {_has_bits_[0] |= 0x200u;}
    void setHasLineStipplePattern() {_has_bits_[0] |= 0x400u;}
    void setHasLineStippleFactor() {_has_bits_[0] |= 0x800u;}
    void setHasFaceMode() {_has_bits_[0] |= 0x1000u;}
    void setHasLightingEnabled() {_has_bits_[0] |= 0x2000u;}
    void setHasLightModelTwoSided() {_has_bits_[0] |= 0x4000u;}

    Gfc2Integer m_nAmbient;
    Gfc2Integer m_nDiffuse;
    Gfc2SceneBlendFactor m_nSourceBlendFactor;
    Gfc2SceneBlendFactor m_nDestBlendFactor;
    Gfc2Boolean m_bDepthTestEnabled;
    Gfc2Boolean m_bDepthWriteEnabled;
    Gfc2FragTestFunc m_nDepthTestFunction;
    Gfc2Double m_dPolygonOffsetFactor;
    Gfc2Double m_dPolygonOffsetUnits;
    glodon::objectbuf::EntityRef m_nPolygonStipple;
    Gfc2Integer m_nLineStipplePattern;
    Gfc2Integer m_nLineStippleFactor;
    Gfc2FaceMode m_nFaceMode;
    Gfc2Boolean m_bLightingEnabled;
    Gfc2Boolean m_bLightModelTwoSided;
};

class GFCCLASSES_API Gfc2StateSetFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2StateSetFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
