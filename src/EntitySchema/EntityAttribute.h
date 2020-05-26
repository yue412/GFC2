#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN

class CTypeObject;

class CAttribute
{
public:
    CAttribute();
    std::wstring& getName() {return m_sName;}
    void SetName(const std::wstring& sName) {m_sName = sName;}
    CTypeObject* getType() {return m_pTypeObject;}
    void SetType(CTypeObject* pType);
    bool getOptionalFlag() {return m_bOptional;}
    void SetOptionalFlag(bool bOptional) {m_bOptional = bOptional;}
    bool getRepeatFlag() {return m_bRepeat;}
    void SetRepeatFlag(bool bRepeat) {m_bRepeat = bRepeat;}
    //bool getRefFlag();
    //void setRefFlag(bool bRefFlag);
    std::wstring getDocument() { return m_sDocument; }
    void setDocument(const std::wstring& sDocument) { m_sDocument = sDocument; }
    std::wstring getTypeName();
private:
    std::wstring m_sName;
    std::wstring m_sDocument;
    CTypeObject* m_pTypeObject;
    bool m_bOptional;
    bool m_bRepeat;
    //bool m_bRefFlag;
};

GFC_NAMESPACE_END

#endif // ATTRIBUTE_H
