#ifndef GFC2SIZEMARK_H
#define GFC2SIZEMARK_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Entity.h"
#include "Gfc2CoedgeList.h"
#include "Gfc2CoedgeList.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2SizeMark: public Gfc2Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2SizeMark,glodon::objectbuf::Entity)
public:
    Gfc2SizeMark();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setSizeMarkType(const Gfc2SizeMarkType& nValue)
    {
        m_nSizeMarkType = nValue;
        setHasSizeMarkType();
    }
    Gfc2SizeMarkType getSizeMarkType() const {return m_nSizeMarkType;}
    bool hasSizeMarkType() const {return (_has_bits_[0] & 0x20u) != 0;}
    void setStartLine(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nStartLine = nValue;
        setHasStartLine();
    }
    glodon::objectbuf::EntityRef getStartLine() const {return m_nStartLine;}
    bool hasStartLine() const {return (_has_bits_[0] & 0x40u) != 0;}
    Gfc2CoedgeList* getStartLinePtr() const {return (Gfc2CoedgeList*)m_pDocument->find(getStartLine());}
    void setEndLine(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nEndLine = nValue;
        setHasEndLine();
    }
    glodon::objectbuf::EntityRef getEndLine() const {return m_nEndLine;}
    bool hasEndLine() const {return (_has_bits_[0] & 0x80u) != 0;}
    Gfc2CoedgeList* getEndLinePtr() const {return (Gfc2CoedgeList*)m_pDocument->find(getEndLine());}

private:
    void setHasSizeMarkType() {_has_bits_[0] |= 0x20u;}
    void setHasStartLine() {_has_bits_[0] |= 0x40u;}
    void setHasEndLine() {_has_bits_[0] |= 0x80u;}

    Gfc2SizeMarkType m_nSizeMarkType;
    glodon::objectbuf::EntityRef m_nStartLine;
    glodon::objectbuf::EntityRef m_nEndLine;
};

class GFCCLASSES_API Gfc2SizeMarkFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SizeMarkFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
