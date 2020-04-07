#ifndef GFC2HALFSPACESOLIDSHAPE_H
#define GFC2HALFSPACESOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SolidShape.h"
#include "Gfc2Surface.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2HalfSpaceSolidShape: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2HalfSpaceSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2HalfSpaceSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setBaseSurface(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBaseSurface = nValue;
        setHasBaseSurface();
    }
    glodon::objectbuf::EntityRef getBaseSurface() const {return m_nBaseSurface;}
    bool hasBaseSurface() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Surface* getBaseSurfacePtr() const {return (Gfc2Surface*)m_pDocument->find(getBaseSurface());}
    void setAgreementFlag(const Gfc2Boolean& bValue)
    {
        m_bAgreementFlag = bValue;
        setHasAgreementFlag();
    }
    Gfc2Boolean getAgreementFlag() const {return m_bAgreementFlag;}
    bool hasAgreementFlag() const {return (_has_bits_[0] & 0x8u) != 0;}

private:
    void setHasBaseSurface() {_has_bits_[0] |= 0x4u;}
    void setHasAgreementFlag() {_has_bits_[0] |= 0x8u;}

    glodon::objectbuf::EntityRef m_nBaseSurface;
    Gfc2Boolean m_bAgreementFlag;
};
#endif
