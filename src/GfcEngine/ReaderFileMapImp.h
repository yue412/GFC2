#ifndef READERFILEMAPIMP_H
#define READERFILEMAPIMP_H

#include <string>
#include <vector>
#include "ReaderImp.h"
#include "GfcEngine/Container.h"

namespace gfc {
    namespace schema {
        class CModel;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CDocument;
class CFileMap;
struct EntityInfo;
class CEntityUpgrader;

template<class T> class CContainerImp;

class CReaderFileMapImp : public CReaderImp
{
    GFCENGINE_DEC_FACTORY(CReaderImp, 0, std::wstring)
public:
    CReaderFileMapImp();
    virtual ~CReaderFileMapImp(void);
    virtual bool open(const std::wstring& sFileName);
    virtual void close();
    virtual void read(CDocument* pDoc);

    // 继承 IContainer接口
    virtual EntityPtr getEntity(EntityRef nId);
    virtual EntityIteratorPtr getEntities(const std::wstring& sType, bool bIncludeSubType = false);
    virtual EntityIteratorPtr getIterator();
protected:
    virtual bool getIndex(EntityInfo& oInfo) = 0;//顺序读取index
    virtual CEntity* createEntity(int64_t nPos) = 0;

    CFileMap* m_pFileMap;
private:
    void buildIndex();
    void addInfo(const EntityInfo& oInfo);

    CContainerImp<EntityInfo>* m_pContainer;
};

struct EntityInfo
{
    EntityInfo(EntityRef nId, int64_t nPos, gfc::schema::CTypeObject* pType) : id(nId), pos(nPos), type(pType) {}
    EntityInfo(): id(-1), pos(0), type(nullptr) {}
    EntityRef id;
    int64_t pos;
    gfc::schema::CTypeObject* type;
    gfc::schema::CClass* getClass() const;
    EntityInfo* get() const;
	void setRef(EntityRef nRef) { id = nRef; }
	EntityRef ref() const { return id; }
    EntityInfo *operator->() const
    {	// return pointer to resource
        return (EntityInfo*)this;
    }
};

GFCENGINE_NAMESPACE_END

#endif
