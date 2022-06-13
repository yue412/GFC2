#ifndef NREADER_NET_H
#define NREADER_NET_H

#include "GfcEngine/Reader.h"
#include "NEntity.h"
#include "NDocument.h"

public ref class NReader
{
public:
    NReader();
    ~NReader();
    void setSchemaPath(System::String^ sSchemaPath);
    bool open(System::String^ sFileName);
    void close();

    void read(NDocument^ pDoc);
private:
    gfc::engine::CReader* m_pReader;
};

#endif
