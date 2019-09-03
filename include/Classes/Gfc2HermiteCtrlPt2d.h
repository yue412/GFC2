#ifndef GFC2HERMITECTRLPT2D_H
#define GFC2HERMITECTRLPT2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Vector2d.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2HermiteCtrlPt2d: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2HermiteCtrlPt2d,glodon::objectbuf::Entity)
public:
    Gfc2HermiteCtrlPt2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPoint = nValue;
        setHasPoint();
    }
    glodon::objectbuf::EntityRef getPoint() const {return m_nPoint;}
    bool hasPoint() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector2d* getPointPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getPoint());}
    void setTangent(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nTangent = nValue;
        setHasTangent();
    }
    glodon::objectbuf::EntityRef getTangent() const {return m_nTangent;}
    bool hasTangent() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector2d* getTangentPtr() const {return (Gfc2Vector2d*)m_pDocument->find(getTangent());}
    void setParameter(const Gfc2Double& dValue)
    {
        m_dParameter = dValue;
        setHasParameter();
    }
    Gfc2Double getParameter() const {return m_dParameter;}
    bool hasParameter() const {return (_has_bits_[0] & 0x4u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasPoint() {_has_bits_[0] |= 0x1u;}
    void setHasTangent() {_has_bits_[0] |= 0x2u;}
    void setHasParameter() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nPoint;
    glodon::objectbuf::EntityRef m_nTangent;
    Gfc2Double m_dParameter;
};

class GFCCLASSES_API Gfc2HermiteCtrlPt2dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2HermiteCtrlPt2dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
