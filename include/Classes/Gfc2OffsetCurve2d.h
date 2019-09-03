#ifndef GFC2OFFSETCURVE2D_H
#define GFC2OFFSETCURVE2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2OffsetCurve2d: public Gfc2Curve2d
{
OBJECTBUF_DEC_OBJECT(Gfc2OffsetCurve2d,glodon::objectbuf::Entity)
public:
    Gfc2OffsetCurve2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setOffDist(const Gfc2Double& dValue)
    {
        m_dOffDist = dValue;
        setHasOffDist();
    }
    Gfc2Double getOffDist() const {return m_dOffDist;}
    bool hasOffDist() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setInitCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nInitCurve = nValue;
        setHasInitCurve();
    }
    glodon::objectbuf::EntityRef getInitCurve() const {return m_nInitCurve;}
    bool hasInitCurve() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Curve2d* getInitCurvePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getInitCurve());}

private:
    void setHasOffDist() {_has_bits_[0] |= 0x1u;}
    void setHasInitCurve() {_has_bits_[0] |= 0x2u;}

    Gfc2Double m_dOffDist;
    glodon::objectbuf::EntityRef m_nInitCurve;
};

class GFCCLASSES_API Gfc2OffsetCurve2dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2OffsetCurve2dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
