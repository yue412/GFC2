#ifndef GFC2POINTANGLEASSITAXIS_H
#define GFC2POINTANGLEASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AssitAxis.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2PointAngleAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2PointAngleAssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2PointAngleAssitAxis();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRefPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRefPoint = nValue;
        setHasRefPoint();
    }
    glodon::objectbuf::EntityRef getRefPoint() const {return m_nRefPoint;}
    bool hasRefPoint() const {return (_has_bits_[0] & 0x100u) != 0;}
    Gfc2Vector2d* getRefPointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getRefPoint());}
    void setAngle(const Gfc2Double& dValue)
    {
        m_dAngle = dValue;
        setHasAngle();
    }
    Gfc2Double getAngle() const {return m_dAngle;}
    bool hasAngle() const {return (_has_bits_[0] & 0x200u) != 0;}

private:
    void setHasRefPoint() {_has_bits_[0] |= 0x100u;}
    void setHasAngle() {_has_bits_[0] |= 0x200u;}

    glodon::objectbuf::EntityRef m_nRefPoint;
    Gfc2Double m_dAngle;
};

class GFCCLASSES_API Gfc2PointAngleAssitAxisFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PointAngleAssitAxisFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
