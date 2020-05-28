#ifndef GLODON_OBJECTBUF_READER_H
#define GLODON_OBJECTBUF_READER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\Container.h"

GFCENGINE_NAMESPACE_BEGIN

class Document;
class EntityFactory;
class ReaderImp;

//typedef void (*RegSchemaInfoProc) (Reader* reader);
//typedef void (*FieldCacheProc) ();
//typedef std::map<string, std::pair<EntityFactory*, FieldCacheInitializer*>> SchemaInfoMap;

struct GFCENGINE_API std::_Container_base12;
template class GFCENGINE_API std::_Vector_val<std::_Simple_types<std::string>>;
template class GFCENGINE_API std::_Compressed_pair<std::_Wrap_alloc<std::allocator<std::string>>, std::_Vector_val<std::_Simple_types<std::string>>, true>;
template class GFCENGINE_API std::vector<std::string, std::allocator<std::string>>;

class GFCENGINE_API Reader
{
public:
    Reader(EntityFactory* pFactory);
    virtual ~Reader(void);
    bool open(const std::string& sFileName);
    void close();

    void read(Document* pDoc);

    EntityPtr getEntity(EntityRef nId);
    EntityIteratorPtr getEntities(const std::string& sType, bool bIncludeSubType = false);

    std::vector<std::string>& log() { return m_oErrors; }
private:
    //Entity* read();
    std::vector<std::string> m_oErrors;
    ReaderImp* m_pImp;
    EntityFactory* m_pFactory;
};

GFCENGINE_NAMESPACE_END

#endif

