#ifndef GFC2RECTANGLEHOLLOWSECTION_H
#define GFC2RECTANGLEHOLLOWSECTION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RectangleSection.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RectangleHollowSection: public Gfc2RectangleSection
{
OBJECTBUF_DEC_OBJECT(Gfc2RectangleHollowSection,glodon::objectbuf::Entity)
public:
    Gfc2RectangleHollowSection();
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
    bool hasThickness() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasThickness() {_has_bits_[0] |= 0x8u;}

    Gfc2Double m_dThickness;
};
#endif
