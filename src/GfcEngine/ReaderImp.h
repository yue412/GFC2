#ifndef READERIMP_H
#define READERIMP_H

#include <string>
#include <vector>
#include "GfcEngine\Reader.h"
#include "GfcEngine\SysMarco.h"

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

class ReaderImp : public Object
{
    GFCENGINE_DEC_FACTORY(ReaderImp, 0, std::string)
public:
    ReaderImp();
    virtual ~ReaderImp(void);
    bool open(const string& sFileName);
    void close();
    void setFactory(EntityFactory* pFactory) { m_pFactory = pFactory; }

    virtual bool preRead(const string& sFileName) = 0; // 判断是否是可以读的格式
    virtual void read(Document* pDoc,std::vector<std::string>& errors) = 0;
    EntityPtr getEntity(EntityRef nId);
    virtual EntityListIterator getEntities(const std::string& sType, bool bIncludeSubType = false) = 0;
protected:
    virtual bool getIndex(EntityInfo& oInfo) = 0;//顺序读取index
    virtual Entity* createEntity(EntityInfo& oInfo) = 0;
    EntityFactory* factory() { return m_pFactory; }
    gfc2::schema::CModel* schema();

    FileMap* m_pFileMap;
private:
    void sort();
    void buildIndex();
    void addInfo(const EntityInfo& oInfo);

    std::vector<EntityInfo> m_oEntityInfos; // 索引 保证有序
    std::map<std::string, std::vector<std::size_t>*> m_oEntityInfoMap;
    EntityFactory* m_pFactory;
};

struct EntityInfo
{
    EntityInfo(__int64 nId, __int64 nPos, gfc2::schema::CTypeObject* pType) : id(nId), pos(nPos), type(pType) {}
    EntityInfo() {}
    __int64 id;
    __int64 pos;
    gfc2::schema::CTypeObject* type;
};

GFCENGINE_NAMESPACE_END

#endif
