#ifndef GFC2ABNORMITYLINEARCHINFO_H
#define GFC2ABNORMITYLINEARCHINFO_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2BaseLineArcInfo.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2AbnormityLineArchInfo: public Gfc2BaseLineArcInfo
{
OBJECTBUF_DEC_OBJECT(Gfc2AbnormityLineArchInfo,glodon::objectbuf::Entity)
public:
    Gfc2AbnormityLineArchInfo();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setTopArchStartT(const Gfc2Double& dValue)
    {
        m_dTopArchStartT = dValue;
        setHasTopArchStartT();
    }
    Gfc2Double getTopArchStartT() const {return m_dTopArchStartT;}
    bool hasTopArchStartT() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setTopArchEndT(const Gfc2Double& dValue)
    {
        m_dTopArchEndT = dValue;
        setHasTopArchEndT();
    }
    Gfc2Double getTopArchEndT() const {return m_dTopArchEndT;}
    bool hasTopArchEndT() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setTopDefineByRadius(const Gfc2Boolean& bValue)
    {
        m_bTopDefineByRadius = bValue;
        setHasTopDefineByRadius();
    }
    Gfc2Boolean getTopDefineByRadius() const {return m_bTopDefineByRadius;}
    bool hasTopDefineByRadius() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setTopArchHeight(const Gfc2Double& dValue)
    {
        m_dTopArchHeight = dValue;
        setHasTopArchHeight();
    }
    Gfc2Double getTopArchHeight() const {return m_dTopArchHeight;}
    bool hasTopArchHeight() const {return (_has_bits_[0] & 0x8u) != 0;}
    void setTopArchRadius(const Gfc2Double& dValue)
    {
        m_dTopArchRadius = dValue;
        setHasTopArchRadius();
    }
    Gfc2Double getTopArchRadius() const {return m_dTopArchRadius;}
    bool hasTopArchRadius() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setDownArchStartT(const Gfc2Double& dValue)
    {
        m_dDownArchStartT = dValue;
        setHasDownArchStartT();
    }
    Gfc2Double getDownArchStartT() const {return m_dDownArchStartT;}
    bool hasDownArchStartT() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setDownArchEndT(const Gfc2Double& dValue)
    {
        m_dDownArchEndT = dValue;
        setHasDownArchEndT();
    }
    Gfc2Double getDownArchEndT() const {return m_dDownArchEndT;}
    bool hasDownArchEndT() const {return (_has_bits_[0] & 0x40u) != 0;}
    void setDownDefineByRadius(const Gfc2Boolean& bValue)
    {
        m_bDownDefineByRadius = bValue;
        setHasDownDefineByRadius();
    }
    Gfc2Boolean getDownDefineByRadius() const {return m_bDownDefineByRadius;}
    bool hasDownDefineByRadius() const {return (_has_bits_[0] & 0x80u) != 0;}
    void setDownArchHeight(const Gfc2Double& dValue)
    {
        m_dDownArchHeight = dValue;
        setHasDownArchHeight();
    }
    Gfc2Double getDownArchHeight() const {return m_dDownArchHeight;}
    bool hasDownArchHeight() const {return (_has_bits_[0] & 0x100u) != 0;}
    void setDownArchRadius(const Gfc2Double& dValue)
    {
        m_dDownArchRadius = dValue;
        setHasDownArchRadius();
    }
    Gfc2Double getDownArchRadius() const {return m_dDownArchRadius;}
    bool hasDownArchRadius() const {return (_has_bits_[0] & 0x200u) != 0;}

private:
    void setHasTopArchStartT() {_has_bits_[0] |= 0x1u;}
    void setHasTopArchEndT() {_has_bits_[0] |= 0x2u;}
    void setHasTopDefineByRadius() {_has_bits_[0] |= 0x4u;}
    void setHasTopArchHeight() {_has_bits_[0] |= 0x8u;}
    void setHasTopArchRadius() {_has_bits_[0] |= 0x10u;}
    void setHasDownArchStartT() {_has_bits_[0] |= 0x20u;}
    void setHasDownArchEndT() {_has_bits_[0] |= 0x40u;}
    void setHasDownDefineByRadius() {_has_bits_[0] |= 0x80u;}
    void setHasDownArchHeight() {_has_bits_[0] |= 0x100u;}
    void setHasDownArchRadius() {_has_bits_[0] |= 0x200u;}

    Gfc2Double m_dTopArchStartT;
    Gfc2Double m_dTopArchEndT;
    Gfc2Boolean m_bTopDefineByRadius;
    Gfc2Double m_dTopArchHeight;
    Gfc2Double m_dTopArchRadius;
    Gfc2Double m_dDownArchStartT;
    Gfc2Double m_dDownArchEndT;
    Gfc2Boolean m_bDownDefineByRadius;
    Gfc2Double m_dDownArchHeight;
    Gfc2Double m_dDownArchRadius;
};

class GFCCLASSES_API Gfc2AbnormityLineArchInfoFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2AbnormityLineArchInfoFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
