#ifndef GFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H
#define GFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ExtrudedAreaSolidShape.h"
#include "Gfc2Section.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ExtrudedAreaSolidTaperedShape: public Gfc2ExtrudedAreaSolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2ExtrudedAreaSolidTaperedShape,glodon::objectbuf::Entity)
public:
    Gfc2ExtrudedAreaSolidTaperedShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setEndSweptArea(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nEndSweptArea = nValue;
        setHasEndSweptArea();
    }
    glodon::objectbuf::EntityRef getEndSweptArea() const {return m_nEndSweptArea;}
    bool hasEndSweptArea() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2Section* getEndSweptAreaPtr() const {return (Gfc2Section*)m_pDocument->find(getEndSweptArea());}

private:
    void setHasEndSweptArea() {_has_bits_[0] |= 0x20u;}

    glodon::objectbuf::EntityRef m_nEndSweptArea;
};
#endif
