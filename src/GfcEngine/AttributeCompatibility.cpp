#include "GfcEngine/AttributeCompatibility.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/TypeObject.h"
#include "GfcSchema/EnumType.h"
#include "GfcSchema/EntityClass.h"
#include "ConverterImp.h"
#include <algorithm>

GFCENGINE_NAMESPACE_BEGIN

TypeCompatibility g_BuildinCompatibilityTable[4][4] = {
    { { true, new CIntConverter },       { true, new CIntConverter }, { true, new CIntConverter }, { true, new CBoolToStringConverter } },
    { { true, new CIntConverter },  { true, new CIntConverter },      { true, new CIntConverter },      { true, new CIntToStringConverter } },
    { { false, new CEmptyConverter },     { false, new CEmptyConverter },    { true, new CFloatConverter },      { true, new CFloatToStringConverter } },
    { { false, new CEmptyConverter },     { false, new CEmptyConverter },    { false, new CEmptyConverter },    { true, new CStringConverter } }
};

TypeCompatibility g_EnumToBuildinTable[4] = { { true, new CIntConverter },{ true, new CIntConverter },{ true, new CIntConverter },{ true, new CIntToStringConverter } };
TypeCompatibility g_BuildinToEnumTable[4] = { { true, new CIntToEnumConverter },{ true, new CIntToEnumConverter },{ false, new CEmptyConverter },{ false, new CEmptyConverter } };

std::vector<std::wstring> g_TypeNames = {L"BOOLEAN", L"INTEGER", L"REAL", L"STRING"};

typedef TypeCompatibility (*TypeCompatibilityFunc)(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo);

TypeCompatibilityFunc g_TypeCompatibilityFuncTable[][gfc::schema::TOE_CLASS + 1] = {
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility},
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::buildinCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::buildinToEnumCompatibility , &CAttributeCompatibility::noCompatibility },
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility },
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::enumToBuildinCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::enumCompatibility , &CAttributeCompatibility::noCompatibility },
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::classCompatibility }
};

// Repeated
// Optional
// Required
TypeCompatibility g_MultiCompatibilityTable[3][3] = {
    { { true, new CArrayToArrayConverter },{ true, new CArrayToOneConverter },{ false, new CArrayToOneConverter } },
    { { true, new COneToArrayConverter },{ true, new COptionalConverter },{ false, new COptionalConverter } },
    { { true, new COneToArrayConverter },{ true, new COptionalConverter },{ true, new COptionalConverter } }
};


CAttributeCompatibility::~CAttributeCompatibility()
{
    delete m_pConverter;
}

void CAttributeCompatibility::init(gfc::schema::CAttribute * pFrom, gfc::schema::CAttribute * pTo, int nToIndex)
{
    m_pFrom = pFrom;
    m_pTo = pTo;
    m_nToIndex = nToIndex;
    delete m_pConverter;
    m_pConverter = nullptr;
    if (pFrom)
    {
        m_sName = pFrom->getName();
        if (pTo)
        {
            // 存在
            auto pFromBaseType = pFrom->getType()->getBaseType();
            auto pToBaseType = pTo->getType()->getBaseType();
            auto oCompatibility = getTypeCompatibility(pFromBaseType, pToBaseType);
            auto oMultiCompatibility = getMultiCompatibility(pFrom, pTo);
            m_bIsCompatible = oCompatibility.isCompatibility && oMultiCompatibility.isCompatibility;
            oMultiCompatibility.converter->setNext(oCompatibility.converter);
            m_pConverter = oMultiCompatibility.converter;
            m_pConverter->init(pFromBaseType, pToBaseType);
        }
        else
        {
            // 丢弃即可
            m_bIsCompatible = true;
        }
    }
    else
    {
        m_sName = pTo->getName();
        // 不存在，判断是否可选或为数组类型
        m_bIsCompatible = pTo->getOptionalFlag() || pTo->getRepeatFlag();
    }
}

TypeCompatibility CAttributeCompatibility::enumCompatibility(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    TypeCompatibility oResult;
    if (pFrom->getName() != pTo->getName() || !isEnumCompatibility((gfc::schema::CEnumType*)pFrom, (gfc::schema::CEnumType*)pTo))
    {
        //需要比较一下枚举值是否相同
        oResult.isCompatibility = false;
        oResult.converter = new CEnumConverter;
    }
    else 
    {
        oResult.isCompatibility = true;
        // 枚举顺序都是一致的
        if (isEnumSame((gfc::schema::CEnumType*)pFrom, (gfc::schema::CEnumType*)pTo))
            oResult.converter = new CIntToEnumConverter;
        else
            oResult.converter = new CEnumConverter;
    }
    return oResult;
}

