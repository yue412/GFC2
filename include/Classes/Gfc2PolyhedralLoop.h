#ifndef GFC2POLYHEDRALLOOP_H
#define GFC2POLYHEDRALLOOP_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Topology.h"
#include "Gfc2PolyhedralEdge.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PolyhedralLoop: public Gfc2Topology
{
OBJECTBUF_DEC_OBJECT(Gfc2PolyhedralLoop,glodon::objectbuf::Entity)
public:
    Gfc2PolyhedralLoop();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getEdgesCount() const {return (int)m_oEdges.size();}
    void clearEdges() {m_oEdges.clear();}
    void addEdges(const glodon::objectbuf::EntityRef& nValue) {m_oEdges.push_back(nValue);}
    glodon::objectbuf::EntityRef getEdges(int nIndex) const {return m_oEdges[nIndex];}
    Gfc2PolyhedralEdge* getEdgesPtr(int nIndex) const {return (Gfc2PolyhedralEdge*)m_pDocument->find(getEdges(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oEdges;
};
#endif
