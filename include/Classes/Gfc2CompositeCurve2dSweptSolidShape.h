#ifndef GFC2COMPOSITECURVE2DSWEPTSOLIDSHAPE_H
#define GFC2COMPOSITECURVE2DSWEPTSOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Curve2d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CompositeCurve2dSweptSolidShape: public Gfc2SweptAreaSolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2CompositeCurve2dSweptSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2CompositeCurve2dSweptSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getSegmentsCount() const {return (int)m_oSegments.size();}
    void clearSegments() {m_oSegments.clear();}
    void addSegments(const glodon::objectbuf::EntityRef& nValue) {m_oSegments.push_back(nValue);}
    glodon::objectbuf::EntityRef getSegments(int nIndex) const {return m_oSegments[nIndex];}
    Gfc2Curve2d* getSegmentsPtr(int nIndex) const {return (Gfc2Curve2d*)m_pDocument->find(getSegments(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oSegments;
};
#endif
