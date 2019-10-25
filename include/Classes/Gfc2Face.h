#ifndef GFC2FACE_H
#define GFC2FACE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2CommonPolygonEx.h"
#include "Gfc2Surface.h"
#include "Gfc2Box3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Face: public Gfc2CommonPolygonEx
{
OBJECTBUF_DEC_OBJECT(Gfc2Face,glodon::objectbuf::Entity)
public:
    Gfc2Face();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setSurface(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSurface = nValue;
        setHasSurface();
    }
    glodon::objectbuf::EntityRef getSurface() const {return m_nSurface;}
    bool hasSurface() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Surface* getSurfacePtr() const {return (Gfc2Surface*)m_pDocument->find(getSurface());}
    void setBox(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBox = nValue;
        setHasBox();
    }
    glodon::objectbuf::EntityRef getBox() const {return m_nBox;}
    bool hasBox() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Box3d* getBoxPtr() const {return (Gfc2Box3d*)m_pDocument->find(getBox());}
    void setSameDir(const Gfc2Boolean& bValue)
    {
        m_bSameDir = bValue;
        setHasSameDir();
    }
    Gfc2Boolean getSameDir() const {return m_bSameDir;}
    bool hasSameDir() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setIndex(const Gfc2Integer& nValue)
    {
        m_nIndex = nValue;
        setHasIndex();
    }
    Gfc2Integer getIndex() const {return m_nIndex;}
    bool hasIndex() const {return (_has_bits_[0] & 0x10u) != 0;}

private:
    void setHasSurface() {_has_bits_[0] |= 0x2u;}
    void setHasBox() {_has_bits_[0] |= 0x4u;}
    void setHasSameDir() {_has_bits_[0] |= 0x8u;}
    void setHasIndex() {_has_bits_[0] |= 0x10u;}

    glodon::objectbuf::EntityRef m_nSurface;
    glodon::objectbuf::EntityRef m_nBox;
    Gfc2Boolean m_bSameDir;
    Gfc2Integer m_nIndex;
};
#endif
