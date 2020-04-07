#ifndef GFC2RELDEFINESBYPROPERTIES_H
#define GFC2RELDEFINESBYPROPERTIES_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelDefines.h"
#include "Gfc2PropertySet.h"
#include "Gfc2Object.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

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
    int getRelatedObjectsCount() const {return (int)m_oRelatedObjects.size();}
    void clearRelatedObjects() {m_oRelatedObjects.clear();}
    void addRelatedObjects(const glodon::objectbuf::EntityRef& nValue) {m_oRelatedObjects.push_back(nValue);}
    glodon::objectbuf::EntityRef getRelatedObjects(int nIndex) const {return m_oRelatedObjects[nIndex];}
    Gfc2Object* getRelatedObjectsPtr(int nIndex) const {return (Gfc2Object*)m_pDocument->find(getRelatedObjects(nIndex));}

private:
    void setHasRelatingPropertySet() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nRelatingPropertySet;
    std::vector<glodon::objectbuf::EntityRef> m_oRelatedObjects;
};
#endif
