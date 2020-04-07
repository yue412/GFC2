#ifndef GFC2EXTRUDEDAREASOLIDSHAPE_H
#define GFC2EXTRUDEDAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Vector3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ExtrudedAreaSolidShape: public Gfc2SweptAreaSolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2ExtrudedAreaSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2ExtrudedAreaSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setExtrudedDirection(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nExtrudedDirection = nValue;
        setHasExtrudedDirection();
    }
    glodon::objectbuf::EntityRef getExtrudedDirection() const {return m_nExtrudedDirection;}
    bool hasExtrudedDirection() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Vector3d* getExtrudedDirectionPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getExtrudedDirection());}
    void setLength(const Gfc2Double& dValue)
    {
        m_dLength = dValue;
        setHasLength();
    }
    Gfc2Double getLength() const {return m_dLength;}
    bool hasLength() const {return (_has_bits_[0] & 0x10u) != 0;}

private:
    void setHasExtrudedDirection() {_has_bits_[0] |= 0x8u;}
    void setHasLength() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nExtrudedDirection;
    Gfc2Double m_dLength;
};
#endif
