#ifndef READERIMP_H
#define READERIMP_H

#include <string>
#include <vector>
#include "glodon\objectbuf\Reader.h"
using namespace std;

namespace glodon {
namespace objectbuf {

class Document;

class OBJECTBUF_API ReaderImp
{
public:
    ReaderImp();
    virtual ~ReaderImp(void);
    virtual bool read(const string& sFileName, Document* pDoc,std::vector<std::string>& errors) = 0;
};

}
}

#endif
