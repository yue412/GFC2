#ifndef GLODON_OBJECTBUF_WRITER_H
#define GLODON_OBJECTBUF_WRITER_H

#include <string>
#include <memory>
#include "GfcEngine\Entity.h"
#include "GfcEngine\Document.h"

using namespace std;

GFCENGINE_NAMESPACE_BEGIN

class WriterImp;

class GFCENGINE_API Writer
{
public:
    Writer(void);
    ~Writer(void);
    bool open(const string& sFileName, const std::string& sFormatType, const string& sVersion, const string& sProductCode = "");
    void close();
    EntityRef writeEntity(Entity* pEntity); 
private:
    WriterImp* m_pImp;
};

GFCENGINE_NAMESPACE_END

#endif
