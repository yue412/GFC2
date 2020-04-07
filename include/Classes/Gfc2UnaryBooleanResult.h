#ifndef GFC2UNARYBOOLEANRESULT_H
#define GFC2UNARYBOOLEANRESULT_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2BooleanResult.h"
#include "Gfc2SolidShape.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2UnaryBooleanResult: public Gfc2BooleanResult
{
OBJECTBUF_DEC_OBJECT(Gfc2UnaryBooleanResult,glodon::objectbuf::Entity)
public:
    Gfc2UnaryBooleanResult();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setOperand(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nOperand = nValue;
        setHasOperand();
    }
    glodon::objectbuf::EntityRef getOperand() const {return m_nOperand;}
    bool hasOperand() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2SolidShape* getOperandPtr() const {return (Gfc2SolidShape*)m_pDocument->find(getOperand());}

private:
    void setHasOperand() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nOperand;
};
#endif
