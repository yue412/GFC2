#ifndef GLODON_OBJECTBUF_READER_H
#define GLODON_OBJECTBUF_READER_H

#include <string>
#include <vector>
#include <map>
#include "GfcEngine/GfcEngine.h"
#include <memory>

using namespace std;

GFCENGINE_NAMESPACE_BEGIN

class Document;
//class EntityFactory;
class Reader;
class SerializerManager;

//typedef void (*RegSchemaInfoProc) (Reader* reader);
//typedef void (*FieldCacheProc) ();
//typedef std::map<string, std::pair<EntityFactory*, FieldCacheInitializer*>> SchemaInfoMap;

class GFCENGINE_API Reader
{
public:
    Reader();
    virtual ~Reader(void);
    bool read(const string& sFileName, Document* pDoc);
    std::vector<std::string> log() { return m_oErrors; }
private:
	std::vector<std::string> m_oErrors;
    std::tr1::shared_ptr<SerializerManager> m_pSerializerManager;
};

GFCENGINE_NAMESPACE_END

#endif

