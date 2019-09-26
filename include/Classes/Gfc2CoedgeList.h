#ifndef GFC2COEDGELIST_H
#define GFC2COEDGELIST_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Geometry.h"
#include "Gfc2Curve2d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2CoedgeList: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2CoedgeList,glodon::objectbuf::Entity)
public:
    Gfc2CoedgeList();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getCoedgesCount() const {return (int)m_oCoedges.size();}
    void clearCoedges() {m_oCoedges.clear();}
    void addCoedges(const glodon::objectbuf::EntityRef& nValue) {m_oCoedges.push_back(nValue);}
    glodon::objectbuf::EntityRef getCoedges(int nIndex) const {return m_oCoedges[nIndex];}
    Gfc2Curve2d* getCoedgesPtr(int nIndex) const {return (Gfc2Curve2d*)m_pDocument->find(getCoedges(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oCoedges;
};

class GFCCLASSES_API Gfc2CoedgeListFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CoedgeListFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
