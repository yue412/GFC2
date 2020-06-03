#ifndef CDOCUMENTWRITER_H
#define CDOCUMENTWRITER_H

#include <string>
#include <fstream>
#include <vector>
#include "SchemaMacro.h"

GFC_NAMESPACE_BEGIN
class CModel;
class CClass;
class CTypeDef;
class CEnumType;
class CTypeObject;
GFC_NAMESPACE_END

using namespace gfc::schema;

class CDocumentWriter
{
public:
    CDocumentWriter(CModel* pModel);
    ~CDocumentWriter();
public:
    void write(const std::wstring& sPath);
private:
    void writeTypedef(CTypeDef* pTypeDef, std::fstream& out);
    void writeClass(CClass* pClass, std::fstream& out);
    void writeEnum(CEnumType* pEnumType, std::fstream& out);
    void writeHead(CTypeObject* pType, std::fstream& out);
    void writeTail(std::fstream& out);
    void writeData(const std::vector<std::wstring>& oList, std::fstream& out);
private:
    CModel* m_pModel;
};

#endif // !CDOCUMENTWRITER_H

