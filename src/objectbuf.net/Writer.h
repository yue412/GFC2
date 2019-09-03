#ifndef WRITER_NET_H
#define WRITER_NET_H

#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/Writer.h"
#include "Entity.h"

namespace glodon {
namespace objectbufnet {

using namespace System;

public ref class Writer
{
public:
    Writer(void);
    ~Writer();
    bool open(String^ sFileName, bool bIsBinary, String^ sProductCode);
    void close();
    glodon::objectbuf::EntityRef writeEntity(Entity^ pEntity); 
private:
    glodon::objectbuf::Writer* m_pWriter;
};

}
}

#endif
