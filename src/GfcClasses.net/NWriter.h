#ifndef NWRITER_NET_H
#define NWRITER_NET_H

#include "GfcEngine/Writer.h"
#include "NEntity.h"

public ref class NWriter
{
public:
    NWriter(System::String^ sProductCode);
    ~NWriter();
    bool open(System::String^ sFileName, System::String^ sFormatType);
    void close();
    gfc::engine::EntityRef writeEntity(NEntity^ pEntity); 
    gfc::engine::CWriter* getWriter();
private:
    gfc::engine::CWriter* m_pWriter;
};

#endif
