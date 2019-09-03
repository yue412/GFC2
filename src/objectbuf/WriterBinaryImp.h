#ifndef WRITERBINARYIMP_H
#define WRITERBINARYIMP_H

#include <string>
#include <string>
#include "glodon/objectbuf/Entity.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <fstream>
#include <map>
#include "glodon/objectbuf/Objectbuf.h"
#include "WriterImp.h"

using namespace std;
namespace glodon {
namespace objectbuf {

class WriterBinaryImp: public WriterImp
{
public:
    WriterBinaryImp(void);
    virtual ~WriterBinaryImp(void);
    virtual bool open(const string& sFileName,const string& sProductCode);
    virtual void close();
    virtual EntityRef writeEntity(Entity* pEntity); 
private:
    void writeSchema(EntitySchema* pSchema);
    std::fstream* m_pFileStream;
    google::protobuf::io::OstreamOutputStream* m_pZeroCopyStream;
    google::protobuf::io::CodedOutputStream* m_pCodedOutputStream;
    std::map<int, bool> m_oTypeMap;
};

}
}

#endif
