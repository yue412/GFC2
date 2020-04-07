#ifndef GFC2COEDGE_H
#define GFC2COEDGE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Topology.h"
#include "Gfc2Curve2d.h"
#include "TypeDef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"

class GFCCLASSES_API Gfc2Coedge: public Gfc2Topology
{
OBJECTBUF_DEC_OBJECT(Gfc2Coedge,glodon::objectbuf::Entity)
public:
    Gfc2Coedge();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setCurve(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nCurve = nValue;
        setHasCurve();
    }
    glodon::objectbuf::EntityRef getCurve() const {return m_nCurve;}
    bool hasCurve() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Curve2d* getCurvePtr() const {return (Gfc2Curve2d*)m_pDocument->find(getCurve());}
    void setEdgeIndex(const Gfc2Integer& nValue)
    {
        m_nEdgeIndex = nValue;
        setHasEdgeIndex();
    }
    Gfc2Integer getEdgeIndex() const {return m_nEdgeIndex;}
    bool hasEdgeIndex() const {return (_has_bits_[0] & 0x2u) != 0;}
    void setEdgeSameDir(const Gfc2Boolean& bValue)
    {
        m_bEdgeSameDir = bValue;
        setHasEdgeSameDir();
    }
    Gfc2Boolean getEdgeSameDir() const {return m_bEdgeSameDir;}
    bool hasEdgeSameDir() const {return (_has_bits_[0] & 0x4u) != 0;}

private:
    void setHasCurve() {_has_bits_[0] |= 0x1u;}
    void setHasEdgeIndex() {_has_bits_[0] |= 0x2u;}
    void setHasEdgeSameDir() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nCurve;
    Gfc2Integer m_nEdgeIndex;
    Gfc2Boolean m_bEdgeSameDir;
};
#endif
