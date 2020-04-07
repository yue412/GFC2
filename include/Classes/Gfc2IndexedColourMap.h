#ifndef GFC2INDEXEDCOLOURMAP_H
#define GFC2INDEXEDCOLOURMAP_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Color.h"
#include "Gfc2PrimitiveRenderable.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2IndexedColourMap: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2IndexedColourMap,glodon::objectbuf::Entity)
public:
    Gfc2IndexedColourMap();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setTransparency(const Gfc2Double& dValue)
    {
        m_dTransparency = dValue;
        setHasTransparency();
    }
    Gfc2Double getTransparency() const {return m_dTransparency;}
    bool hasTransparency() const {return (_has_bits_[0] & 0x1u) != 0;}
    int getColoursCount() const {return (int)m_oColours.size();}
    void clearColours() {m_oColours.clear();}
    void addColours(const glodon::objectbuf::EntityRef& nValue) {m_oColours.push_back(nValue);}
    glodon::objectbuf::EntityRef getColours(int nIndex) const {return m_oColours[nIndex];}
    Gfc2Color* getColoursPtr(int nIndex) const {return (Gfc2Color*)m_pDocument->find(getColours(nIndex));}
    int getColourIndexCount() const {return (int)m_oColourIndex.size();}
    void clearColourIndex() {m_oColourIndex.clear();}
    void addColourIndex(const Gfc2Integer& nValue) {m_oColourIndex.push_back(nValue);}
    Gfc2Integer getColourIndex(int nIndex) const {return m_oColourIndex[nIndex];}
    void setMappedTo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nMappedTo = nValue;
        setHasMappedTo();
    }
    glodon::objectbuf::EntityRef getMappedTo() const {return m_nMappedTo;}
    bool hasMappedTo() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2PrimitiveRenderable* getMappedToPtr() const {return (Gfc2PrimitiveRenderable*)m_pDocument->find(getMappedTo());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasTransparency() {_has_bits_[0] |= 0x1u;}
    void setHasMappedTo() {_has_bits_[0] |= 0x8u;}

    Gfc2Double m_dTransparency;
    std::vector<glodon::objectbuf::EntityRef> m_oColours;
    std::vector<Gfc2Integer> m_oColourIndex;
    glodon::objectbuf::EntityRef m_nMappedTo;
};
#endif
