#ifndef READERBINARYIMP_H
#define READERBINARYIMP_H

#include "ReaderImp.h"
#include "glodon/framework/OBObject.h"

namespace glodon {
namespace objectbuf {

class ReaderBinaryImp: public ReaderImp
{
public:
    ReaderBinaryImp(/*SchemaInfoMap* pSchemaInfoMap*/);
    virtual ~ReaderBinaryImp(void);
    bool read(const string& sFileName, Document* pDoc,std::vector<std::string>& errors);
private:
    std::map<int, CREATETHIS> m_oFactoryList;
};

}
}

#endif
