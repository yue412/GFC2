#ifndef GFC2FACESPHEREINFO_H
#define GFC2FACESPHEREINFO_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2FaceInfo.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2FaceSphereInfo: public Gfc2FaceInfo
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceSphereInfo,glodon::objectbuf::Entity)
public:
    Gfc2FaceSphereInfo();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCenterPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCenterPoint = nValue;
        setHasCenterPoint();
    }
    glodon::objectbuf::EntityRef getCenterPoint() const {return m_nCenterPoint;}
    bool hasCenterPoint() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector2d* getCenterPointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getCenterPoint());}
    void setHeight(const Gfc2Double& dValue)
    {
        m_dHeight = dValue;
        setHasHeight();
    }
    Gfc2Double getHeight() const {return m_dHeight;}
    bool hasHeight() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setChord(const Gfc2Double& dValue)
    {
        m_dChord = dValue;
        setHasChord();
    }
    Gfc2Double getChord() const {return m_dChord;}
    bool hasChord() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setCheckInnerChord(const Gfc2Boolean& bValue)
    {
        m_bCheckInnerChord = bValue;
        setHasCheckInnerChord();
    }
    Gfc2Boolean getCheckInnerChord() const {return m_bCheckInnerChord;}
    bool hasCheckInnerChord() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasCenterPoint() {_has_bits_[0] |= 0x1u;}
    void setHasHeight() {_has_bits_[0] |= 0x2u;}
    void setHasChord() {_has_bits_[0] |= 0x4u;}
    void setHasCheckInnerChord() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nCenterPoint;
    Gfc2Double m_dHeight;
    Gfc2Double m_dChord;
    Gfc2Boolean m_bCheckInnerChord;
};

class GFCCLASSES_API Gfc2FaceSphereInfoFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceSphereInfoFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
