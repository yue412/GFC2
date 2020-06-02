#ifndef READERIMP_H
#define READERIMP_H

#include <string>
#include <vector>
#include "GfcEngine\Reader.h"
#include "GfcEngine\SysMarco.h"
#include "GfcEngine\Container.h"

namespace gfc2 {
    namespace schema {
        class CModel;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Document;
class FileMap;
class EntityFactory;
struct EntityInfo;

template<class T> class ContainerImp;

class ReaderImp : public Object, public IContainer
{
    GFCENGINE_DEC_FACTORY(ReaderImp, 0, std::wstring)
public:
    ReaderImp();
    virtual ~ReaderImp(void);
    bool open(const std::wstring& sFileName);
    void close();
    void setFactory(EntityFactory* pFactory) { m_pFactory = pFactory; }

    virtual bool preRead(const std::wstring& sFileName) = 0; // 判断是否是可以读的格式
    virtual void read(Document* pDoc,std::vector<std::wstring>& errors) = 0;
    // 继承 IContainer接口
    virtual EntityPtr getEntity(EntityRef nId);
    virtual EntityIteratorPtr getEntities(const std::wstring& sType, bool bIncludeSubType = false);
    virtual EntityIteratorPtr getIterator();
protected:
    virtual bool getIndex(EntityInfo& oInfo) = 0;//顺序读取index
    virtual Entity* createEntity(EntityInfo& oInfo) = 0;
    EntityFactory* factory() { return m_pFactory; }
    gfc2::schema::CModel* schema();

    FileMap* m_pFileMap;
private:
    //void sort();
    void buildIndex();
    void addInfo(const EntityInfo& oInfo);

    //std::vector<EntityInfo> m_oEntityInfos; // 索引 保证有序
    //std::map<std::string, std::vector<std::size_t>*> m_oEntityInfoMap;
    ContainerImp<EntityInfo>* m_pContainer;
    EntityFactory* m_pFactory;
};

struct EntityInfo
{
    EntityInfo(EntityRef nId, __int64 nPos, gfc2::schema::CTypeObject* pType) : id(nId), pos(nPos), type(pType) {}
    EntityInfo(): id(-1), pos(0), type(nullptr) {}
    EntityRef id;
    __int64 pos;
    gfc2::schema::CTypeObject* type;
    gfc2::schema::CClass* getClass() const;
    EntityInfo* get() const;
};

GFCENGINE_NAMESPACE_END

#endif
