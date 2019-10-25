#ifndef SERIALIZERMANAGER_H
#define SERIALIZERMANAGER_H

#include <vector>
#include <utility>
#include <memory>
#include <string>
#include <Windows.h>

namespace glodon {
namespace objectbuf {

class ReaderImp;
class WriterImp;
class SerializerManager;

typedef std::tr1::shared_ptr<SerializerManager> SerializerManagerPtr;

struct SerializerInfo
{
    SerializerInfo(): handle(0), readerImp(nullptr), writerImp(nullptr) {}
    HMODULE handle;
    std::string type;
    ReaderImp* readerImp;
    WriterImp* writerImp;
};

class SerializerManager
{
public:
    ~SerializerManager();
    int getCount();
    ReaderImp* getReaderImp(int nIndex);
    WriterImp* getWriterImp(const std::string& sType);
    static SerializerManagerPtr getInstance();
private:
    SerializerManager();
    void init();
    void free();
    std::vector<SerializerInfo> m_oSerializerList;
    static std::weak_ptr<SerializerManager> m_pSerializerManager;
};

}
}

#endif // !SERIALIZERMANAGER_H

