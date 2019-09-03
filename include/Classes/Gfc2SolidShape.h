#ifndef GFC2SOLIDSHAPE_H
#define GFC2SOLIDSHAPE_H

#include "GfcClasses.h"
#include <vector>
#include "Gfc2Shape3d.h"
#include "Gfc2Body.h"
#include "Gfc2EdgeData.h"
#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/FieldCacheInitializer.h"

class GFCCLASSES_API Gfc2SolidShape: public Gfc2Shape3d
{
OBJECTBUF_DEC_OBJECT(Gfc2SolidShape,glodon::objectbuf::Entity)
public:
    Gfc2SolidShape();
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
    int getEdgeDatasCount() const {return (int)m_oEdgeDatas.size();}
    void clearEdgeDatas() {m_oEdgeDatas.clear();}
    void addEdgeDatas(const glodon::objectbuf::EntityRef& nValue) {m_oEdgeDatas.push_back(nValue);}
    glodon::objectbuf::EntityRef getEdgeDatas(int nIndex) const {return m_oEdgeDatas[nIndex];}
    Gfc2EdgeData* getEdgeDatasPtr(int nIndex) const {return (Gfc2EdgeData*)m_pDocument->find(getEdgeDatas(nIndex));}

private:
    void setHasBody() {_has_bits_[0] |= 0x4u;}

    glodon::objectbuf::EntityRef m_nBody;
    std::vector<glodon::objectbuf::EntityRef> m_oEdgeDatas;
};

class GFCCLASSES_API Gfc2SolidShapeFieldCacheInitializer: public glodon::objectbuf::FieldCacheInitializer
{
OBJECTBUF_DEC_OBJECT(Gfc2SolidShapeFieldCacheInitializer,glodon::objectbuf::FieldCacheInitializer)
public:
    virtual void init(const std::map<std::string, int>& oFieldIdMap);

};
#endif
