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

class CDocument;
class CFileMap;
struct EntityInfo;
class CEntityUpgrader;

template<class T> class CContainerImp;

class CReaderImp : public CObject, public IContainer
{
    GFCENGINE_DEC_FACTORY(CReaderImp, 0, std::wstring)
public:
    CReaderImp();
    virtual ~CReaderImp(void);
    virtual bool open(const std::wstring& sFileName);
    virtual void close();
    void setModel(gfc::schema::CModel* pModel) { m_pModel = pModel; }
    void setSchemaPath(const std::wstring& sSchemaPath) { m_sSchemaPath = sSchemaPath; }
    void setUseStaticClass(bool bUseStaticClass) { m_bUseStaticClass = bUseStaticClass; }
    virtual void read(CDocument* pDoc);
    std::vector<std::wstring>& errors() { return m_oErrors; }

    virtual bool preRead(const std::wstring& sFileName) = 0; // 判断是否是可以读的格式
    virtual std::wstring readFileVersion() = 0;
    // 继承 IContainer接口
    virtual EntityPtr getEntity(EntityRef nId);
    virtual EntityIteratorPtr getEntities(const std::wstring& sType, bool bIncludeSubType = false);
    virtual EntityIteratorPtr getIterator();
protected:
    virtual bool getIndex(EntityInfo& oInfo) = 0;//顺序读取index
    virtual CEntity* createEntity(__int64 nPos, EntityRef& nId) = 0;
    void log(const std::wstring& sError);
    gfc::schema::CModel* schema(); 
    void initUpgrader();

    CFileMap* m_pFileMap;
    CEntityUpgrader* m_pUpgrader;
    bool m_bUseStaticClass;
private:
    //void sort();
    void buildIndex();
    void addInfo(const EntityInfo& oInfo);
    bool openFileModel(const std::wstring& sFileVer);
    bool needUpdate();

    //std::vector<EntityInfo> m_oEntityInfos; // 索引 保证有序
    //std::map<std::string, std::vector<std::size_t>*> m_oEntityInfoMap;
    CContainerImp<EntityInfo>* m_pContainer;
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
	void ref(EntityRef nRef) { id = nRef; }
	EntityRef ref() const { return id; }
};

GFCENGINE_NAMESPACE_END

#endif
