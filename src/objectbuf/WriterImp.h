#ifndef WRITERIMP_H
#define WRITERIMP_H

#include <string>
#include <string>
#include "glodon/objectbuf/Entity.h"
using namespace std;
namespace glodon {
namespace objectbuf {

class WriterImp
{
public:
    WriterImp(void);
    virtual ~WriterImp(void);

    virtual bool open(const string& sFileName,const string& sProductCode) = 0;
    virtual void close() = 0;
    virtual EntityRef writeEntity(Entity* pEntity) = 0; 
protected:
    int m_nCount;
};

}
}

#endif
