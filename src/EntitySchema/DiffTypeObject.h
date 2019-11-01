#ifndef DIFFTYPEOBJECT_H
#define DIFFTYPEOBJECT_H

#include <vector>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN

class CTypeObject;
class CClass;
class CTypeDef;
class CEnumType;

enum EnDiffType
{
    DT_LEFTMISS,
    DT_RIGHTMISS,
    DT_DIFFTYPE,
    DT_DIFFERENT,
    DT_EQUAL
};

struct CDiffInfo
{
    CDiffInfo(): type(DT_EQUAL), left(nullptr), right(nullptr) {}
    CDiffInfo(EnDiffType pType, void* pLeft, void* pRight): type(pType), left(pLeft), right(pRight) {}
    EnDiffType type;
    void* left;
    void* right;
};

class CDiffTypeObject
{
public:
    CDiffTypeObject(void);
    CDiffTypeObject(EnDiffType pType, void* pLeft, void* pRight);
    virtual ~CDiffTypeObject(void);
public:
    std::wstring getName();
    CDiffInfo& getInfo();
    int getCount();
    CDiffInfo* getAttributeDiffInfo(int nIndex);
    std::vector<CDiffInfo*>& leftAttributeDiffInfoList();
    std::vector<CDiffInfo*>& rightAttributeDiffInfoList();
    void compare(CTypeObject * pLeft, CTypeObject * pRight);
private:
    void compareClass(CClass* pLeft, CClass* pRight);
    void compareEnum(CEnumType* pLeft,  CEnumType* pRight);
    void compareTypeDef(CTypeDef* pLeft, CTypeDef* pRight);

    CDiffInfo m_oInfo;
    std::vector<CDiffInfo*> m_oList; // all
    std::vector<CDiffInfo*> m_oLeft;
    std::vector<CDiffInfo*> m_oRight;
};

GFC_NAMESPACE_END

#endif
