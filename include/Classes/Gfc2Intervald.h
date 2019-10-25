#ifndef GFC2INTERVALD_H
#define GFC2INTERVALD_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Geometry.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Intervald: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Intervald,glodon::objectbuf::Entity)
public:
    Gfc2Intervald();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setMin(const Gfc2Double& dValue)
    {
        m_dMin = dValue;
        setHasMin();
    }
    Gfc2Double getMin() const {return m_dMin;}
    bool hasMin() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setMax(const Gfc2Double& dValue)
    {
        m_dMax = dValue;
        setHasMax();
    }
    Gfc2Double getMax() const {return m_dMax;}
    bool hasMax() const {return (_has_bits_[0] & 0x2u) != 0;}

private:
    void setHasMin() {_has_bits_[0] |= 0x1u;}
    void setHasMax() {_has_bits_[0] |= 0x2u;}

    Gfc2Double m_dMin;
    Gfc2Double m_dMax;
};
#endif
