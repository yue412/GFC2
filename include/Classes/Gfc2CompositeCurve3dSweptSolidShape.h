#ifndef GFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H
#define GFC2COMPOSITECURVE3DSWEPTSOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Curve3d.h"
#include "Gfc2Surface.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CompositeCurve3dSweptSolidShape: public Gfc2SweptAreaSolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2CompositeCurve3dSweptSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2CompositeCurve3dSweptSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getSegmentsCount() const {return (int)m_oSegments.size();}
    void clearSegments() {m_oSegments.clear();}
    void addSegments(const glodon::objectbuf::EntityRef& nValue) {m_oSegments.push_back(nValue);}
    glodon::objectbuf::EntityRef getSegments(int nIndex) const {return m_oSegments[nIndex];}
    Gfc2Curve3d* getSegmentsPtr(int nIndex) const {return (Gfc2Curve3d*)m_pDocument->find(getSegments(nIndex));}
    int getReferencesCount() const {return (int)m_oReferences.size();}
    void clearReferences() {m_oReferences.clear();}
    void addReferences(const glodon::objectbuf::EntityRef& nValue) {m_oReferences.push_back(nValue);}
    glodon::objectbuf::EntityRef getReferences(int nIndex) const {return m_oReferences[nIndex];}
    Gfc2Surface* getReferencesPtr(int nIndex) const {return (Gfc2Surface*)m_pDocument->find(getReferences(nIndex));}

private:
    std::vector<glodon::objectbuf::EntityRef> m_oSegments;
    std::vector<glodon::objectbuf::EntityRef> m_oReferences;
};
#endif
