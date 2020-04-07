#ifndef GFC2ARBITRARYSECTION_H
#define GFC2ARBITRARYSECTION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Section.h"
#include "Gfc2Polygon.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ArbitrarySection: public Gfc2Section
{
OBJECTBUF_DEC_OBJECT(Gfc2ArbitrarySection,glodon::objectbuf::Entity)
public:
    Gfc2ArbitrarySection();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPoly(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPoly = nValue;
        setHasPoly();
    }
    glodon::objectbuf::EntityRef getPoly() const {return m_nPoly;}
    bool hasPoly() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Polygon* getPolyPtr() const {return (Gfc2Polygon*)m_pDocument->find(getPoly());}

private:
    void setHasPoly() {_has_bits_[0] |= 0x1u;}

    glodon::objectbuf::EntityRef m_nPoly;
};
#endif
