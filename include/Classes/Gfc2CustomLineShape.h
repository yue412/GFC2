#ifndef GFC2CUSTOMLINESHAPE_H
#define GFC2CUSTOMLINESHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SolidShape.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2CustomLineShape: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2CustomLineShape,glodon::objectbuf::Entity)
public:
    Gfc2CustomLineShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setWidth(const Gfc2Double& dValue)
    {
        m_dWidth = dValue;
        setHasWidth();
    }
    Gfc2Double getWidth() const {return m_dWidth;}
    bool hasWidth() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setLeftWidth(const Gfc2Double& dValue)
    {
        m_dLeftWidth = dValue;
        setHasLeftWidth();
    }
    Gfc2Double getLeftWidth() const {return m_dLeftWidth;}
    bool hasLeftWidth() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setLine(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nLine = nValue;
        setHasLine();
    }
    glodon::objectbuf::EntityRef getLine() const {return m_nLine;}
    bool hasLine() const {return (_has_bits_[0] & 0x40u) != 0;}
    Gfc2Curve2d* getLinePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getLine());}
    void setE_S_Elevation(const Gfc2Double& dValue)
    {
        m_dE_S_Elevation = dValue;
        setHasE_S_Elevation();
    }
    Gfc2Double getE_S_Elevation() const {return m_dE_S_Elevation;}
    bool hasE_S_Elevation() const {return (_has_bits_[0] & 0x80u) != 0;}

private:
    void setHasWidth() {_has_bits_[0] |= 0x10u;}
    void setHasLeftWidth() {_has_bits_[0] |= 0x20u;}
    void setHasLine() {_has_bits_[0] |= 0x40u;}
    void setHasE_S_Elevation() {_has_bits_[0] |= 0x80u;}

    Gfc2Double m_dWidth;
    Gfc2Double m_dLeftWidth;
    glodon::objectbuf::EntityRef m_nLine;
    Gfc2Double m_dE_S_Elevation;
};

class GFCCLASSES_API Gfc2CustomLineShapeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2CustomLineShapeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
