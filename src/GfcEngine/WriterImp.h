#ifndef WRITERIMP_H
#define WRITERIMP_H

#include <string>
#include <set>
#include <Windows.h>
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
    EntityRef writeEntity(CEntity* pEntity); 
public:
    void addIgnoreDuplicates(const std::wstring& sEntityName);
    void setCodePage(UINT nCodePage);
    void setUppercase(bool bUppercase);
protected:
    virtual EntityRef doWriteEntity(CEntity* pEntity) = 0;
    EntityRef m_nCount;
    UINT m_nCodePage;
    bool m_bUppercase;
private:
    bool inIgnoreDuplicatesEntitySet(const std::wstring& sEntityName);
    std::map<std::wstring, EntityRef> m_oDuplicatesMap;
    std::set<std::wstring> m_oIgnoreDuplicatesEntitySet;
};

GFCENGINE_NAMESPACE_END

#endif
