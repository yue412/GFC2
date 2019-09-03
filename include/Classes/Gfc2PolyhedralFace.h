#ifndef GFC2POLYHEDRALFACE_H
#define GFC2POLYHEDRALFACE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2PolyhedralLoop.h"
#include "Gfc2PlaneCoef.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2PolyhedralFace: public glodon::objectbuf::Entity
{
OBJECTBUF_DEC_OBJECT(Gfc2PolyhedralFace,glodon::objectbuf::Entity)
public:
    Gfc2PolyhedralFace();
    bool isInitialized() const;
    int typeId() const;
    virtual glodon::objectbuf::EntitySchema* createSchema() const;
    virtual std::string entityName() const;
    int getLoopsCount() const {return (int)m_oLoops.size();}
    void clearLoops() {m_oLoops.clear();}
    void addLoops(const glodon::objectbuf::EntityRef& nValue) {m_oLoops.push_back(nValue);}
    glodon::objectbuf::EntityRef getLoops(int nIndex) const {return m_oLoops[nIndex];}
    Gfc2PolyhedralLoop* getLoopsPtr(int nIndex) const {return (Gfc2PolyhedralLoop*)m_pDocument->find(getLoops(nIndex));}
    void setPlane(const glodon::objectbuf::EntityRef& nValue)
    {
        m_nPlane = nValue;
        setHasPlane();
    }
    glodon::objectbuf::EntityRef getPlane() const {return m_nPlane;}
    bool hasPlane() const {return (_has_bits_[0] & 0x2u) != 0;}
    Gfc2PlaneCoef* getPlanePtr() const {return (Gfc2PlaneCoef*)m_pDocument->find(getPlane());}

protected:
    unsigned _has_bits_[1];
private:
    void setHasPlane() {_has_bits_[0] |= 0x2u;}

    std::vector<glodon::objectbuf::EntityRef> m_oLoops;
    glodon::objectbuf::EntityRef m_nPlane;
};

class GFCCLASSES_API Gfc2PolyhedralFaceFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2PolyhedralFaceFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
