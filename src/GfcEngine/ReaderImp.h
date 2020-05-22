#ifndef READERIMP_H
#define READERIMP_H

#include <string>
#include <vector>
#include "GfcEngine\Reader.h"
using namespace std;

namespace glodon {
namespace objectbuf {

class Document;

class GFCENGINE_API ReaderImp
{
public:
    ReaderImp();
    virtual ~ReaderImp(void);
    virtual bool read(const string& sFileName, Document* pDoc,std::vector<std::string>& errors) = 0;
    virtual bool preRead(const string& sFileName) = 0; // 判断是否是可以读的格式
};

}
}

#endif
