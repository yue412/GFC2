#include "DiffModel.h"
#include "DiffTypeObject.h"
#include "Model.h"
#include <assert.h>

GFC_NAMESPACE_BEGIN

CDiffModel::CDiffModel(void)
{
}


CDiffModel::~CDiffModel(void)
{
}

void CDiffModel::compare(CModel * pLeft, CModel * pRight)
{
    assert(pLeft); assert(pRight);
    for (int i = 0; i < pLeft->getTypeObjectCount(); i++)
    {
        auto pLeftType = pLeft->getTypeObject(i);
        if (pLeftType->getType() == TOE_UNDEFINE || pLeftType->getType() == TOE_BUILDIN)
            continue;
        auto pRightType = pRight->findTypeObject(pLeftType->getName());
        if (pRightType)
        {
            // compare
            auto pObject = new CDiffTypeObject;
            pObject->compare(pLeftType, pRightType);
            add(pObject);
        }
        else
        {
            add(new CDiffTypeObject(DT_RIGHTMISS, pLeftType, nullptr));
        }
    }

    for (int i = 0; i < pRight->getTypeObjectCount(); i++)
    {
        auto pRightType = pRight->getTypeObject(i);
        if (pRightType->getType() == TOE_UNDEFINE || pRightType->getType() == TOE_BUILDIN)
            continue;
        auto pDiffType = find(pRightType->getName());
        if (pDiffType == nullptr)
        {
            add(new CDiffTypeObject(DT_LEFTMISS, nullptr, pRightType));
        }
    }

}

CDiffTypeObject * CDiffModel::find(const std::wstring & sName)
{
    auto itr = m_oDiffIndex.find(sName);
    return itr == m_oDiffIndex.end() ? nullptr : itr->second;
}

CDiffTypeObject * CDiffModel::getItems(int nIndex)
{
    return m_oDiffList[nIndex];
}

int CDiffModel::getCount()
{
    return (int)m_oDiffList.size();
}

void CDiffModel::add(CDiffTypeObject * pObject)
{
    m_oDiffList.push_back(pObject);
    m_oDiffIndex.insert(std::make_pair(pObject->getName(), pObject));
}

GFC_NAMESPACE_END