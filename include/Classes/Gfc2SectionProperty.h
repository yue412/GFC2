#ifndef GFC2SECTIONPROPERTY_H
#define GFC2SECTIONPROPERTY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SingleProperty.h"
#include "Gfc2Section.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SectionProperty: public Gfc2SingleProperty
{
OBJECTBUF_DEC_OBJECT(Gfc2SectionProperty,glodon::objectbuf::Entity)
public:
    Gfc2SectionProperty();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setSection(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSection = nValue;
        setHasSection();
    }
    glodon::objectbuf::EntityRef getSection() const {return m_nSection;}
    bool hasSection() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Section* getSectionPtr() const {return (Gfc2Section*)m_pDocument->find(getSection());}

private:
    void setHasSection() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nSection;
};
#endif
