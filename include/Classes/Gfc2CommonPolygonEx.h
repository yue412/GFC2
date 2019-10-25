#ifndef GFC2COMMONPOLYGONEX_H
#define GFC2COMMONPOLYGONEX_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Polygon.h"
#include "Gfc2CoedgeListEx.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CommonPolygonEx: public Gfc2Polygon
{
OBJECTBUF_DEC_OBJECT(Gfc2CommonPolygonEx,glodon::objectbuf::Entity)
public:
    Gfc2CommonPolygonEx();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getLoopExsCount() const {return (int)m_oLoopExs.size();}
    void clearLoopExs() {m_oLoopExs.clear();}
    void addLoopExs(const glodon::objectbuf::EntityRef& nValue) {m_oLoopExs.push_back(nValue);}
    glodon::objectbuf::EntityRef getLoopExs(int nIndex) const {return m_oLoopExs[nIndex];}
    Gfc2CoedgeListEx* getLoopExsPtr(int nIndex) const {return (Gfc2CoedgeListEx*)m_pDocument->find(getLoopExs(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oLoopExs;
};
#endif
