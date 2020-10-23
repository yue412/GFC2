#ifndef READERIMP_H
#define READERIMP_H

#include <string>
#include <vector>
#include "GfcEngine\Reader.h"
#include "GfcEngine\SysMarco.h"

namespace gfc {
    namespace schema {
        class CModel;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CDocument;
class CEntityUpgrader;

template<class T> class CContainerImp;

class CReaderImp : public CObject, public IContainer
{
    GFCENGINE_DEC_FACTORY(CReaderImp, 0, std::wstring)
public:
    CReaderImp();
    virtual ~CReaderImp(void);
    virtual bool open(const std::wstring& sFileName) = 0;
    virtual void close();
    void setModel(gfc::schema::CModel* pModel) { m_pModel = pModel; }
    void setSchemaPath(const std::wstring& sSchemaPath) { m_sSchemaPath = sSchemaPath; }
    void setUseStaticClass(bool bUseStaticClass) { m_bUseStaticClass = bUseStaticClass; }
    virtual void read(CDocument* pDoc) = 0;
    std::vector<std::wstring>& errors() { return m_oErrors; }

    virtual bool preRead(const std::wstring& sFileName) = 0; // 判断是否是可以读的格式
    virtual std::wstring readFileVersion() = 0;
    // 继承 IContainer接口
    virtual EntityPtr getEntity(EntityRef nId);
    virtual EntityIteratorPtr getEntities(const std::wstring& sType, bool bIncludeSubType = false);
    virtual EntityIteratorPtr getIterator();
protected:
    void log(const std::wstring& sError);
    gfc::schema::CModel* schema(); 
    void initUpgrader();
    bool openFileModel(const std::wstring& sFileVer);
    bool needUpdate();

    CEntityUpgrader* m_pUpgrader;
    bool m_bUseStaticClass;
    gfc::schema::CModel* m_pModel;
    gfc::schema::CModel* m_pFileModel;
    std::wstring m_sSchemaPath;
private:
    std::vector<std::wstring> m_oErrors;
};

GFCENGINE_NAMESPACE_END

#endif
