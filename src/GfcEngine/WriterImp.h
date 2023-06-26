#ifndef WRITERIMP_H
#define WRITERIMP_H

#include <string>
#include <set>
#if (defined _WIN32 || defined _WIN64)
#include <Windows.h>
#endif
#include "GfcEngine/Entity.h"
#include "GfcEngine/GfcEngine.h"
#include "GfcEngine/Object.h"
#include "GfcEngine/SysMarco.h"

GFCENGINE_NAMESPACE_BEGIN

class CWriterImp: public CObject
{
    GFCENGINE_DEC_FACTORY(CWriterImp, 0, std::wstring)
public:
    CWriterImp(void);
    virtual ~CWriterImp(void);

    virtual bool open(const std::wstring& sFileName,const std::wstring& sProductCode, const std::wstring& sVersion, const std::wstring& sStandardVersion) = 0;
    virtual void close() = 0;
    EntityRef writeEntity(CEntity* pEntity); 
    void writeDoc(CDocument* pDoc);
public:
    void addIgnoreDuplicates(const std::wstring& sEntityName);
    void setCodePage(unsigned int nCodePage);
    void setUppercase(bool bUppercase);
protected:
    virtual void doWriteEntity(EntityRef nId, CEntity* pEntity) = 0;
    EntityRef innerWriteEntity(CEntity* pEntity);
    EntityRef m_nCount;
    unsigned int m_nCodePage;
    bool m_bUppercase;
private:
    bool inIgnoreDuplicatesEntitySet(const std::wstring& sEntityName);
    std::map<std::wstring, EntityRef> m_oDuplicatesMap;
    std::set<std::wstring> m_oIgnoreDuplicatesEntitySet;
};

GFCENGINE_NAMESPACE_END

#endif
