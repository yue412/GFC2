#ifndef GFC2CIRCLESECTION_H
#define GFC2CIRCLESECTION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ParameterizedSection.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CircleSection: public Gfc2ParameterizedSection
{
OBJECTBUF_DEC_OBJECT(Gfc2CircleSection,glodon::objectbuf::Entity)
public:
    Gfc2CircleSection();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x2u) != 0;}

private:
    void setHasRadius() {_has_bits_[0] |= 0x2u;}

    Gfc2Double m_dRadius;
};
#endif
