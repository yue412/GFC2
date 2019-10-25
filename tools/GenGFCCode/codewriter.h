#ifndef CODEWRITER_H
#define CODEWRITER_H

#include <string>
#include <vector>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN
class CModel;
class CTypeObject;
class CBuildinType;
class CTypeDef;
class CEnumType;
class CClass;
class CAttribute;
GFC_NAMESPACE_END

enum EnBaseType {
    EBT_ENTITY,
    EBT_ENUM,
    EBT_STRING,
    EBT_INT,
    EBT_DOUBLE,
    EBT_BOOL
};

class CppBaseFile;
class CppClass;
class CppCode;

using namespace gfc2::schema;

class CCodeWriter
{
public:
    CCodeWriter(CModel* pModel);
    ~CCodeWriter();
	// 扩展接口，只生成指定的gfc文件,xuxp,2017-6-19
    void write(const std::wstring& sPathName, const std::wstring &sCPPPath, const std::wstring &sTextPath, const std::wstring &sBinPath, 
        const std::wstring& sNETPath);
//signals:
//    void reset();
//    void setRange(int minimum, int maximum);
//    void setValue(int value);
private:
    //void writeSchema(CClass* pClass, int nTypeId, std::wstring& sSchema, int& nSize);
    void updateProgressBar();
    int getClassCount();
    void writeFieldCacheHeadFile();
    void writeFieldCacheImpFile();
//    void writeRegSchemaInfoHeadFile();
//    void writeRegSchemaInfoImpFile();
    void writeTypedefFile(std::vector<CTypeObject*>& oObjectList);
    void writeCliTypedefFile(std::vector<CTypeObject*>& oObjectList);
    void writeClassFile(std::vector<CTypeObject*>& oObjectList);
    void writeClassHeadFile(CClass* pTypeObject, CppClass* pClass, CppClass* pFactoryClass, CppClass* pFieldCacheClass);
    void writeClassImpFile(CppClass* pClass, CppClass* pFactoryClass, CppClass* pFieldCacheClass);
    void writeCliClassHeadFile(CClass* pTypeObject, CppClass* pClass);
    void writeCliClassImpFile(CppClass* pClass);
    void writeBinarySerializerClassFile(CClass* pTypeObject, CppClass* pClass, CppClass* pFieldCacheClass);
    void writeTextSerializerClassFile(CClass* pTypeObject, CppClass* pClass);

    void addConstructor(CClass *pTypeObject, CppClass* pClass);
    void addCliConstructor1(CClass *pTypeObject, CppClass* pClass);
    void addCliConstructor2(CClass *pTypeObject, CppClass* pClass);
    void addByteSizeFunc(CClass *pTypeObject, CppClass* pClass);
    void addIsInitializedFunc(CClass *pTypeObject, CppClass* pClass);
    void addEntityNameFunc(CClass *pTypeObject, CppClass* pClass);
    void addSerializeWithCachedSizesFunc(CClass *pTypeObject, CppClass* pClass);
    void addSerializeWithCachedSizesToArrayFunc(CClass *pTypeObject, CppClass* pClass);
    void addParseField1(CClass *pTypeObject, CppClass* pClass);
    void addSerializeFunc(CClass *pTypeObject, CppClass* pClass);
    void addParseField2(CClass *pTypeObject, CppClass* pClass);
    void addTypeIdFunc(CppClass* pClass, int nTypeId);
    void addCreateSchemaFunc(CClass *pTypeObject, CppClass* pClass, int nTypeId);

    //void writeClass(CClass* pTypeObject, int nTypeId);
    CppClass* createCppClass(CClass* pTypeObject, int nTypeId);
    CppClass* createCppCliClass(CClass* pTypeObject, int nTypeId);
    CppClass* createFactoryClass(CClass* pTypeObject);
    CppClass* createFieldCacheClass(CClass* pTypeObject);
    CppClass* createTextSerializerClass(CClass* pTypeObject);
    CppClass* createBinarySerializerClass(CClass* pTypeObject);
    //void writeClassHead(CClass* pTypeObject);
    //void writeClassImp(CClass* pTypeObject, int nTypeId);

    std::wstring getTypeCode(CTypeObject* pTypeObject, bool b4cli = false);
    std::wstring getStoreTypeCode(CTypeObject* pTypeObject, bool bIsRef, bool b4cli = false);
    std::wstring getBaseTypeCode(CTypeObject* pTypeObject, bool b4cli = false);
    EnBaseType getBaseType(CTypeObject* pTypeObject);
    std::wstring getBaseTypePrefix(EnBaseType nType, bool bIsRefType);
    std::wstring getTypeDefaultValue(EnBaseType nType, const std::wstring& sTypeName, bool bIsRef);
    int getAttributeIndex(CClass* pTypeObject, int nIndex);
    int getMaxAttributeCount(CClass* pTypeObject);
//    void getRepeatAttributeCode(CAttribute* pAttribute, std::wstring& sPublic, std::wstring& sMember);
//    void getAttributeCode(CClass* pTypeObject, int nAttributeIndex,
//                          std::wstring& sPublic, std::wstring& sPrivate, std::wstring& sMember);
    void initRepeatAttributeCode(CAttribute* pAttribute, CppClass* pClass);
    void initCliRepeatAttributeCode(CClass* pTypeObject, CAttribute* pAttribute, CppClass* pClass);
    void initAttributeCode(CClass* pTypeObject, int nAttributeIndex, CppClass* pClass);
    void initCliAttributeCode(CClass* pTypeObject, int nAttributeIndex, CppClass* pClass);
    std::wstring getClassFieldCode(CAttribute* pAttrib);
    std::wstring getSizeCode(CAttribute* pAttribute);
    std::wstring getTypeWriteCode(EnBaseType nType, bool bIsRepeat, bool bIsRef);
    std::wstring getTypeWriteCodeNoTag(EnBaseType nType, bool bIsRepeat, bool bIsRef);
    std::wstring getTypeWriteTextCode(EnBaseType nType, const std::wstring& sAttributeName, const std::wstring& sAttributeType, bool bIsRepeat);
    std::wstring getTagTypeCode(EnBaseType nType, bool bIsRef);
    std::wstring getTypeReadCode(EnBaseType nType, bool bIsRef);
    std::wstring getTypeTextReadCode(EnBaseType nType, const std::wstring& sAttributeType);
    std::wstring getTypeWriteToArrayCode(EnBaseType nType, bool bIsRepeat, bool bIsRef);
    std::wstring getTypeWriteToArrayCodeNoTag(EnBaseType nType, bool bIsRepeat, bool bIsRef);
    std::wstring getParentClassCode(CClass* pClass, bool b4cli = false);
    bool hasConstructor(CClass* pTypeObject);
    void getRequireFlag(CClass* pClass, int& nCount, int& nFlag, std::vector<int> &oFlagList);
    void getRequireFlag(CClass* pClass, std::vector<int>& oFlagList);

    std::wstring m_sPath;
    std::wstring m_sCPPPath;
    std::wstring m_sTextPath;
    std::wstring m_sBinPath;
    std::wstring m_sNETPath;
    bool m_bOutputHead;
    bool m_bOutputCpp;
    bool m_bOutputNet;
    CModel* m_pModel;
    int m_nCount;
};

#endif // CODEWRITER_H
