#ifndef GFC2BINARYBOOLEANRESULT_H
#define GFC2BINARYBOOLEANRESULT_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2BooleanResult.h"
#include "Gfc2SolidShape.h"
#include "Gfc2SolidShape.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2BinaryBooleanResult: public Gfc2BooleanResult
{
OBJECTBUF_DEC_OBJECT(Gfc2BinaryBooleanResult,glodon::objectbuf::Entity)
public:
    Gfc2BinaryBooleanResult();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setOperator(const Gfc2BooleanOperator& nValue)
    {
        m_nOperator = nValue;
        setHasOperator();
    }
    Gfc2BooleanOperator getOperator() const {return m_nOperator;}
    bool hasOperator() const {return (_has_bits_[0] & 0x4u) != 0;}
    void setFirstOperand(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nFirstOperand = nValue;
        setHasFirstOperand();
    }
    glodon::objectbuf::EntityRef getFirstOperand() const {return m_nFirstOperand;}
    bool hasFirstOperand() const {return (_has_bits_[0] & 0x8u) != 0;}
    Gfc2SolidShape* getFirstOperandPtr() const {return (Gfc2SolidShape*)m_pDocument->find(getFirstOperand());}
    void setSecondOperand(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nSecondOperand = nValue;
        setHasSecondOperand();
    }
    glodon::objectbuf::EntityRef getSecondOperand() const {return m_nSecondOperand;}
    bool hasSecondOperand() const {return (_has_bits_[0] & 0x10u) != 0;}
    Gfc2SolidShape* getSecondOperandPtr() const {return (Gfc2SolidShape*)m_pDocument->find(getSecondOperand());}

private:
    void setHasOperator() {_has_bits_[0] |= 0x4u;}
    void setHasFirstOperand() {_has_bits_[0] |= 0x8u;}
    void setHasSecondOperand() {_has_bits_[0] |= 0x10u;}

    Gfc2BooleanOperator m_nOperator;
    glodon::objectbuf::EntityRef m_nFirstOperand;
    glodon::objectbuf::EntityRef m_nSecondOperand;
};
#endif
