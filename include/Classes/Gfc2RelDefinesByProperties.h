#ifndef GFC2RELDEFINESBYPROPERTIES_H
#define GFC2RELDEFINESBYPROPERTIES_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelDefines.h"
#include "Gfc2PropertySet.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2RelDefinesByProperties: public Gfc2RelDefines
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefinesByProperties,glodon::objectbuf::Entity)
public:
    Gfc2RelDefinesByProperties();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRelatingPropertySet(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRelatingPropertySet = nValue;
        setHasRelatingPropertySet();
    }
    glodon::objectbuf::EntityRef getRelatingPropertySet() const {return m_nRelatingPropertySet;}
    bool hasRelatingPropertySet() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2PropertySet* getRelatingPropertySetPtr() const {return (Gfc2PropertySet*)m_pDocument->find(getRelatingPropertySet());}

private:
    void setHasRelatingPropertySet() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nRelatingPropertySet;
};

class GFCCLASSES_API Gfc2RelDefinesByPropertiesFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefinesByPropertiesFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
