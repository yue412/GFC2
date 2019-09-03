#ifndef GFC2BREPBODY_H
#define GFC2BREPBODY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Body.h"
#include "Gfc2Face.h"
#include "Gfc2Edge.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2BrepBody: public Gfc2Body
{
OBJECTBUF_DEC_OBJECT(Gfc2BrepBody,glodon::objectbuf::Entity)
public:
    Gfc2BrepBody();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getFacesCount() const {return (int)m_oFaces.size();}
    void clearFaces() {m_oFaces.clear();}
    void addFaces(const glodon::objectbuf::EntityRef& nValue) {m_oFaces.push_back(nValue);}
    glodon::objectbuf::EntityRef getFaces(int nIndex) const {return m_oFaces[nIndex];}
    Gfc2Face* getFacesPtr(int nIndex) const {return (Gfc2Face*)m_pDocument->find(getFaces(nIndex));}
    int getEdgesCount() const {return (int)m_oEdges.size();}
    void clearEdges() {m_oEdges.clear();}
    void addEdges(const glodon::objectbuf::EntityRef& nValue) {m_oEdges.push_back(nValue);}
    glodon::objectbuf::EntityRef getEdges(int nIndex) const {return m_oEdges[nIndex];}
    Gfc2Edge* getEdgesPtr(int nIndex) const {return (Gfc2Edge*)m_pDocument->find(getEdges(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oFaces;
    std::vector<glodon::objectbuf::EntityRef> m_oEdges;
};

class GFCCLASSES_API Gfc2BrepBodyFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2BrepBodyFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
