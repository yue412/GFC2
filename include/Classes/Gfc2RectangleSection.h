#ifndef GFC2RECTANGLESECTION_H
#define GFC2RECTANGLESECTION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ParameterizedSection.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RectangleSection: public Gfc2ParameterizedSection
{
OBJECTBUF_DEC_OBJECT(Gfc2RectangleSection,glodon::objectbuf::Entity)
public:
    Gfc2RectangleSection();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setXLength(const Gfc2Double& dValue)
    {
        m_dXLength = dValue;
        setHasXLength();
    }
    Gfc2Double getXLength() const {return m_dXLength;}
    bool hasXLength() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setYLength(const Gfc2Double& dValue)
    {
        m_dYLength = dValue;
        setHasYLength();
    }
    Gfc2Double getYLength() const {return m_dYLength;}
    bool hasYLength() const {return (_has_bits_[0] & 0x4u) != 0;}

private:
    void setHasXLength() {_has_bits_[0] |= 0x2u;}
    void setHasYLength() {_has_bits_[0] |= 0x4u;}

    Gfc2Double m_dXLength;
    Gfc2Double m_dYLength;
};
#endif
