#ifndef GFC2FACEARCHINFO_H
#define GFC2FACEARCHINFO_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2FaceInfo.h"
#include "Gfc2Line2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2FaceArchInfo: public Gfc2FaceInfo
{
OBJECTBUF_DEC_OBJECT(Gfc2FaceArchInfo,glodon::objectbuf::Entity)
public:
    Gfc2FaceArchInfo();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setAxialLine(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nAxialLine = nValue;
        setHasAxialLine();
    }
    glodon::objectbuf::EntityRef getAxialLine() const {return m_nAxialLine;}
    bool hasAxialLine() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Line2d* getAxialLinePtr() const {return (Gfc2Line2d*)m_pDocument->find(getAxialLine());}
    void setHeight(const Gfc2Double& dValue)
    {
        m_dHeight = dValue;
        setHasHeight();
    }
    Gfc2Double getHeight() const {return m_dHeight;}
    bool hasHeight() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setChord(const Gfc2Double& dValue)
    {
        m_dChord = dValue;
        setHasChord();
    }
    Gfc2Double getChord() const {return m_dChord;}
    bool hasChord() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setCheckInnerChord(const Gfc2Boolean& bValue)
    {
        m_bCheckInnerChord = bValue;
        setHasCheckInnerChord();
    }
    Gfc2Boolean getCheckInnerChord() const {return m_bCheckInnerChord;}
    bool hasCheckInnerChord() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasAxialLine() {_has_bits_[0] |= 0x1u;}
    void setHasHeight() {_has_bits_[0] |= 0x2u;}
    void setHasChord() {_has_bits_[0] |= 0x4u;}
    void setHasCheckInnerChord() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nAxialLine;
    Gfc2Double m_dHeight;
    Gfc2Double m_dChord;
    Gfc2Boolean m_bCheckInnerChord;
};
#endif
