#ifndef READERTEXTIMP_H
#define READERTEXTIMP_H

#include "ReaderImp.h"
#include <map>
#include <fstream>
using namespace std;
namespace glodon {
namespace objectbuf {

class Reader;
class EntityTextSerializer;

class ReaderTextImp: public ReaderImp
{
public:
    ReaderTextImp();
    virtual ~ReaderTextImp(void);
    bool read(const string& sFileName, Document* pDoc, std::vector<std::string>& errors);
	string projectId(const string& sFileName);
private:
    string getFileSchema(fstream& in);
    bool locate(fstream& in, const string& sWord);

    std::map<std::string, EntityTextSerializer*> m_oSerMap;
};

}
}

#endif
