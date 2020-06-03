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

class Document;
class ReaderImp;

//typedef void (*RegSchemaInfoProc) (Reader* reader);
//typedef void (*FieldCacheProc) ();
//typedef std::map<wstring, std::pair<EntityFactory*, FieldCacheInitializer*>> SchemaInfoMap;

struct GFCENGINE_API std::_Container_base12;
template class GFCENGINE_API std::_Vector_val<std::_Simple_types<std::wstring>>;
template class GFCENGINE_API std::_Compressed_pair<std::_Wrap_alloc<std::allocator<std::wstring>>, std::_Vector_val<std::_Simple_types<std::wstring>>, true>;
template class GFCENGINE_API std::vector<std::wstring, std::allocator<std::wstring>>;

class GFCENGINE_API Reader
{
public:
    Reader(gfc::schema::CModel* pModel);
    virtual ~Reader(void);
    bool open(const std::wstring& sFileName);
    void close();

    void read(Document* pDoc);

    EntityPtr getEntity(EntityRef nId);
    EntityIteratorPtr getEntities(const std::wstring& sType, bool bIncludeSubType = false);

    std::vector<std::wstring>& log() { return m_oErrors; }
private:
    //Entity* read();
    std::vector<std::wstring> m_oErrors;
    ReaderImp* m_pImp;
    gfc::schema::CModel* m_pModel;
};

GFCENGINE_NAMESPACE_END

#endif

