#ifndef GFC2SHAPE2D_H
#define GFC2SHAPE2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2ParametricShape.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Shape2d: public Gfc2ParametricShape
{
OBJECTBUF_DEC_OBJECT(Gfc2Shape2d,glodon::objectbuf::Entity)
public:
    Gfc2Shape2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setElev(const Gfc2Double& dValue)
    {
        m_dElev = dValue;
        setHasElev();
    }
    Gfc2Double getElev() const {return m_dElev;}
    bool hasElev() const {return (_has_bits_[0] & 0x4u) != 0;}

private:
    void setHasElev() {_has_bits_[0] |= 0x4u;}

    Gfc2Double m_dElev;
};
#endif
