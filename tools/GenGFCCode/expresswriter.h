#ifndef EXPRESSWRITER_H
#define EXPRESSWRITER_H

#include <string>
#include <fstream>

class CModel;
class CTypeDef;
class CClass;
class CEnumType;
class CBuildinType;

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
