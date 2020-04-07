#ifndef GFC2CSGSOLIDSHAPE_H
#define GFC2CSGSOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2SolidShape.h"
#include "Gfc2BooleanResult.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2CsgSolidShape: public Gfc2SolidShape
{
OBJECTBUF_DEC_OBJECT(Gfc2CsgSolidShape,glodon::objectbuf::Entity)
public:
    Gfc2CsgSolidShape();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setTreeRootExpression(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nTreeRootExpression = nValue;
        setHasTreeRootExpression();
    }
    glodon::objectbuf::EntityRef getTreeRootExpression() const {return m_nTreeRootExpression;}
    bool hasTreeRootExpression() const {return (_has_bits_[0] & 0x4u) != 0;}
    Gfc2BooleanResult* getTreeRootExpressionPtr() const {return (Gfc2BooleanResult*)m_pDocument->find(getTreeRootExpression());}

private:
    void setHasTreeRootExpression() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nTreeRootExpression;
};
#endif
