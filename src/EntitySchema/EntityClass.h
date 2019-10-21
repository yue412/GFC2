#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include "TypeObject.h"

GFC_NAMESPACE_BEGIN

class CAttribute;

class CClass;

typedef std::vector<CClass*> CClassList;
typedef std::vector<CAttribute*> CAttributeList;

class CClass : public CTypeObject
{
public:
    CClass();
    CClass(const std::wstring& sName);
    virtual ~CClass();
    virtual CTypeObjectEnum getType() const {return TOE_CLASS;}
    bool getIsAbstract() {return m_bIsAbstract;}
    void setIsAbstract(bool bIsAbstract) {m_bIsAbstract = bIsAbstract;}
    //virtual bool getIsValueType() {return m_bIsValueType;}
    //void setIsValueType(bool bIsValueType) {m_bIsValueType = bIsValueType;}
    // ºÃ≥–
    CClass* getParent() {return m_pParent;}
    void setParent(CClass* pClass) {m_pParent = pClass;}
    int getChildCount() {return (int)m_oChildList.size();}
    CClass* getChild(int nIndex);
    void addChild(CClass* pClass);
    //  Ù–‘
    CAttribute *getAttribute(int nIndex);
    int getAttributeCount(){return (int)m_oAttributeList.size();}
    void addAttribute(CAttribute* pAttribute);
private:
    CClass* m_pParent;
    CClassList m_oChildList;
    CAttributeList m_oAttributeList;
    bool m_bIsAbstract;
    //bool m_bIsValueType;
};

GFC_NAMESPACE_END

#endif // CLASS_H
