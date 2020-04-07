#ifndef GFC2MANIFOLDSOLIDSHAPE_H
#define GFC2MANIFOLDSOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SolidShape.h"
#include "Gfc2Body.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2ManifoldSolidShape: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2ManifoldSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2ManifoldSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setBody(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nBody = nValue;
        setHasBody();
    }
    glodon::objectbuf::EntityRef getBody() const {return m_nBody;}
    bool hasBody() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2Body* getBodyPtr() const {return (Gfc2Body*)m_pDocument->find(getBody());}

private:
    void setHasBody() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nBody;
};
#endif
