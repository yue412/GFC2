#ifndef GFC2SIMPLELOOP_H
#define GFC2SIMPLELOOP_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Topology.h"
#include "Gfc2SimpleVertex.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SimpleLoop: public Gfc2Topology
{
OBJECTBUF_DEC_OBJECT(Gfc2SimpleLoop,glodon::objectbuf::Entity)
public:
    Gfc2SimpleLoop();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getVertexesCount() const {return (int)m_oVertexes.size();}
    void clearVertexes() {m_oVertexes.clear();}
    void addVertexes(const glodon::objectbuf::EntityRef& nValue) {m_oVertexes.push_back(nValue);}
    glodon::objectbuf::EntityRef getVertexes(int nIndex) const {return m_oVertexes[nIndex];}
    Gfc2SimpleVertex* getVertexesPtr(int nIndex) const {return (Gfc2SimpleVertex*)m_pDocument->find(getVertexes(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oVertexes;
};
#endif
