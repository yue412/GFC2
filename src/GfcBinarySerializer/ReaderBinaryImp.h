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
    virtual bool read(const string& sFileName, Document* pDoc,std::vector<std::string>& errors);
    virtual bool preRead(const string& sFileName);
private:
    std::map<int, CREATETHIS> m_oFactoryList;
};

}
}

#endif
