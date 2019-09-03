#ifndef GLODON_OBJECTBUF_WRITER_H
#define GLODON_OBJECTBUF_WRITER_H

#include <string>
#include <string>
#include "glodon/objectbuf/Entity.h"

using namespace std;
namespace glodon {
namespace objectbuf {

class WriterImp;

class OBJECTBUF_API Writer
{
public:
    Writer(void);
    ~Writer(void);
    bool open(const string& sFileName, bool bIsBinary = true, const string& sProductCode = "");
    void close();
    EntityRef writeEntity(Entity* pEntity); 
private:
    WriterImp* m_pImp;
};

}
}

#endif
