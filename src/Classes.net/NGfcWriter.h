#ifndef NWRITER_NET_H
#define NWRITER_NET_H

#include "GfcEngine/Writer.h"
#include "NGfcEntity.h"

using namespace System;

public ref class NGfcWriter
{
public:
    NGfcWriter(String^ sProductCode);
    ~NGfcWriter();
    bool open(String^ sFileName, String^ sFormatType);
    void close();
    gfc::engine::EntityRef writeEntity(NGfcEntity^ pEntity); 
private:
    gfc::engine::CWriter* m_pWriter;
};

#endif
