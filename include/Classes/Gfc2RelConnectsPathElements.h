#ifndef GFC2RELCONNECTSPATHELEMENTS_H
#define GFC2RELCONNECTSPATHELEMENTS_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2RelConnectsElements.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2RelConnectsPathElements: public Gfc2RelConnectsElements
{
OBJECTBUF_DEC_OBJECT(Gfc2RelConnectsPathElements,glodon::objectbuf::Entity)
public:
    Gfc2RelConnectsPathElements();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setRelatedConnectionType(const Gfc2ConnectionType& nValue)
    {
        m_nRelatedConnectionType = nValue;
        setHasRelatedConnectionType();
    }
    Gfc2ConnectionType getRelatedConnectionType() const {return m_nRelatedConnectionType;}
    bool hasRelatedConnectionType() const {return (_has_bits_[0] & 0x10u) != 0;}
    void setRelatingConnectionType(const Gfc2ConnectionType& nValue)
    {
        m_nRelatingConnectionType = nValue;
        setHasRelatingConnectionType();
    }
    Gfc2ConnectionType getRelatingConnectionType() const {return m_nRelatingConnectionType;}
    bool hasRelatingConnectionType() const {return (_has_bits_[0] & 0x20u) != 0;}

private:
    void setHasRelatedConnectionType() {_has_bits_[0] |= 0x10u;}
    void setHasRelatingConnectionType() {_has_bits_[0] |= 0x20u;}

    Gfc2ConnectionType m_nRelatedConnectionType;
    Gfc2ConnectionType m_nRelatingConnectionType;
};
#endif
