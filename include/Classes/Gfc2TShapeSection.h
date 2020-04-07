#ifndef GFC2TSHAPESECTION_H
#define GFC2TSHAPESECTION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ParameterizedSection.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2TShapeSection: public Gfc2ParameterizedSection
{
OBJECTBUF_DEC_OBJECT(Gfc2TShapeSection,glodon::objectbuf::Entity)
public:
    Gfc2TShapeSection();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setWidth(const Gfc2Double& dValue)
    {
        m_dWidth = dValue;
        setHasWidth();
    }
    Gfc2Double getWidth() const {return m_dWidth;}
    bool hasWidth() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setHeight(const Gfc2Double& dValue)
    {
        m_dHeight = dValue;
        setHasHeight();
    }
    Gfc2Double getHeight() const {return m_dHeight;}
    bool hasHeight() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setThickness1(const Gfc2Double& dValue)
    {
        m_dThickness1 = dValue;
        setHasThickness1();
    }
    Gfc2Double getThickness1() const {return m_dThickness1;}
    bool hasThickness1() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setThickness2(const Gfc2Double& dValue)
    {
        m_dThickness2 = dValue;
        setHasThickness2();
    }
    Gfc2Double getThickness2() const {return m_dThickness2;}
    bool hasThickness2() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setLeftWidth(const Gfc2Double& dValue)
    {
        m_dLeftWidth = dValue;
        setHasLeftWidth();
    }
    Gfc2Double getLeftWidth() const {return m_dLeftWidth;}
    bool hasLeftWidth() const {return (_has_bits_[0] & 0x20u) != 0;}

private:
    void setHasWidth() {_has_bits_[0] |= 0x2u;}
    void setHasHeight() {_has_bits_[0] |= 0x4u;}
    void setHasThickness1() {_has_bits_[0] |= 0x8u;}
    void setHasThickness2() {_has_bits_[0] |= 0x10u;}
    void setHasLeftWidth() {_has_bits_[0] |= 0x20u;}

    Gfc2Double m_dWidth;
    Gfc2Double m_dHeight;
    Gfc2Double m_dThickness1;
    Gfc2Double m_dThickness2;
    Gfc2Double m_dLeftWidth;
};
#endif
