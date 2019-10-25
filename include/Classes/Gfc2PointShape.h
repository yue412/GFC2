#ifndef GFC2POINTSHAPE_H
#define GFC2POINTSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SectionPointShape.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Polygon.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2PointShape: public Gfc2SectionPointShape
{
OBJECTBUF_DEC_OBJECT(Gfc2PointShape,glodon::objectbuf::Entity)
public:
    Gfc2PointShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setHeight(const Gfc2Double& dValue)
    {
        m_dHeight = dValue;
        setHasHeight();
    }
    Gfc2Double getHeight() const {return m_dHeight;}
    bool hasHeight() const {return (_has_bits_[0] & 0x200u) != 0;}
    void setObliqueDir(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nObliqueDir = nValue;
        setHasObliqueDir();
    }
    glodon::objectbuf::EntityRef getObliqueDir() const {return m_nObliqueDir;}
    bool hasObliqueDir() const {return (_has_bits_[0] & 0x400u) != 0;}
    Gfc2Vector3d* getObliqueDirPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getObliqueDir());}
    void setTopPoly(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nTopPoly = nValue;
        setHasTopPoly();
    }
    glodon::objectbuf::EntityRef getTopPoly() const {return m_nTopPoly;}
    bool hasTopPoly() const {return (_has_bits_[0] & 0x800u) != 0;}
    Gfc2Polygon* getTopPolyPtr() const {return (Gfc2Polygon*)m_pDocument->find(getTopPoly());}

private:
    void setHasHeight() {_has_bits_[0] |= 0x200u;}
    void setHasObliqueDir() {_has_bits_[0] |= 0x400u;}
    void setHasTopPoly() {_has_bits_[0] |= 0x800u;}

    Gfc2Double m_dHeight;
    glodon::objectbuf::EntityRef m_nObliqueDir;
    glodon::objectbuf::EntityRef m_nTopPoly;
};
#endif
