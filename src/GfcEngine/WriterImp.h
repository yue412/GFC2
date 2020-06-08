#ifndef WRITERIMP_H
#define WRITERIMP_H

#include <string>
#include "GfcEngine\Entity.h"
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Object.h"
#include "GfcEngine\SysMarco.h"

GFCENGINE_NAMESPACE_BEGIN

class CWriterImp: public CObject
{
    GFCENGINE_DEC_FACTORY(CWriterImp, 0, std::wstring)
public:
    CWriterImp(void);
    virtual ~CWriterImp(void);

    virtual bool open(const std::wstring& sFileName,const std::wstring& sProductCode, const std::wstring& sVersion) = 0;
    virtual void close() = 0;
    virtual EntityRef writeEntity(CEntity* pEntity) = 0; 
protected:
    EntityRef m_nCount;
};

GFCENGINE_NAMESPACE_END

#endif
