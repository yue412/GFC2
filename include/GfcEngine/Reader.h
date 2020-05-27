#ifndef GLODON_OBJECTBUF_READER_H
#define GLODON_OBJECTBUF_READER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\Container.h"

using namespace std;

GFCENGINE_NAMESPACE_BEGIN

class Document;
class EntityFactory;
class ReaderImp;

//typedef void (*RegSchemaInfoProc) (Reader* reader);
//typedef void (*FieldCacheProc) ();
//typedef std::map<string, std::pair<EntityFactory*, FieldCacheInitializer*>> SchemaInfoMap;

class GFCENGINE_API Reader
{
public:
    Reader(EntityFactory* pFactory);
    virtual ~Reader(void);
    bool open(const string& sFileName);
    void close();

    void read(Document* pDoc);

    EntityPtr getEntity(EntityRef nId);
    EntityIteratorPtr getEntities(const std::string& sType, bool bIncludeSubType = false);

    std::vector<std::string> log() { return m_oErrors; }
private:
    //Entity* read();
    std::vector<std::string> m_oErrors;
    ReaderImp* m_pImp;
    EntityFactory* m_pFactory;
};

GFCENGINE_NAMESPACE_END

#endif

