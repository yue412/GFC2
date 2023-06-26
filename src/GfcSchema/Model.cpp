#include "GfcSchema/Model.h"
#include "GfcSchema/BuildinType.h"
#include "Common.h"
#include <assert.h>

GFC_NAMESPACE_BEGIN

CModel::CModel(): m_pRefModel(nullptr)
{
    addTypeObject(new CBooleanType);
    addTypeObject(new CIntegerType);
    addTypeObject(new CRealType);
    addTypeObject(new CStringType);
}

CModel::~CModel()
{
    clear();
}

CTypeObject *CModel::getTypeObject(int nIndex)
{
    assert(nIndex >= 0 && nIndex < (int)m_oTypeObjectList.size());
    return m_oTypeObjectList[nIndex];
}

void CModel::addTypeObject(CTypeObject *pTypeObject)
{
    assert(pTypeObject);
    m_oTypeObjectList.push_back(pTypeObject);
    m_oTypeIndex.insert(std::make_pair(UpperString(pTypeObject->getName()), pTypeObject));
}

CTypeObject *CModel::findTypeObject(const std::wstring &sTypeName)
{
    CTypeMap::iterator itr = m_oTypeIndex.find(UpperString(sTypeName));
    if (itr == m_oTypeIndex.end())
    {
        return NULL;
    }
    else
    {
        return itr->second;
    }
}

void CModel::clear()
{
    m_oTypeIndex.clear();
    for (CTypeObjectList::iterator itr = m_oTypeObjectList.begin(); itr != m_oTypeObjectList.end(); ++itr)
    {
        delete *itr;
    }
    m_oTypeObjectList.clear();
}

void CModel::getTypeObjectList(CTypeObjectList &oTypeList/*,QStringList files = QStringList()*/)
{
	for (auto oIter = m_oTypeObjectList.begin();oIter != m_oTypeObjectList.end();oIter++)
	{
		if (m_pRefModel == nullptr || m_pRefModel->findTypeObject((*oIter)->getName()) == nullptr)
		{
			oTypeList.push_back(*oIter);
		}
	}

}

GFC_NAMESPACE_END