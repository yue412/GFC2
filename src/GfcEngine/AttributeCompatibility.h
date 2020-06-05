#ifndef ATTRIBUTECOMPATIBILITY_H
#define ATTRIBUTECOMPATIBILITY_H

#include <string>
#include "GfcEngine\GfcEngine.h"

namespace gfc {
    namespace schema {
        class CAttribute;
        class CClass;
        class CEnumType;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CConverter;

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
    CAttributeCompatibility() : m_bIsCompatible(false), m_pConverter(nullptr), m_nToIndex(-1){};
    ~CAttributeCompatibility();
public:
    void init(gfc::schema::CAttribute* pFrom, gfc::schema::CAttribute* pTo, int nToIndex);
    std::wstring getName() { return m_sName; }
    bool isCompatible() { return m_bIsCompatible; }
    CConverter* converter() { return m_pConverter; }
    int toIndex() { return m_nToIndex; }
public:
    static TypeCompatibility noCompatibility(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
    static TypeCompatibility buildinCompatibility(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
    static TypeCompatibility buildinToEnumCompatibility(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
    static TypeCompatibility enumToBuildinCompatibility(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
    static TypeCompatibility enumCompatibility(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
    static TypeCompatibility classCompatibility(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);

    static bool isClassCompatibility(gfc::schema::CClass* pFrom, gfc::schema::CClass* pTo);
    static bool isEnumCompatibility(gfc::schema::CEnumType* pFrom, gfc::schema::CEnumType* pTo);
    static bool isEnumSame(gfc::schema::CEnumType* pFrom, gfc::schema::CEnumType* pTo);
    static int getTypeIndex(gfc::schema::CTypeObject* pType);
    static TypeCompatibility getTypeCompatibility(gfc::schema::CTypeObject* pFrom, gfc::schema::CTypeObject* pTo);
    static TypeCompatibility getMultiCompatibility(gfc::schema::CAttribute* pFrom, gfc::schema::CAttribute* pTo);
private:
    static int getMultiIndex(gfc::schema::CAttribute* pAttrib);


    std::wstring m_sName;
    bool m_bIsCompatible;
    CConverter* m_pConverter;
    int m_nToIndex;
};

GFCENGINE_NAMESPACE_END

#endif
