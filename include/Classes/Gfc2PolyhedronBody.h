#ifndef GFC2POLYHEDRONBODY_H
#define GFC2POLYHEDRONBODY_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Body.h"
#include "Gfc2PolyhedralFace.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PolyhedronBody: public Gfc2Body
{
OBJECTBUF_DEC_OBJECT(Gfc2PolyhedronBody,glodon::objectbuf::Entity)
public:
    Gfc2PolyhedronBody();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getFacesCount() const {return (int)m_oFaces.size();}
    void clearFaces() {m_oFaces.clear();}
    void addFaces(const glodon::objectbuf::EntityRef& nValue) {m_oFaces.push_back(nValue);}
    glodon::objectbuf::EntityRef getFaces(int nIndex) const {return m_oFaces[nIndex];}
    Gfc2PolyhedralFace* getFacesPtr(int nIndex) const {return (Gfc2PolyhedralFace*)m_pDocument->find(getFaces(nIndex));}
    int getVertexesCount() const {return (int)m_oVertexes.size();}
    void clearVertexes() {m_oVertexes.clear();}
    void addVertexes(const glodon::objectbuf::EntityRef& nValue) {m_oVertexes.push_back(nValue);}
    glodon::objectbuf::EntityRef getVertexes(int nIndex) const {return m_oVertexes[nIndex];}
    Gfc2Vector3d* getVertexesPtr(int nIndex) const {return (Gfc2Vector3d*)m_pDocument->find(getVertexes(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oFaces;
    std::vector<glodon::objectbuf::EntityRef> m_oVertexes;
};
#endif
