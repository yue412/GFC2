#ifndef GFC2RELDEFINES_H
#define GFC2RELDEFINES_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelationShip.h"
#include "Gfc2Object.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelDefines: public Gfc2RelationShip
{
OBJECTBUF_DEC_OBJECT(Gfc2RelDefines,glodon::objectbuf::Entity)
public:
    Gfc2RelDefines();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getRelatedObjectsCount() const {return (int)m_oRelatedObjects.size();}
    void clearRelatedObjects() {m_oRelatedObjects.clear();}
    void addRelatedObjects(const glodon::objectbuf::EntityRef& nValue) {m_oRelatedObjects.push_back(nValue);}
    glodon::objectbuf::EntityRef getRelatedObjects(int nIndex) const {return m_oRelatedObjects[nIndex];}
    Gfc2Object* getRelatedObjectsPtr(int nIndex) const {return (Gfc2Object*)m_pDocument->find(getRelatedObjects(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oRelatedObjects;
};
#endif
