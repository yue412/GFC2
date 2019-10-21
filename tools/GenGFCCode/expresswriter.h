#ifndef EXPRESSWRITER_H
#define EXPRESSWRITER_H

#include <string>
#include <fstream>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN
class CModel;
class CTypeDef;
class CClass;
class CEnumType;
class CBuildinType;
GFC_NAMESPACE_END

using namespace gfc2::schema;

class CExpressWriter
{
public:
    CExpressWriter(CModel* pModel);
    void write(const std::wstring& sFileName, const std::wstring& sSchemaName);
private:
    void writeTypedef(CTypeDef* pTypeDef, std::wfstream& out);
    void writeClass(CClass* pClass, std::wfstream& out);
    void writeEnum(CEnumType* pEnumType, std::wfstream& out);
private:
    CModel* m_pModel;
};

#endif // EXPRESSWRITER_H
