#ifndef GFC2SIMPLEPOLYGON_H
#define GFC2SIMPLEPOLYGON_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Polygon.h"
#include "Gfc2SimpleLoop.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2SimplePolygon: public Gfc2Polygon
{
OBJECTBUF_DEC_OBJECT(Gfc2SimplePolygon,glodon::objectbuf::Entity)
public:
    Gfc2SimplePolygon();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getLoopsCount() const {return (int)m_oLoops.size();}
    void clearLoops() {m_oLoops.clear();}
    void addLoops(const glodon::objectbuf::EntityRef& nValue) {m_oLoops.push_back(nValue);}
    glodon::objectbuf::EntityRef getLoops(int nIndex) const {return m_oLoops[nIndex];}
    Gfc2SimpleLoop* getLoopsPtr(int nIndex) const {return (Gfc2SimpleLoop*)m_pDocument->find(getLoops(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oLoops;
};

class GFCCLASSES_API Gfc2SimplePolygonFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SimplePolygonFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
