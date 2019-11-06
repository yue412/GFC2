#ifndef ATTRIBUTECOMPATIBILITY_H
#define ATTRIBUTECOMPATIBILITY_H

#include <string>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN

class CAttribute;
class CConverter;
class CClass;
class CEnumType;
class CTypeObject;

struct TypeCompatibility
{
    TypeCompatibility() : isCompatibility(false), converter(nullptr) {}
    TypeCompatibility(bool bIsCompatibility, CConverter* pConverter): isCompatibility(bIsCompatibility), converter(pConverter) {}
    bool isCompatibility;
    CConverter* converter;
};

class CAttributeCompatibility
{
public:
    CAttributeCompatibility() : m_bIsCompatible(false), m_pConverter(nullptr){};
    ~CAttributeCompatibility();
public:
    void init(CAttribute* pFrom, CAttribute* pTo);
    std::wstring getName() { return m_sName; }
    bool isCompatible() { return m_bIsCompatible; }
    CConverter* converter() { return m_pConverter; }
public:
    static TypeCompatibility noCompatibility(CTypeObject* pFrom, CTypeObject* pTo);
    static TypeCompatibility buildinCompatibility(CTypeObject* pFrom, CTypeObject* pTo);
    static TypeCompatibility buildinToEnumCompatibility(CTypeObject* pFrom, CTypeObject* pTo);
    static TypeCompatibility enumToBuildinCompatibility(CTypeObject* pFrom, CTypeObject* pTo);
    static TypeCompatibility enumCompatibility(CTypeObject* pFrom, CTypeObject* pTo);
    static TypeCompatibility classCompatibility(CTypeObject* pFrom, CTypeObject* pTo);

    static bool isClassCompatibility(CClass* pFrom, CClass* pTo);
    static bool isEnumCompatibility(CEnumType* pFrom, CEnumType* pTo);
    static int getTypeIndex(CTypeObject* pType);
private:
    TypeCompatibility getTypeCompatibility(CTypeObject* pFrom, CTypeObject* pTo);
    TypeCompatibility getMultiCompatibility(CAttribute* pFrom, CAttribute* pTo);
    int getMultiIndex(CAttribute* pAttrib);


    std::wstring m_sName;
    bool m_bIsCompatible;
    CConverter* m_pConverter;
};

GFC_NAMESPACE_END

#endif
