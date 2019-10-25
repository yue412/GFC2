#ifndef GFC2FACESHAPE_H
#define GFC2FACESHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SolidShape.h"
#include "Gfc2Polygon.h"
#include "Gfc2FaceInfo.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2FaceShape: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceShape,glodon::objectbuf::Entity)
public:
    Gfc2FaceShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setThickness(const Gfc2Double& dValue)
    {
        m_dThickness = dValue;
        setHasThickness();
    }
    Gfc2Double getThickness() const {return m_dThickness;}
    bool hasThickness() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setPoly(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPoly = nValue;
        setHasPoly();
    }
    glodon::objectbuf::EntityRef getPoly() const {return m_nPoly;}
    bool hasPoly() const {return (_has_bits_[0] & 0x20u) != 0;}
    Gfc2Polygon* getPolyPtr() const {return (Gfc2Polygon*)m_pDocument->find(getPoly());}
    void setMirrorFlag(const Gfc2Boolean& bValue)
    {
        m_bMirrorFlag = bValue;
        setHasMirrorFlag();
    }
    Gfc2Boolean getMirrorFlag() const {return m_bMirrorFlag;}
    bool hasMirrorFlag() const {return (_has_bits_[0] & 0x40u) != 0;}
    void setFaceInfo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nFaceInfo = nValue;
        setHasFaceInfo();
    }
    glodon::objectbuf::EntityRef getFaceInfo() const {return m_nFaceInfo;}
    bool hasFaceInfo() const {return (_has_bits_[0] & 0x80u) != 0;}
    Gfc2FaceInfo* getFaceInfoPtr() const {return (Gfc2FaceInfo*)m_pDocument->find(getFaceInfo());}

private:
    void setHasThickness() {_has_bits_[0] |= 0x10u;}
    void setHasPoly() {_has_bits_[0] |= 0x20u;}
    void setHasMirrorFlag() {_has_bits_[0] |= 0x40u;}
    void setHasFaceInfo() {_has_bits_[0] |= 0x80u;}

    Gfc2Double m_dThickness;
    glodon::objectbuf::EntityRef m_nPoly;
    Gfc2Boolean m_bMirrorFlag;
    glodon::objectbuf::EntityRef m_nFaceInfo;
};
#endif
