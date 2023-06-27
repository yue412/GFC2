#include <iostream>
#include "common.h"
#include <algorithm>
#include "expresswriter.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/TypeDefine.h"
#include "GfcSchema/EnumType.h"
#include "GfcSchema/Model.h"
#include "GfcSchema/EntityAttribute.h"
#include <assert.h>

CExpressWriter::CExpressWriter(CModel *pModel): m_pModel(pModel)
{
}

void CExpressWriter::write(const std::wstring &sFileName, const std::wstring &sSchemaName)
{
    assert(m_pModel);
    if (sFileName.empty())
    {
        assert(false);
        return;
    }

    std::wfstream oFile;
#if (defined _WIN32 || defined _WIN64)
    auto sFile = sFileName;
#else
    auto sFile = UnicodeToUtf8(sFileName);
#endif
    oFile.open(sFile, std::ios::out);
    if (!oFile.good())
    {
        std::wcout << "文件打开失败!" << std::endl;
        return;
    }

    oFile << L"SCHEMA " << sSchemaName << L";\n\n";

    int nCount = m_pModel->getTypeObjectCount();
    // 排序
    std::vector<CTypeObject*> oTempList;
    m_pModel->getTypeObjectList(oTempList);
    std::sort(oTempList.begin(), oTempList.end(), lessTypeObject);
    //
    for (int i = 0; i < nCount; ++i)
    {
        CTypeObject* pTypeObject = oTempList[i];//m_pModel->getTypeObject(i);
        CClass* pClass = dynamic_cast<CClass*>(pTypeObject);
        if (pClass)
        {
            writeClass(pClass, oFile);
            oFile << L"\n";
            continue;
        }
        CTypeDef* pTypeDef = dynamic_cast<CTypeDef*>(pTypeObject);
        if (pTypeDef)
        {
            writeTypedef(pTypeDef, oFile);
            oFile << L"\n";
            continue;
        }
        CEnumType* pEnumType = dynamic_cast<CEnumType*>(pTypeObject);
        if (pEnumType)
        {
            writeEnum(pEnumType, oFile);
            oFile << L"\n";
            continue;
        }
    }

    oFile << L"END_SCHEMA;\n";

    oFile.close();
}

void CExpressWriter::writeTypedef(CTypeDef *pTypeDef, std::wfstream& out)
{
    out << FormatWstring(L"TYPE %ls = %ls;\n", 
        pTypeDef->getName().c_str(),
        pTypeDef->getRefType()->getName().c_str()
    );
    out << L"END_TYPE;\n";
}

void CExpressWriter::writeClass(CClass *pClass, std::wfstream& out)
{
    out << L"ENTITY " << pClass->getName();
    int nCount = pClass->getChildCount();
    if (nCount > 0)
    {
        out << L"\n ";
        if (pClass->getIsAbstract())
        {
            out << L"ABSTRACT ";
        }
        out << L"SUPERTYPE OF (ONEOF\n\t(";
        for (int i = 0; i < nCount; ++i)
        {
            if (i == 0)
            {
                out << pClass->getChild(i)->getName();
            }
            else
            {
                out << L"\n\t," << pClass->getChild(i)->getName();
            }
        }
        out << L"))";
    }
    if (pClass->getParent())
    {
        out << FormatWstring(L"\n SUBTYPE OF (%ls)", 
            pClass->getParent()->getName().c_str()
        );
    }
    out << ";\n";

    nCount = pClass->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttribute = pClass->getAttribute(i);
        std::wstring sPrefix = pAttribute->getOptionalFlag() ? L" OPTIONAL ": L" ";
        //std::wstring sType = pAttribute->getRepeatFlag() ? L"LIST [0:?] OF %ls": L"%ls";
        out << FormatWstring(L"\t%ls :%ls%ls;\n",
            pAttribute->getName().c_str(),
            sPrefix.c_str(),
            pAttribute->getTypeName().c_str()
            //FormatWstring(sType.c_str(), 
            //    pAttribute->getType()->getName().c_str()
            //)
        );
    }

    out << L"END_ENTITY;\n";
}

void CExpressWriter::writeEnum(CEnumType *pEnumType, std::wfstream& out)
{
    out << FormatWstring(L"TYPE %ls = ENUMERATION OF\n", 
        pEnumType->getName().c_str()
    );
    out << L"\t(";
    int nCount = pEnumType->getEnumCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        if (i == 0)
        {
            out << pEnumType->getEnum(i);
        }
        else
        {
            out << L"\n\t," << pEnumType->getEnum(i);
        }
    }
    out << L");\n";
    out << L"END_TYPE;\n";
}
