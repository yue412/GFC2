#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN

class CTypeObject;

class CAttributeDataHandler;

class CAttribute
{
public:
    CAttribute();
    ~CAttribute();
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
    void setDataHandler(CAttributeDataHandler* pHandler) { m_pHandler = pHandler; }
    CAttributeDataHandler* getDataHandler() { return m_pHandler; }
private:
    std::wstring m_sName;
    std::wstring m_sDocument;
    CTypeObject* m_pTypeObject;
    CAttributeDataHandler* m_pHandler;
    bool m_bOptional;
    bool m_bRepeat;
    //bool m_bRefFlag;
};

class CAttributeDataHandler
{
public:
    CAttributeDataHandler(CAttribute* pOwner): m_pOwner(pOwner), m_nOffset(-1){ }
    virtual ~CAttributeDataHandler() {}
public:
    void setOffset(int nOffset) { m_nOffset = nOffset; }
    int getOffset() const { return m_nOffset; }
    int getDataSize() { return getRawDataSize() + 1; }
    virtual void init(char* pData) {}
    virtual void free(char* pData) {}
protected:
    virtual int getRawDataSize() { return 0; }
    CAttribute* m_pOwner;
private:
    int m_nOffset;
};

GFC_NAMESPACE_END

#endif // ATTRIBUTE_H
