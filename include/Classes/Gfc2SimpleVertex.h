#ifndef GFC2SIMPLEVERTEX_H
#define GFC2SIMPLEVERTEX_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SimpleVertex: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2SimpleVertex,glodon::objectbuf::Entity)
public:
    Gfc2SimpleVertex();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPoint = nValue;
        setHasPoint();
    }
    glodon::objectbuf::EntityRef getPoint() const {return m_nPoint;}
    bool hasPoint() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector2d* getPointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getPoint());}
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setArcType(const Gfc2ArcType& nValue)
    {
        m_nArcType = nValue;
        setHasArcType();
    }
    Gfc2ArcType getArcType() const {return m_nArcType;}
    bool hasArcType() const {return (_has_bits_[0] & 0x4u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasPoint() {_has_bits_[0] |= 0x1u;}
    void setHasRadius() {_has_bits_[0] |= 0x2u;}
    void setHasArcType() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nPoint;
    Gfc2Double m_dRadius;
    Gfc2ArcType m_nArcType;
};
#endif
