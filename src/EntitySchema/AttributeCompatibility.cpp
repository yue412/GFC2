#include "AttributeCompatibility.h"
#include "EntityAttribute.h"
#include "TypeObject.h"
#include "Converter.h"
#include "EnumType.h"
#include "EntityClass.h"


GFC_NAMESPACE_BEGIN

TypeCompatibility g_BuildinCompatibilityTable[4][4] = {
    { { true, new CCopyConverter },       { true, new CBoolToIntConverter }, { true, new CBoolToIntConverter }, { true, new CBoolToStringConverter } },
    { { true, new CIntToBoolConverter },  { true, new CCopyConverter },      { true, new CCopyConverter },      { true, new CStringConverter } },
    { { false, new CEmptyConverter },     { false, new CEmptyConverter },    { true, new CCopyConverter },      { true, new CStringConverter } },
    { { false, new CEmptyConverter },     { false, new CEmptyConverter },    { false, new CEmptyConverter },    { true, new CCopyConverter } },
};

TypeCompatibility g_EnumToBuildinTable[4] = { { true, new CEnumToBoolConverter },{ true, new CEnumToIntConverter },{ true, new CEnumToIntConverter },{ true, new CEnumToStringConverter } };
TypeCompatibility g_BuildinToEnumTable[4] = { { true, new CBoolToEnumConverter },{ true, new CIntToEnumConverter },{ false, new CEmptyConverter },{ false, new CEmptyConverter } };

std::vector<std::wstring> g_TypeNames = {L"BOOLEAN", L"INTEGER", L"REAL", L"STRING"};

typedef TypeCompatibility (*TypeCompatibilityFunc)(CTypeObject * pFrom, CTypeObject * pTo);

TypeCompatibilityFunc g_TypeCompatibilityFuncTable[][TOE_CLASS + 1] = {
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility},
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::buildinCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::buildinToEnumCompatibility , &CAttributeCompatibility::noCompatibility },
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility },
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::enumToBuildinCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::enumCompatibility , &CAttributeCompatibility::noCompatibility },
    { &CAttributeCompatibility::noCompatibility, &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::noCompatibility , &CAttributeCompatibility::classCompatibility },
};

// Repeated
// Optional
// Required
TypeCompatibility g_MultiCompatibilityTable[3][3] = {
    { { true, new CArrayToArrayConverter },{ true, new CArrayToOneConverter },{ false, new CArrayToOneConverter } },
    { { true, new COneToArrayConverter },{ true, new COptionalConverter },{ false, new COptionalConverter } },
    { { true, new COneToArrayConverter },{ true, new CCopyConverter },{ true, new CCopyConverter } }
};


CAttributeCompatibility::~CAttributeCompatibility()
{
    delete m_pConverter;
}

void CAttributeCompatibility::init(CAttribute * pFrom, CAttribute * pTo, int nToIndex)
{
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

TypeCompatibility CAttributeCompatibility::enumCompatibility(CTypeObject * pFrom, CTypeObject * pTo)
{
    TypeCompatibility oResult;
    if (pFrom->getName() != pTo->getName() || !isEnumCompatibility((CEnumType*)pFrom, (CEnumType*)pTo))
    {
        //需要比较一下枚举值是否相同
        oResult.isCompatibility = false;
        oResult.converter = new CEnumConverter;
    }
    else
    {
        oResult.isCompatibility = true;
        oResult.converter = new CCopyConverter;
    }
    return oResult;
}

TypeCompatibility CAttributeCompatibility::classCompatibility(CTypeObject * pFrom, CTypeObject * pTo)
{
    TypeCompatibility oResult;
    if (isClassCompatibility((CClass*)pFrom, (CClass*)pTo))
    {
        oResult.isCompatibility = true;
        oResult.converter = new CCopyConverter;
    }
    else
    {
        oResult.isCompatibility = false;
        oResult.converter = new CEmptyConverter;
    }
    return oResult;
}

TypeCompatibility CAttributeCompatibility::getTypeCompatibility(CTypeObject * pFrom, CTypeObject * pTo)
{
    auto oResult = (*g_TypeCompatibilityFuncTable[pFrom->getType()][pTo->getType()])(pFrom, pTo);
    oResult.converter = oResult.converter->clone();
    oResult.converter->init(pFrom, pTo);
    return oResult;
}

TypeCompatibility CAttributeCompatibility::getMultiCompatibility(CAttribute * pFrom, CAttribute * pTo)
{
    auto nFromIndex = getMultiIndex(pFrom);
    auto nToIndex = getMultiIndex(pTo);
    auto oResult = g_MultiCompatibilityTable[nFromIndex][nToIndex];
    oResult.converter = oResult.converter->clone();
    return oResult;
}

int CAttributeCompatibility::getMultiIndex(CAttribute * pAttrib)
{
    if (pAttrib->getRepeatFlag())
        return 0;
    else if (pAttrib->getOptionalFlag())
        return 1;
    else
        return 2;
}

int CAttributeCompatibility::getTypeIndex(CTypeObject * pType)
{
    auto itr = std::find(g_TypeNames.begin(), g_TypeNames.end(), pType->getName());
    return itr == g_TypeNames.end() ? -1 : itr - g_TypeNames.begin();
}

bool CAttributeCompatibility::isEnumCompatibility(CEnumType * pFrom, CEnumType * pTo)
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

bool CAttributeCompatibility::isClassCompatibility(CClass * pFrom, CClass * pTo)
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

TypeCompatibility CAttributeCompatibility::noCompatibility(CTypeObject * pFrom, CTypeObject * pTo)
{
    return TypeCompatibility(false, new CEmptyConverter);
}

TypeCompatibility CAttributeCompatibility::buildinCompatibility(CTypeObject * pFrom, CTypeObject * pTo)
{
    auto nRow = getTypeIndex(pFrom);
    auto nCol = getTypeIndex(pTo);
    return g_BuildinCompatibilityTable[nRow][nCol];
}

TypeCompatibility CAttributeCompatibility::buildinToEnumCompatibility(CTypeObject * pFrom, CTypeObject * pTo)
{
    auto nIndex = getTypeIndex(pFrom);
    return g_BuildinToEnumTable[nIndex];
}

TypeCompatibility CAttributeCompatibility::enumToBuildinCompatibility(CTypeObject * pFrom, CTypeObject * pTo)
{
    auto nIndex = getTypeIndex(pTo);
    return g_EnumToBuildinTable[nIndex];
}

GFC_NAMESPACE_END

