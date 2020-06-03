#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <map>
#include "GfcSchema\TypeObject.h"

GFC_NAMESPACE_BEGIN

class CAttribute;

class CClass;

typedef std::vector<CClass*> CClassList;
typedef std::vector<CAttribute*> CAttributeList;

template class __declspec(dllexport) std::_Vector_val<std::_Simple_types<gfc::schema::CAttribute *>>;
template class __declspec(dllexport) std::_Compressed_pair<std::_Wrap_alloc<std::allocator<gfc::schema::CAttribute *>>, std::_Vector_val<std::_Simple_types<gfc::schema::CAttribute *>>, true>;
template class __declspec(dllexport) std::vector<gfc::schema::CAttribute *, std::allocator<gfc::schema::CAttribute *>>;
template class __declspec(dllexport) std::_Vector_val<std::_Simple_types<gfc::schema::CClass *>>;
template class __declspec(dllexport) std::_Compressed_pair<std::_Wrap_alloc<std::allocator<gfc::schema::CClass *>>, std::_Vector_val<std::_Simple_types<gfc::schema::CClass *>>, true>;
template class __declspec(dllexport) std::vector<gfc::schema::CClass *, std::allocator<gfc::schema::CClass *>>;
template class __declspec(dllexport) std::_Tree_val<std::_Tree_simple_types<std::pair<const std::wstring, std::size_t>>>;
template class __declspec(dllexport) std::_Compressed_pair<std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<const std::wstring, std::size_t>, void *>>>, std::_Tree_val<std::_Tree_simple_types<std::pair<const std::wstring, std::size_t>>>, true>;
template class __declspec(dllexport) std::_Compressed_pair<std::less<std::wstring>, std::_Compressed_pair<std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<const std::wstring, std::size_t>, void *>>>, std::_Tree_val<std::_Tree_simple_types<std::pair<const std::wstring, std::size_t>>>, true>, true>;
template class __declspec(dllexport) std::map<std::wstring, std::size_t, std::less<std::wstring>, std::allocator<std::pair<const std::wstring, std::size_t>>>;

class GFCSCHEMA_API CClass : public CTypeObject
{
public:
    CClass();
    CClass(const std::wstring& sName);
    virtual ~CClass();
    virtual CTypeObjectEnum getType() const {return TOE_CLASS;}
    bool getIsAbstract() {return m_bIsAbstract;}
    void setIsAbstract(bool bIsAbstract) {m_bIsAbstract = bIsAbstract;}
    virtual CDataTypeEnum getDataType() const { return EDT_ENTITY; }
    //virtual bool getIsValueType() {return m_bIsValueType;}
    //void setIsValueType(bool bIsValueType) {m_bIsValueType = bIsValueType;}
    // 继承
    CClass* getParent() {return m_pParent;}
    void setParent(CClass* pClass) {m_pParent = pClass;}
    int getChildCount() {return (int)m_oChildList.size();}
    CClass* getChild(int nIndex);
    void addChild(CClass* pClass);
    bool isInherited(const std::wstring& sName);
    // 属性
    CAttribute *getAttribute(int nIndex);
    int getAttributeCount(){return (int)m_oAttributeList.size();}
    int getTotalAttributeCount(); // 含所有父的属性
    void addAttribute(CAttribute* pAttribute);
    CAttribute* findAttribute(const std::wstring& sName);
    int attributeIndexByName(const std::wstring& sName);

    bool getIsValid() { return m_bIsValid; }
    void setIsValid(bool bIsValid) { m_bIsValid = bIsValid; }
private:
    CClass* m_pParent;
    CClassList m_oChildList;
    CAttributeList m_oAttributeList;
    std::map<std::wstring, std::size_t> m_oAttributeMap;
    bool m_bIsAbstract;
    bool m_bIsValid;
    //bool m_bIsValueType;
};

GFC_NAMESPACE_END

#endif // CLASS_H
