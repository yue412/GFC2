#ifndef GFC2SWEPTAREASOLIDSHAPE_H
#define GFC2SWEPTAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SolidShape.h"
#include "Gfc2Section.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SweptAreaSolidShape: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2SweptAreaSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2SweptAreaSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setSweptArea(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSweptArea = nValue;
        setHasSweptArea();
    }
    glodon::objectbuf::EntityRef getSweptArea() const {return m_nSweptArea;}
    bool hasSweptArea() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Section* getSweptAreaPtr() const {return (Gfc2Section*)m_pDocument->find(getSweptArea());}

private:
    void setHasSweptArea() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nSweptArea;
};
#endif
