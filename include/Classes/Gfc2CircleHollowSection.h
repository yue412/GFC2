#ifndef GFC2CIRCLEHOLLOWSECTION_H
#define GFC2CIRCLEHOLLOWSECTION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2CircleSection.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CircleHollowSection: public Gfc2CircleSection
{
OBJECTBUF_DEC_OBJECT(Gfc2CircleHollowSection,glodon::objectbuf::Entity)
public:
    Gfc2CircleHollowSection();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setThickness(const Gfc2Double& dValue)
    {
        m_dThickness = dValue;
        setHasThickness();
    }
    Gfc2Double getThickness() const {return m_dThickness;}
    bool hasThickness() const {return (_has_bits_[0] & 0x4u) != 0;}

private:
    void setHasThickness() {_has_bits_[0] |= 0x4u;}

    Gfc2Double m_dThickness;
};
#endif
