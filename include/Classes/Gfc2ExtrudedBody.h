#ifndef GFC2EXTRUDEDBODY_H
#define GFC2EXTRUDEDBODY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Body.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Polygon.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2ExtrudedBody: public Gfc2Body
{
OBJECTBUF_DEC_OBJECT(Gfc2ExtrudedBody,glodon::objectbuf::Entity)
public:
    Gfc2ExtrudedBody();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCoordinate(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCoordinate = nValue;
        setHasCoordinate();
    }
    glodon::objectbuf::EntityRef getCoordinate() const {return m_nCoordinate;}
    bool hasCoordinate() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Coordinates3d* getCoordinatePtr() const {return (Gfc2Coordinates3d*)m_pDocument->find(getCoordinate());}
    void setLength(const Gfc2Double& dValue)
    {
        m_dLength = dValue;
        setHasLength();
    }
    Gfc2Double getLength() const {return m_dLength;}
    bool hasLength() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setSection(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSection = nValue;
        setHasSection();
    }
    glodon::objectbuf::EntityRef getSection() const {return m_nSection;}
    bool hasSection() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Polygon* getSectionPtr() const {return (Gfc2Polygon*)m_pDocument->find(getSection());}

private:
    void setHasCoordinate() {_has_bits_[0] |= 0x1u;}
    void setHasLength() {_has_bits_[0] |= 0x2u;}
    void setHasSection() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nCoordinate;
    Gfc2Double m_dLength;
    glodon::objectbuf::EntityRef m_nSection;
};

class GFCCLASSES_API Gfc2ExtrudedBodyFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2ExtrudedBodyFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
