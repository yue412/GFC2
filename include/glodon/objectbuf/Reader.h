#ifndef GLODON_OBJECTBUF_READER_H
#define GLODON_OBJECTBUF_READER_H

#include <string>
#include <vector>
#include <map>
#include "glodon/objectbuf/Objectbuf.h"
#include <memory>

using namespace std;
namespace glodon {
namespace objectbuf {

class Document;
//class EntityFactory;
class Reader;
class SerializerManager;

//typedef void (*RegSchemaInfoProc) (Reader* reader);
//typedef void (*FieldCacheProc) ();
//typedef std::map<string, std::pair<EntityFactory*, FieldCacheInitializer*>> SchemaInfoMap;

class OBJECTBUF_API Reader
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

}
}

#endif

