#include "GfcEngine\ModelCompatibility.h"
#include "GfcEngine\ClassCompatibility.h"
#include "GfcSchema\Model.h"
#include "GfcSchema\EntityClass.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

CModelCompatibility::CModelCompatibility(void)
{
}


CModelCompatibility::~CModelCompatibility(void)
{
    clear();
}

void CModelCompatibility::init(gfc::schema::CModel * pFrom, gfc::schema::CModel * pTo)
{
    // 判断两个模型的兼容性
    assert(pFrom); assert(pTo);
    for (int i = 0; i < pFrom->getTypeObjectCount(); i++)
    {
        auto pFromType = pFrom->getTypeObject(i);
        auto pFromBaseType = pFromType->getBaseType();
        if (pFromBaseType->getType() == gfc::schema::TOE_CLASS)
        {
            auto pToType = pTo->findTypeObject(pFromBaseType->getName());
            if (pToType && pToType->getBaseType()->getType() == gfc::schema::TOE_CLASS)
            {
                // 必须是同名的类
                auto pCompatibility = new CClassCompatibility;
                pCompatibility->init(pFromType, pToType);
                add(pCompatibility);
            }// 其他各种情形，都视为未找到匹配的类，可以兼容（取决与别的类是否有引用）
        }
    }
}

CClassCompatibility * CModelCompatibility::find(const std::wstring & sName)
{
    auto itr = m_oClassIndex.find(sName);
    return itr == m_oClassIndex.end() ? nullptr : itr->second;
}

CClassCompatibility * CModelCompatibility::getItems(int nIndex)
{
    return m_oClassList[nIndex];
}

int CModelCompatibility::getCount()
{
    return (int)m_oClassList.size();
}

void CModelCompatibility::add(CClassCompatibility * pObject)
{
    m_oClassList.push_back(pObject);
    m_oClassIndex.insert(std::make_pair(pObject->getName(), pObject));
}

void CModelCompatibility::clear()
{
    for each (auto pClass in m_oClassList)
    {
        delete pClass;
    }
    m_oClassList.clear();
    m_oClassIndex.clear();
}

GFCENGINE_NAMESPACE_END