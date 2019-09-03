#ifndef GFC2BOX3D_H
#define GFC2BOX3D_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Geometry.h"
#include "Gfc2Vector3d.h"
#include "Gfc2Vector3d.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2Box3d: public Gfc2Geometry
{
OBJECTBUF_DEC_OBJECT(Gfc2Box3d,glodon::objectbuf::Entity)
public:
    Gfc2Box3d();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    void setMin(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nMin = nValue;
        setHasMin();
    }
    glodon::objectbuf::EntityRef getMin() const {return m_nMin;}
    bool hasMin() const {return (_has_bits_[0] & 0x1u) != 0;}
    Gfc2Vector3d* getMinPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getMin());}
    void setMax(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nMax = nValue;
        setHasMax();
    }
    glodon::objectbuf::EntityRef getMax() const {return m_nMax;}
    bool hasMax() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2Vector3d* getMaxPtr() const {return (Gfc2Vector3d*)m_pDocument->find(getMax());}

private:
    void setHasMin() {_has_bits_[0] |= 0x1u;}
    void setHasMax() {_has_bits_[0] |= 0x2u;}

    glodon::objectbuf::EntityRef m_nMin;
    glodon::objectbuf::EntityRef m_nMax;
};

class GFCCLASSES_API Gfc2Box3dFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2Box3dFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
