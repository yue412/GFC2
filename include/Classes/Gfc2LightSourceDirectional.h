#ifndef GFC2LIGHTSOURCEDIRECTIONAL_H
#define GFC2LIGHTSOURCEDIRECTIONAL_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2LightSource.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2LightSourceDirectional: public Gfc2LightSource
{
OBJECTBUF_DEC_OBJECT(Gfc2LightSourceDirectional,glodon::objectbuf::Entity)
public:
    Gfc2LightSourceDirectional();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setOrientation(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nOrientation = nValue;
        setHasOrientation();
    }
    glodon::objectbuf::EntityRef getOrientation() const {return m_nOrientation;}
    bool hasOrientation() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2Vector3d* getOrientationPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getOrientation());}

private:
    void setHasOrientation() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nOrientation;
};
#endif
