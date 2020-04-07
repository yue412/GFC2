#ifndef GFC2REVOLVEDAREASOLIDSHAPE_H
#define GFC2REVOLVEDAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RevolvedAreaSolidShape: public Gfc2SweptAreaSolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2RevolvedAreaSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2RevolvedAreaSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setAxis(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nAxis = nValue;
        setHasAxis();
    }
    glodon::objectbuf::EntityRef getAxis() const {return m_nAxis;}
    bool hasAxis() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Vector2d* getAxisPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getAxis());}
    void setAngle(const Gfc2Double& dValue)
    {
        m_dAngle = dValue;
        setHasAngle();
    }
    Gfc2Double getAngle() const {return m_dAngle;}
    bool hasAngle() const {return (_has_bits_[0] & 0x10u) != 0;}

private:
    void setHasAxis() {_has_bits_[0] |= 0x8u;}
    void setHasAngle() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nAxis;
    Gfc2Double m_dAngle;
};
#endif
