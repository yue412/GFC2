#ifndef GFC2BEVEL_H
#define GFC2BEVEL_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Surface.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Intervald.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Bevel: public Gfc2Surface
{
OBJECTBUF_DEC_OBJECT(Gfc2Bevel,glodon::objectbuf::Entity)
public:
    Gfc2Bevel();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCoord(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCoord = nValue;
        setHasCoord();
    }
    glodon::objectbuf::EntityRef getCoord() const {return m_nCoord;}
    bool hasCoord() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Coordinates3d* getCoordPtr() const {return (Gfc2Coordinates3d*)m_pDocument->find(getCoord());}
    void setHeight(const Gfc2Double& dValue)
    {
        m_dHeight = dValue;
        setHasHeight();
    }
    Gfc2Double getHeight() const {return m_dHeight;}
    bool hasHeight() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setRangeV(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRangeV = nValue;
        setHasRangeV();
    }
    glodon::objectbuf::EntityRef getRangeV() const {return m_nRangeV;}
    bool hasRangeV() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Intervald* getRangeVPtr() const {return (Gfc2Intervald*)m_pDocument->find(getRangeV());}
    void setCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurve = nValue;
        setHasCurve();
    }
    glodon::objectbuf::EntityRef getCurve() const {return m_nCurve;}
    bool hasCurve() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Curve2d* getCurvePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getCurve());}

private:
    void setHasCoord() {_has_bits_[0] |= 0x1u;}
    void setHasHeight() {_has_bits_[0] |= 0x2u;}
    void setHasRangeV() {_has_bits_[0] |= 0x4u;}
    void setHasCurve() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nCoord;
    Gfc2Double m_dHeight;
    glodon::objectbuf::EntityRef m_nRangeV;
    glodon::objectbuf::EntityRef m_nCurve;
};

class GFCCLASSES_API Gfc2BevelFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2BevelFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
