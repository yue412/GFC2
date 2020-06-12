#ifndef GLODON_OBJECTBUF_READER_H
#define GLODON_OBJECTBUF_READER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\Container.h"

namespace gfc {
    namespace schema {
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CDocument;
class CReaderImp;

//typedef void (*RegSchemaInfoProc) (Reader* reader);
//typedef void (*FieldCacheProc) ();
//typedef std::map<wstring, std::pair<EntityFactory*, FieldCacheInitializer*>> SchemaInfoMap;

struct __declspec(dllexport) std::_Container_base12;
template class __declspec(dllexport) std::_Vector_val<std::_Simple_types<std::wstring>>;
template class __declspec(dllexport) std::_Compressed_pair<std::_Wrap_alloc<std::allocator<std::wstring>>, std::_Vector_val<std::_Simple_types<std::wstring>>, true>;
template class __declspec(dllexport) std::vector<std::wstring, std::allocator<std::wstring>>;

class GFCENGINE_API CReader : public IContainer
{
public:
    CReader(gfc::schema::CModel* pModel);
    virtual ~CReader(void);
    void setSchemaPath(const std::wstring& sSchemaPath) { m_sSchemaPath = sSchemaPath; }
    bool open(const std::wstring& sFileName);
    void close();

    void read(CDocument* pDoc);

    virtual EntityPtr getEntity(EntityRef nId);
    virtual EntityIteratorPtr getEntities(const std::wstring& sType, bool bIncludeSubType = false);
    virtual EntityIteratorPtr getIterator();

    std::vector<std::wstring>& log() { return m_oErrors; }
private:
    //Entity* read();
    std::vector<std::wstring> m_oErrors;
    CReaderImp* m_pImp;
    gfc::schema::CModel* m_pModel;
    std::wstring m_sSchemaPath;
};

GFCENGINE_NAMESPACE_END

#endif

