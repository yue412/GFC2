#ifndef GFC2GEOMETRYSHAPE_H
#define GFC2GEOMETRYSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Shape.h"
#include "Gfc2Geometry.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2GeometryShape: public Gfc2Shape
{
OBJECTBUF_DEC_OBJECT(Gfc2GeometryShape,glodon::objectbuf::Entity)
public:
    Gfc2GeometryShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getGeosCount() const {return (int)m_oGeos.size();}
    void clearGeos() {m_oGeos.clear();}
    void addGeos(const glodon::objectbuf::EntityRef& nValue) {m_oGeos.push_back(nValue);}
    glodon::objectbuf::EntityRef getGeos(int nIndex) const {return m_oGeos[nIndex];}
    Gfc2Geometry* getGeosPtr(int nIndex) const {return (Gfc2Geometry*)m_pDocument->find(getGeos(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oGeos;
};
#endif
