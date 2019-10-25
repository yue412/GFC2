#ifndef GFC2VARIABLESECTIONLINESHAPE_H
#define GFC2VARIABLESECTIONLINESHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SectionLineShape.h"
#include "Gfc2Polygon.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2VariableSectionLineShape: public Gfc2SectionLineShape
{
OBJECTBUF_DEC_OBJECT(Gfc2VariableSectionLineShape,glodon::objectbuf::Entity)
public:
    Gfc2VariableSectionLineShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setEndPoly(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nEndPoly = nValue;
        setHasEndPoly();
    }
    glodon::objectbuf::EntityRef getEndPoly() const {return m_nEndPoly;}
    bool hasEndPoly() const {return (_has_bits_[0] & 0x4000u) != 0;}
    Gfc2Polygon* getEndPolyPtr() const {return (Gfc2Polygon*)m_pDocument->find(getEndPoly());}

private:
    void setHasEndPoly() {_has_bits_[0] |= 0x4000u;}

    glodon::objectbuf::EntityRef m_nEndPoly;
};
#endif
