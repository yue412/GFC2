#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <map>
#include "GfcSchema\TypeObject.h"

GFC_NAMESPACE_BEGIN

typedef std::vector<CTypeObject*> CTypeObjectList;

class CModel
{
public:
    CModel();
    ~CModel();
    CTypeObject *getTypeObject(int nIndex);
    int getTypeObjectCount(){return (int)m_oTypeObjectList.size();}
    void addTypeObject(CTypeObject* pTypeObject);
    CTypeObject *findTypeObject(const std::wstring& sTypeName);
    CModel* getRefModel() { return m_pRefModel; }
    void setRefModel(CModel* pRefModel) { m_pRefModel = pRefModel; }
    void clear();
    std::wstring version() { return m_sVersion; }
    void setVersion(const std::wstring& sVersion) { m_sVersion = sVersion; }

	// 扩展接口，只生成指定的gfc文件，xuxp,2017-6-19
    void getTypeObjectList(CTypeObjectList& oTypeList/*,QStringList files = QStringList()*/);
private:
    CTypeObjectList m_oTypeObjectList;
    typedef std::map<std::wstring, CTypeObject*> CTypeMap;
    CTypeMap m_oTypeIndex;
    CModel* m_pRefModel;
    std::wstring m_sVersion;
};

GFC_NAMESPACE_END

#endif // MODEL_H
