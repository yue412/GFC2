#ifndef WRITER_NET_H
#define WRITER_NET_H

#include "GfcEngine/Entity.h"
#include "GfcEngine/Writer.h"
#include "Entity.h"

namespace gfc { namespace engine { namespace net {

using namespace System;

public ref class Writer
{
public:
    Writer(String^ sProductCode);
    ~Writer();
    bool open(String^ sFileName, String^ sFormatType);
    void close();
    gfc::engine::EntityRef writeEntity(Entity^ pEntity); 
private:
    gfc::engine::CWriter* m_pWriter;
};

}}}

#endif
