#include "DiffTypeObject.h"
#include "TypeObject.h"
#include "EntityClass.h"
#include "EnumType.h"
#include "TypeDefine.h"
#include "EntityAttribute.h"
#include <algorithm>
#include <assert.h>

GFC_NAMESPACE_BEGIN

CDiffTypeObject::CDiffTypeObject(void)
{
}


CDiffTypeObject::CDiffTypeObject(EnDiffType pType, void * pLeft, void * pRight): m_oInfo(pType, pLeft, pRight)
{
}

CDiffTypeObject::~CDiffTypeObject(void)
{
}

std::wstring CDiffTypeObject::getName()
{
    return m_oInfo.left ? ((CTypeObject*)(m_oInfo.left))->getName() : 
        m_oInfo.right ? ((CTypeObject*)(m_oInfo.right))->getName() : L"";
}

CDiffInfo & CDiffTypeObject::getInfo()
{
    return m_oInfo;
}

int CDiffTypeObject::getCount()
{
    return (int)m_oList.size();
}

CDiffInfo * CDiffTypeObject::getAttributeDiffInfo(int nIndex)
{
    return m_oList[nIndex];
}

std::vector<CDiffInfo*>& CDiffTypeObject::leftAttributeDiffInfoList()
{
    return m_oLeft;
}

std::vector<CDiffInfo*>& CDiffTypeObject::rightAttributeDiffInfoList()
{
    return m_oRight;
}

void CDiffTypeObject::compare(CTypeObject * pLeft, CTypeObject * pRight)
{
    assert(pLeft); assert(pRight);
    m_oInfo.left = pLeft;
    m_oInfo.right = pRight;
    if (pLeft->getType() != pRight->getType())
    {
        m_oInfo.type = DT_DIFFTYPE;
        return;
    }
    switch (pLeft->getType())
    {
    case TOE_CLASS:
        compareClass((CClass*)pLeft, (CClass*)pRight);
        break;
    case TOE_ENUM:
        compareEnum((CEnumType*)pLeft, (CEnumType*)pRight);
        break;
    case TOE_TYPE:
        compareTypeDef((CTypeDef*)pLeft, (CTypeDef*)pRight);
        break;
    default:
        assert(false);
        break;
    }
}

void CDiffTypeObject::compareClass(CClass * pLeft, CClass * pRight)
{
    for (int i = 0; i < pLeft->getAttributeCount(); i++)
    {
        auto pLeftAttrib = pLeft->getAttribute(i);
        auto pRightAttrib = pRight->findAttribute(pLeftAttrib->getName());
        if (pRightAttrib)
        {
            //

        }
        else
        {
            auto pDiff = new CDiffInfo(DT_RIGHTMISS, pLeftAttrib, pRightAttrib);
            m_oLeft.push_back(pDiff);
            m_oList.push_back(pDiff);
            m_oInfo.type = DT_DIFFERENT;
        }
    }

    for (int i = 0; i < pRight->getAttributeCount(); i++)
    {
        auto pRightAttrib = pRight->getAttribute(i);
        auto itr = std::find_if(m_oLeft.begin(), m_oLeft.end(), 
            [pRightAttrib](CDiffInfo* pDiff) {return ((CAttribute*)pDiff->left)->getName() == pRightAttrib->getName(); });
        if (itr == m_oLeft.end())
        {
            auto pDiff = new CDiffInfo(DT_LEFTMISS, nullptr, pRightAttrib);
            m_oRight.push_back(pDiff);
            m_oList.push_back(pDiff);//最后释放oList
            m_oInfo.type = DT_DIFFERENT;
        }
        else
        {
            m_oRight.push_back(*itr);
        }
    }
}

void CDiffTypeObject::compareEnum(CEnumType * pLeft, CEnumType * pRight)
{
    // 如果枚举值有不同，也无法做到兼容
    if (pLeft->getEnumCount() != pRight->getEnumCount())
    {
        m_oInfo.type = DT_DIFFERENT;
        return;
    }
    for (int i = 0; i < pLeft->getEnumCount(); i++)
    {
        auto sEnum = pLeft->getEnum(i);
        if (!pRight->exists(sEnum))
        {
            m_oInfo.type = DT_DIFFERENT;
            return;
        }
    }
    m_oInfo.type = DT_EQUAL;
}

void CDiffTypeObject::compareTypeDef(CTypeDef * pLeft, CTypeDef * pRight)
{
    auto pLeftBaseType = pLeft->getBaseType();
    auto pRightBaseType = pRight->getBaseType();
    m_oInfo.type = pLeftBaseType->getType() != pRightBaseType->getType() || pLeftBaseType->getName() != pRightBaseType->getName() ? DT_DIFFERENT : DT_EQUAL;
}

GFC_NAMESPACE_END