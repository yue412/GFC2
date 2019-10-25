#ifndef GFC2NURBSCTRLPT3D_H
#define GFC2NURBSCTRLPT3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Vector3d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2NurbsCtrlPt3d: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2NurbsCtrlPt3d,glodon::objectbuf::Entity)
public:
    Gfc2NurbsCtrlPt3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setPoint(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPoint = nValue;
        setHasPoint();
    }
    glodon::objectbuf::EntityRef getPoint() const {return m_nPoint;}
    bool hasPoint() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector3d* getPointPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getPoint());}
    void setWeight(const Gfc2Double& dValue)
    {
        m_dWeight = dValue;
        setHasWeight();
    }
    Gfc2Double getWeight() const {return m_dWeight;}
    bool hasWeight() const {return (_has_bits_[0] & 0x2u) != 0;}

protected:
    unsigned _has_bits_[1];
private:
    void setHasPoint() {_has_bits_[0] |= 0x1u;}
    void setHasWeight() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nPoint;
    Gfc2Double m_dWeight;
};
#endif
