#ifndef GFC2CENTERSTARTENDARCASSITAXIS_H
#define GFC2CENTERSTARTENDARCASSITAXIS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2AssitAxis.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2CenterStartEndArcAssitAxis: public Gfc2AssitAxis
{
OBJECTBUF_DEC_OBJECT(Gfc2CenterStartEndArcAssitAxis,glodon::objectbuf::Entity)
public:
    Gfc2CenterStartEndArcAssitAxis();
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
    void setStartPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nStartPoint = nValue;
        setHasStartPoint();
    }
    glodon::objectbuf::EntityRef getStartPoint() const {return m_nStartPoint;}
    bool hasStartPoint() const {return (_has_bits_[0] & 0x200u) != 0;}
    Gfc2Vector2d* getStartPointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getStartPoint());}
    void setEndPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nEndPoint = nValue;
        setHasEndPoint();
    }
    glodon::objectbuf::EntityRef getEndPoint() const {return m_nEndPoint;}
    bool hasEndPoint() const {return (_has_bits_[0] & 0x400u) != 0;}
    Gfc2Vector2d* getEndPointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getEndPoint());}

private:
    void setHasCenter() {_has_bits_[0] |= 0x100u;}
    void setHasStartPoint() {_has_bits_[0] |= 0x200u;}
    void setHasEndPoint() {_has_bits_[0] |= 0x400u;}

    glodon::objectbuf::EntityRef m_nCenter;
    glodon::objectbuf::EntityRef m_nStartPoint;
    glodon::objectbuf::EntityRef m_nEndPoint;
};

class GFCCLASSES_API Gfc2CenterStartEndArcAssitAxisFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CenterStartEndArcAssitAxisFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
