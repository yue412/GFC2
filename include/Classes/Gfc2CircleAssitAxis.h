#ifndef GFC2CIRCLEASSITAXIS_H
#define GFC2CIRCLEASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AssitAxis.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2CircleAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2CircleAssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2CircleAssitAxis();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCenter(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCenter = nValue;
        setHasCenter();
    }
    glodon::objectbuf::EntityRef getCenter() const {return m_nCenter;}
    bool hasCenter() const {return (_has_bits_[0] & 0x100u) != 0;}
    Gfc2Vector2d* getCenterPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getCenter());}
    void setRadius(const Gfc2Double& dValue)
    {
        m_dRadius = dValue;
        setHasRadius();
    }
    Gfc2Double getRadius() const {return m_dRadius;}
    bool hasRadius() const {return (_has_bits_[0] & 0x200u) != 0;}

private:
    void setHasCenter() {_has_bits_[0] |= 0x100u;}
    void setHasRadius() {_has_bits_[0] |= 0x200u;}

    glodon::objectbuf::EntityRef m_nCenter;
    Gfc2Double m_dRadius;
};

class GFCCLASSES_API Gfc2CircleAssitAxisFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CircleAssitAxisFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
