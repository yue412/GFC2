#ifndef READERIMP_H
#define READERIMP_H

#include <string>
#include <vector>
#include "GfcEngine\Reader.h"
#include "GfcEngine\SysMarco.h"
#include "GfcEngine\Container.h"

namespace gfc {
    namespace schema {
        class CModel;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class Document;
class FileMap;
struct EntityInfo;
class Upgrader;

template<class T> class ContainerImp;

class ReaderImp : public Object, public IContainer
{
    GFCENGINE_DEC_FACTORY(ReaderImp, 0, std::wstring)
public:
    ReaderImp();
    virtual ~ReaderImp(void);
    bool open(const std::wstring& sFileName);
    void close();
    void setModel(gfc::schema::CModel* pModel) { m_pModel = pModel; }
    void setSchemaPath(const std::wstring& sSchemaPath) { m_sSchemaPath = sSchemaPath; }
    void read(Document* pDoc);
    std::vector<std::wstring>& errors() { return m_oErrors; }

    virtual bool preRead(const std::wstring& sFileName) = 0; // 判断是否是可以读的格式
    virtual std::wstring readFileVersion() = 0;
    // 继承 IContainer接口
    virtual EntityPtr getEntity(EntityRef nId);
    virtual EntityIteratorPtr getEntities(const std::wstring& sType, bool bIncludeSubType = false);
    virtual EntityIteratorPtr getIterator();
protected:
    virtual bool getIndex(EntityInfo& oInfo) = 0;//顺序读取index
    virtual Entity* createEntity(__int64 nPos, EntityRef& nId) = 0;
    void log(const std::wstring& sError);
    gfc::schema::CModel* schema(); 

    FileMap* m_pFileMap;
    Upgrader* m_pUpgrader;
private:
    //void sort();
    void buildIndex();
    void addInfo(const EntityInfo& oInfo);
    bool openFileModel(const std::wstring& sFileVer);
    bool needUpdate();

    //std::vector<EntityInfo> m_oEntityInfos; // 索引 保证有序
    //std::map<std::string, std::vector<std::size_t>*> m_oEntityInfoMap;
    ContainerImp<EntityInfo>* m_pContainer;
    gfc::schema::CModel* m_pModel;
    gfc::schema::CModel* m_pFileModel;
    std::wstring m_sSchemaPath;
    std::vector<std::wstring> m_oErrors;
};

struct EntityInfo
{
    EntityInfo(EntityRef nId, __int64 nPos, gfc::schema::CTypeObject* pType) : id(nId), pos(nPos), type(pType) {}
    EntityInfo(): id(-1), pos(0), type(nullptr) {}
    EntityRef id;
    __int64 pos;
    gfc::schema::CTypeObject* type;
    gfc::schema::CClass* getClass() const;
    EntityInfo* get() const;
};

GFCENGINE_NAMESPACE_END

#endif
