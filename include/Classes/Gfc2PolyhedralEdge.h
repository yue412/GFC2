#ifndef GFC2POLYHEDRALEDGE_H
#define GFC2POLYHEDRALEDGE_H

#include "GfcClasses.h"
#include <vector>
#include "TypeDef.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2PolyhedralEdge: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2PolyhedralEdge,glodon::objectbuf::Entity)
public:
    Gfc2PolyhedralEdge();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setStartVertexIndex(const Gfc2Integer& nValue)
    {
        m_nStartVertexIndex = nValue;
        setHasStartVertexIndex();
    }
    Gfc2Integer getStartVertexIndex() const {return m_nStartVertexIndex;}
    bool hasStartVertexIndex() const {return (_has_bits_[0] & 0x1u) != 0;}
    void setEndVertexIndex(const Gfc2Integer& nValue)
    {
        m_nEndVertexIndex = nValue;
        setHasEndVertexIndex();
    }
    Gfc2Integer getEndVertexIndex() const {return m_nEndVertexIndex;}
    bool hasEndVertexIndex() const {return (_has_bits_[0] & 0x2u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasStartVertexIndex() {_has_bits_[0] |= 0x1u;}
    void setHasEndVertexIndex() {_has_bits_[0] |= 0x2u;}

    Gfc2Integer m_nStartVertexIndex;
    Gfc2Integer m_nEndVertexIndex;
};

class GFCCLASSES_API Gfc2PolyhedralEdgeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PolyhedralEdgeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
