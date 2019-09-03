#ifndef GLODON_OBJECTBUF_READER_H
#define GLODON_OBJECTBUF_READER_H

#include <string>
#include <vector>
#include <map>
#include "glodon/objectbuf/Objectbuf.h"
using namespace std;
namespace glodon {
namespace objectbuf {

class Document;
class EntityFactory;
class Reader;
class FieldCacheInitializer;

typedef void (*RegSchemaInfoProc) (Reader* reader);
typedef void (*FieldCacheProc) ();
//typedef std::map<string, std::pair<EntityFactory*, FieldCacheInitializer*>> SchemaInfoMap;

class OBJECTBUF_API Reader
{
public:
    Reader(FieldCacheProc pInitProc, FieldCacheProc pFreeProc);
    virtual ~Reader(void);
    bool read(const string& sFileName, Document* pDoc);

	string getProjectId(const string& sFileName);
	std::vector<std::string> log();
	string version();
private:
    void clear();
    bool isBinaryFile( const string &sFileName);

    FieldCacheProc m_pFreeProc;
	std::vector<std::string> errors;
};

}
}

#endif

