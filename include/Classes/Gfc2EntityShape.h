#ifndef GFC2ENTITYSHAPE_H
#define GFC2ENTITYSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2Shape.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2EntityShape: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2EntityShape,glodon::objectbuf::Entity)
public:
    Gfc2EntityShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setIdentifier(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nIdentifier = nValue;
        setHasIdentifier();
    }
    glodon::objectbuf::EntityRef getIdentifier() const {return m_nIdentifier;}
    bool hasIdentifier() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2String* getIdentifierPtr() const {return (Gfc2String*)m_pDocument->find(getIdentifier());}
    void setShape(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nShape = nValue;
        setHasShape();
    }
    glodon::objectbuf::EntityRef getShape() const {return m_nShape;}
    bool hasShape() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Shape* getShapePtr() const {return (Gfc2Shape*)m_pDocument->find(getShape());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasIdentifier() {_has_bits_[0] |= 0x1u;}
    void setHasShape() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nIdentifier;
    glodon::objectbuf::EntityRef m_nShape;
};

class GFCCLASSES_API Gfc2EntityShapeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2EntityShapeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
