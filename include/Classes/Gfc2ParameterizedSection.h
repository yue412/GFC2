#ifndef GFC2PARAMETERIZEDSECTION_H
#define GFC2PARAMETERIZEDSECTION_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Section.h"
#include "Gfc2Coordinates3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ParameterizedSection: public Gfc2Section
{
OBJECTBUF_DEC_OBJECT(Gfc2ParameterizedSection,glodon::objectbuf::Entity)
public:
    Gfc2ParameterizedSection();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPosition(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPosition = nValue;
        setHasPosition();
    }
    glodon::objectbuf::EntityRef getPosition() const {return m_nPosition;}
    bool hasPosition() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Coordinates3d* getPositionPtr() const {return (Gfc2Coordinates3d*)m_pDocument->find(getPosition());}

private:
    void setHasPosition() {_has_bits_[0] |= 0x1u;}

    glodon::objectbuf::EntityRef m_nPosition;
};
#endif
