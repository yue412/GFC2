#ifndef GFC2INDEXEDTEXTUREMAP_H
#define GFC2INDEXEDTEXTUREMAP_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2PrimitiveRenderable.h"
#include "Gfc2Vector2d.h"
#include "Gfc2SurfaceTexture.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2IndexedTextureMap: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2IndexedTextureMap,glodon::objectbuf::Entity)
public:
    Gfc2IndexedTextureMap();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setMappedTo(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nMappedTo = nValue;
        setHasMappedTo();
    }
    glodon::objectbuf::EntityRef getMappedTo() const {return m_nMappedTo;}
    bool hasMappedTo() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2PrimitiveRenderable* getMappedToPtr() const {return (Gfc2PrimitiveRenderable*)m_pDocument->find(getMappedTo());}
    int getTexCoordsCount() const {return (int)m_oTexCoords.size();}
    void clearTexCoords() {m_oTexCoords.clear();}
    void addTexCoords(const glodon::objectbuf::EntityRef& nValue) {m_oTexCoords.push_back(nValue);}
    glodon::objectbuf::EntityRef getTexCoords(int nIndex) const {return m_oTexCoords[nIndex];}
    Gfc2Vector2d* getTexCoordsPtr(int nIndex) const {return (Gfc2Vector2d*)m_pDocument->find(getTexCoords(nIndex));}
    int getTexCoordIndexCount() const {return (int)m_oTexCoordIndex.size();}
    void clearTexCoordIndex() {m_oTexCoordIndex.clear();}
    void addTexCoordIndex(const Gfc2Integer& nValue) {m_oTexCoordIndex.push_back(nValue);}
    Gfc2Integer getTexCoordIndex(int nIndex) const {return m_oTexCoordIndex[nIndex];}
    int getMapsCount() const {return (int)m_oMaps.size();}
    void clearMaps() {m_oMaps.clear();}
    void addMaps(const glodon::objectbuf::EntityRef& nValue) {m_oMaps.push_back(nValue);}
    glodon::objectbuf::EntityRef getMaps(int nIndex) const {return m_oMaps[nIndex];}
    Gfc2SurfaceTexture* getMapsPtr(int nIndex) const {return (Gfc2SurfaceTexture*)m_pDocument->find(getMaps(nIndex));}

protected:
    unsigned _has_bits_[1];
private:
    void setHasMappedTo() {_has_bits_[0] |= 0x1u;}

    glodon::objectbuf::EntityRef m_nMappedTo;
    std::vector<glodon::objectbuf::EntityRef> m_oTexCoords;
    std::vector<Gfc2Integer> m_oTexCoordIndex;
    std::vector<glodon::objectbuf::EntityRef> m_oMaps;
};
#endif
