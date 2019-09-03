#ifndef GFC2VECTOR2D_H
#define GFC2VECTOR2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Geometry.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Vector2d: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Vector2d,glodon::objectbuf::Entity)
public:
    Gfc2Vector2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setX(const Gfc2Double& dValue)
    {
        m_dX = dValue;
        setHasX();
    }
    Gfc2Double getX() const {return m_dX;}
    bool hasX() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setY(const Gfc2Double& dValue)
    {
        m_dY = dValue;
        setHasY();
    }
    Gfc2Double getY() const {return m_dY;}
    bool hasY() const {return (_has_bits_[0] & 0x2u) != 0;}

private:
    void setHasX() {_has_bits_[0] |= 0x1u;}
    void setHasY() {_has_bits_[0] |= 0x2u;}

    Gfc2Double m_dX;
    Gfc2Double m_dY;
};

class GFCCLASSES_API Gfc2Vector2dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Vector2dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
