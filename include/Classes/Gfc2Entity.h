#ifndef GFC2ENTITY_H
#define GFC2ENTITY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Object.h"
#include "Gfc2Representation.h"
#include "Gfc2EntityShape.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Entity: public Gfc2Object
{
OBJECTBUF_DEC_OBJECT(Gfc2Entity,glodon::objectbuf::Entity)
public:
    Gfc2Entity();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setType(const Gfc2Integer& nValue)
    {
        m_nType = nValue;
        setHasType();
    }
    Gfc2Integer getType() const {return m_nType;}
    bool hasType() const {return (_has_bits_[0] & 0x4u) != 0;}
    int getRepresentationsCount() const {return (int)m_oRepresentations.size();}
    void clearRepresentations() {m_oRepresentations.clear();}
    void addRepresentations(const glodon::objectbuf::EntityRef& nValue) {m_oRepresentations.push_back(nValue);}
    glodon::objectbuf::EntityRef getRepresentations(int nIndex) const {return m_oRepresentations[nIndex];}
    Gfc2Representation* getRepresentationsPtr(int nIndex) const {return (Gfc2Representation*)m_pDocument->find(getRepresentations(nIndex));}
    int getShapesCount() const {return (int)m_oShapes.size();}
    void clearShapes() {m_oShapes.clear();}
    void addShapes(const glodon::objectbuf::EntityRef& nValue) {m_oShapes.push_back(nValue);}
    glodon::objectbuf::EntityRef getShapes(int nIndex) const {return m_oShapes[nIndex];}
    Gfc2EntityShape* getShapesPtr(int nIndex) const {return (Gfc2EntityShape*)m_pDocument->find(getShapes(nIndex));}

private:
    void setHasType() {_has_bits_[0] |= 0x4u;}

    Gfc2Integer m_nType;
    std::vector<glodon::objectbuf::EntityRef> m_oRepresentations;
    std::vector<glodon::objectbuf::EntityRef> m_oShapes;
};
#endif
