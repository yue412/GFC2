#ifndef GFC2SURFACETEXTURE_H
#define GFC2SURFACETEXTURE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2String.h"
#include "Gfc2Matrix.h"
#include "Gfc2String.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2SurfaceTexture: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2SurfaceTexture,glodon::objectbuf::Entity)
public:
    Gfc2SurfaceTexture();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRepeatS(const Gfc2Boolean& bValue)
    {
        m_bRepeatS = bValue;
        setHasRepeatS();
    }
    Gfc2Boolean getRepeatS() const {return m_bRepeatS;}
    bool hasRepeatS() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setRepeatT(const Gfc2Boolean& bValue)
    {
        m_bRepeatT = bValue;
        setHasRepeatT();
    }
    Gfc2Boolean getRepeatT() const {return m_bRepeatT;}
    bool hasRepeatT() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setImageFileName(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nImageFileName = nValue;
        setHasImageFileName();
    }
    glodon::objectbuf::EntityRef getImageFileName() const {return m_nImageFileName;}
    bool hasImageFileName() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2String* getImageFileNamePtr() const {return (Gfc2String*)m_pDocument->find(getImageFileName());}
    void setTranfromsMatirx(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nTranfromsMatirx = nValue;
        setHasTranfromsMatirx();
    }
    glodon::objectbuf::EntityRef getTranfromsMatirx() const {return m_nTranfromsMatirx;}
    bool hasTranfromsMatirx() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2Matrix* getTranfromsMatirxPtr() const {return (Gfc2Matrix*)m_pDocument->find(getTranfromsMatirx());}
    int getParameterCount() const {return (int)m_oParameter.size();}
    void clearParameter() {m_oParameter.clear();}
    void addParameter(const glodon::objectbuf::EntityRef& nValue) {m_oParameter.push_back(nValue);}
    glodon::objectbuf::EntityRef getParameter(int nIndex) const {return m_oParameter[nIndex];}
    Gfc2String* getParameterPtr(int nIndex) const {return (Gfc2String*)m_pDocument->find(getParameter(nIndex));}

protected:
    unsigned _has_bits_[1];
private:
    void setHasRepeatS() {_has_bits_[0] |= 0x1u;}
    void setHasRepeatT() {_has_bits_[0] |= 0x2u;}
    void setHasImageFileName() {_has_bits_[0] |= 0x4u;}
    void setHasTranfromsMatirx() {_has_bits_[0] |= 0x8u;}

    Gfc2Boolean m_bRepeatS;
    Gfc2Boolean m_bRepeatT;
    glodon::objectbuf::EntityRef m_nImageFileName;
    glodon::objectbuf::EntityRef m_nTranfromsMatirx;
    std::vector<glodon::objectbuf::EntityRef> m_oParameter;
};
#endif
