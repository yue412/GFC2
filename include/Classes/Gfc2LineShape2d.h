#ifndef GFC2LINESHAPE2D_H
#define GFC2LINESHAPE2D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Shape2d.h"
#include "Gfc2Curve2d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2LineShape2d: public Gfc2Shape2d
{
OBJECTBUF_DEC_OBJECT(Gfc2LineShape2d,glodon::objectbuf::Entity)
public:
    Gfc2LineShape2d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setLine(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nLine = nValue;
        setHasLine();
    }
    glodon::objectbuf::EntityRef getLine() const {return m_nLine;}
    bool hasLine() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Curve2d* getLinePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getLine());}

private:
    void setHasLine() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nLine;
};

class GFCCLASSES_API Gfc2LineShape2dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2LineShape2dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
