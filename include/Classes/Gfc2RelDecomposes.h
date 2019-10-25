#ifndef GFC2RELDECOMPOSES_H
#define GFC2RELDECOMPOSES_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelationShip.h"
#include "Gfc2Object.h"
#include "Gfc2Object.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelDecomposes: public Gfc2RelationShip
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDecomposes,glodon::objectbuf::Entity)
public:
    Gfc2RelDecomposes();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRelatingObject(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nRelatingObject = nValue;
        setHasRelatingObject();
    }
    glodon::objectbuf::EntityRef getRelatingObject() const {return m_nRelatingObject;}
    bool hasRelatingObject() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Object* getRelatingObjectPtr() const {return (Gfc2Object*)m_pDocument->find(getRelatingObject());}
    int getRelatedObjectsCount() const {return (int)m_oRelatedObjects.size();}
    void clearRelatedObjects() {m_oRelatedObjects.clear();}
    void addRelatedObjects(const glodon::objectbuf::EntityRef& nValue) {m_oRelatedObjects.push_back(nValue);}
    glodon::objectbuf::EntityRef getRelatedObjects(int nIndex) const {return m_oRelatedObjects[nIndex];}
    Gfc2Object* getRelatedObjectsPtr(int nIndex) const {return (Gfc2Object*)m_pDocument->find(getRelatedObjects(nIndex));}

private:
    void setHasRelatingObject() {_has_bits_[0] |= 0x1u;}

    glodon::objectbuf::EntityRef m_nRelatingObject;
    std::vector<glodon::objectbuf::EntityRef> m_oRelatedObjects;
};
#endif
