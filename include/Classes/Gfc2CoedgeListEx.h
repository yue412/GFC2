#ifndef GFC2COEDGELISTEX_H
#define GFC2COEDGELISTEX_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Topology.h"
#include "Gfc2Coedge.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CoedgeListEx: public Gfc2Topology
{
OBJECTBUF_DEC_OBJECT(Gfc2CoedgeListEx,glodon::objectbuf::Entity)
public:
    Gfc2CoedgeListEx();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getCoedgeExsCount() const {return (int)m_oCoedgeExs.size();}
    void clearCoedgeExs() {m_oCoedgeExs.clear();}
    void addCoedgeExs(const glodon::objectbuf::EntityRef& nValue) {m_oCoedgeExs.push_back(nValue);}
    glodon::objectbuf::EntityRef getCoedgeExs(int nIndex) const {return m_oCoedgeExs[nIndex];}
    Gfc2Coedge* getCoedgeExsPtr(int nIndex) const {return (Gfc2Coedge*)m_pDocument->find(getCoedgeExs(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oCoedgeExs;
};
#endif
