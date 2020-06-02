#ifndef WRITERIMP_H
#define WRITERIMP_H

#include <string>
#include "GfcEngine\Entity.h"
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Object.h"
#include "GfcEngine\SysMarco.h"

GFCENGINE_NAMESPACE_BEGIN

class WriterImp: public Object
{
    GFCENGINE_DEC_FACTORY(WriterImp, 0, std::wstring)
public:
    WriterImp(void);
    virtual ~WriterImp(void);

    virtual bool open(const std::wstring& sFileName,const std::wstring& sProductCode, const std::wstring& sVersion) = 0;
    virtual void close() = 0;
    virtual EntityRef writeEntity(Entity* pEntity) = 0; 
protected:
    EntityRef m_nCount;
};

GFCENGINE_NAMESPACE_END

#endif
