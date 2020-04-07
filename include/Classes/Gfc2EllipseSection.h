#ifndef GFC2ELLIPSESECTION_H
#define GFC2ELLIPSESECTION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ParameterizedSection.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2EllipseSection: public Gfc2ParameterizedSection
{
OBJECTBUF_DEC_OBJECT(Gfc2EllipseSection,glodon::objectbuf::Entity)
public:
    Gfc2EllipseSection();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setSemiAxis1(const Gfc2Double& dValue)
    {
        m_dSemiAxis1 = dValue;
        setHasSemiAxis1();
    }
    Gfc2Double getSemiAxis1() const {return m_dSemiAxis1;}
    bool hasSemiAxis1() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setSemiAxis2(const Gfc2Double& dValue)
    {
        m_dSemiAxis2 = dValue;
        setHasSemiAxis2();
    }
    Gfc2Double getSemiAxis2() const {return m_dSemiAxis2;}
    bool hasSemiAxis2() const {return (_has_bits_[0] & 0x4u) != 0;}

private:
    void setHasSemiAxis1() {_has_bits_[0] |= 0x2u;}
    void setHasSemiAxis2() {_has_bits_[0] |= 0x4u;}

    Gfc2Double m_dSemiAxis1;
    Gfc2Double m_dSemiAxis2;
};
#endif
