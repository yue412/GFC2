#ifndef WRITERTEXTIMP_H
#define WRITERTEXTIMP_H

#include <string>
#include "glodon/objectbuf/Entity.h"
#include "WriterImp.h"
#include <fstream>
using namespace std;
namespace glodon {
namespace objectbuf {

// 内部实现，不对外公开
class WriterTextImp: public WriterImp
{
public:
    WriterTextImp(void);
    virtual ~WriterTextImp(void);
    virtual bool open(const string& sFileName, const string& sProductCode);
    virtual void close();
    virtual EntityRef writeEntity(Entity* pEntity); 
private:
    void writeHead(const string& sFileName, const string& sProductCode);
	fstream* m_pTextStream;
};

}
}

#endif