TypeCompatibility CAttributeCompatibility::classCompatibility(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    TypeCompatibility oResult;
    if (isClassCompatibility((gfc::schema::CClass*)pFrom, (gfc::schema::CClass*)pTo))
    {
        oResult.isCompatibility = true;
        oResult.converter = new CEntityRefConverter;
    }
    else
    {
        oResult.isCompatibility = false;
        oResult.converter = new CEmptyConverter;
    }
    return oResult;
}

TypeCompatibility CAttributeCompatibility::getTypeCompatibility(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    auto oResult = (*g_TypeCompatibilityFuncTable[pFrom->getType()][pTo->getType()])(pFrom, pTo);
    oResult.converter = oResult.converter->clone();
    oResult.converter->init(pFrom, pTo);
    return oResult;
}

TypeCompatibility CAttributeCompatibility::getMultiCompatibility(gfc::schema::CAttribute * pFrom, gfc::schema::CAttribute * pTo)
{
    auto nFromIndex = getMultiIndex(pFrom);
    auto nToIndex = getMultiIndex(pTo);
    auto oResult = g_MultiCompatibilityTable[nFromIndex][nToIndex];
    oResult.converter = oResult.converter->clone();
    return oResult;
}

int CAttributeCompatibility::getMultiIndex(gfc::schema::CAttribute * pAttrib)
{
    if (pAttrib->getRepeatFlag())
        return 0;
    else if (pAttrib->getOptionalFlag())
        return 1;
    else
        return 2;
}

int CAttributeCompatibility::getTypeIndex(gfc::schema::CTypeObject * pType)
{
    auto itr = std::find(g_TypeNames.begin(), g_TypeNames.end(), pType->getName());
    return itr == g_TypeNames.end() ? -1 : itr - g_TypeNames.begin();
}

bool CAttributeCompatibility::isEnumCompatibility(gfc::schema::CEnumType * pFrom, gfc::schema::CEnumType * pTo)
{
    for (int i = 0; i < pFrom->getEnumCount(); i++)
    {
        if (!pTo->exists(pFrom->getEnum(i)))
        {
            return false;
        }
    }
    return true;
}

bool CAttributeCompatibility::isEnumSame(gfc::schema::CEnumType * pFrom, gfc::schema::CEnumType * pTo)
{
    for (int i = 0; i < pFrom->getEnumCount() && i < pTo->getEnumCount(); i++)
    {
        if (pFrom->getEnum(i) != pTo->getEnum(i))
        {
            return false;
        }
    }
    return true;
}

bool CAttributeCompatibility::isClassCompatibility(gfc::schema::CClass * pFrom, gfc::schema::CClass * pTo)
{
    auto pParent = pFrom;
    do
    {
        if (pParent->getName() == pTo->getName())
        {
            return true;
        }
        pParent = pParent->getParent();
    }
    while (pParent);
        
    return false;
}

void CAttributeCompatibility::setConverter(CConverter * pConverter)
{
    if (pConverter != m_pConverter)
    {
        delete m_pConverter;
        m_pConverter = pConverter;
    }
}

TypeCompatibility CAttributeCompatibility::noCompatibility(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    return TypeCompatibility(false, new CEmptyConverter);
}

TypeCompatibility CAttributeCompatibility::buildinCompatibility(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    auto nRow = getTypeIndex(pFrom);
    auto nCol = getTypeIndex(pTo);
    return g_BuildinCompatibilityTable[nRow][nCol];
}

TypeCompatibility CAttributeCompatibility::buildinToEnumCompatibility(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    auto nIndex = getTypeIndex(pFrom);
    return g_BuildinToEnumTable[nIndex];
}

TypeCompatibility CAttributeCompatibility::enumToBuildinCompatibility(gfc::schema::CTypeObject * pFrom, gfc::schema::CTypeObject * pTo)
{
    auto nIndex = getTypeIndex(pTo);
    return g_EnumToBuildinTable[nIndex];
}

GFCENGINE_NAMESPACE_END

