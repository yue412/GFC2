#include "DocumentWriter.h"
#include <vector>
#include "GfcSchema/TypeObject.h"
#include "GfcSchema/Model.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EnumType.h"
#include "GfcSchema/TypeDefine.h"
#include "GfcSchema/EntityAttribute.h"
#include <algorithm>
#include <iostream>
#include "common.h"
#include <assert.h>

CDocumentWriter::CDocumentWriter(CModel * pModel) : m_pModel(pModel)
{
}

CDocumentWriter::~CDocumentWriter()
{
}

void CDocumentWriter::write(const std::wstring & sPath)
{
    assert(m_pModel);
    if (sPath.empty())
    {
        assert(false);
        return;
    }

    int nCount = m_pModel->getTypeObjectCount();
    std::vector<std::wstring> oClassList, oTypeList, oEnumList;
    // 排序
    std::vector<CTypeObject*> oTempList;
    m_pModel->getTypeObjectList(oTempList);
    std::sort(oTempList.begin(), oTempList.end(), lessTypeObject);
    //
    for (int i = 0; i < nCount; ++i)
    {
        CTypeObject* pTypeObject = oTempList[i];//m_pModel->getTypeObject(i);
        if (pTypeObject->getType() == TOE_BUILDIN)
            continue;
        // create file
        std::fstream oFile;
        // todo
        auto sFileName = UnicodeToACP(sPath + L"/" + pTypeObject->getName() + L".html");
        oFile.open(sFileName, std::ios::out);
        if (!oFile.good())
        {
            std::wcout << L"文件打开失败!" << L"\n";
            return;
        }

        writeHead(pTypeObject, oFile);

        CClass* pClass = dynamic_cast<CClass*>(pTypeObject);
        if (pClass)
        {
            writeClass(pClass, oFile);
            oClassList.push_back(pTypeObject->getName());
        }
        else
        {
            CTypeDef* pTypeDef = dynamic_cast<CTypeDef*>(pTypeObject);
            if (pTypeDef)
            {
                writeTypedef(pTypeDef, oFile);
                oTypeList.push_back(pTypeObject->getName());
            }
            else
            {
                CEnumType* pEnumType = dynamic_cast<CEnumType*>(pTypeObject);
                if (pEnumType)
                {
                    writeEnum(pEnumType, oFile);
                    oEnumList.push_back(pTypeObject->getName());
                }
            }
        }
        writeTail(oFile);
        oFile.close();
    }
    // write json data
    std::fstream oFile;
    // todo
    auto sFileName = UnicodeToACP(sPath + L"/class_data.js");
    oFile.open(sFileName, std::ios::out);
    if (!oFile.good())
    {
        std::wcout << L"文件打开失败!" << L"\n";
        return;
    }
    oFile << L"var g_class_data={\"class\":[";
    writeData(oClassList, oFile);
    oFile << "], \"type\":[";
    writeData(oTypeList, oFile);
    oFile << "],\"enum\":[";
    writeData(oEnumList, oFile);
    oFile << "]};";
    oFile.close();
}

void CDocumentWriter::writeTypedef(CTypeDef * pTypeDef, std::fstream& out)
{
    CTypeObject* pType = pTypeDef->getRefType();
    if (pType->getType() == TOE_BUILDIN)
    {
        out << pType->getName() << L"类型";
    }
    else
    {
        std::wstring sType = pType->getName();
        std::wstring sLinkType = L"<a href=\"" + sType + L".html\">" + sType + L"</a>";
        out << sLinkType << L"类型";
    }
}

void CDocumentWriter::writeClass(CClass * pClass, std::fstream& out)
{
    out << L"<div>实体定义</div>";
    std::wstring s = pClass->getDocument();
    out << s;
    //return;
    if (pClass->getTotalAttributeCount() > 0)
    {
        out << L"<div>属性定义</div>";
        out << L"<table border=\"1\">";
        out << L"<tr>";
        out << L"<td>序号</td>";
        out << L"<td>属性名称</td>";
        out << L"<td>中文解释</td>";
        out << L"<td>数据类型</td>";
        out << L"<td>必填</td>";
        out << L"</tr>";
        writeAttributes(pClass, out);
        out << L"</table>";
    }
    if (pClass->getParent() || pClass->getChildCount() > 0)
    {
        out << L"<div>继承关系</div>";
        std::vector<CClass*> oClassList;
        auto pTemp = pClass;
        while (pTemp)
        {
            oClassList.push_back(pTemp);
            pTemp = pTemp->getParent();
        }
        std::wstring sBlank;
        for (int i = oClassList.size() - 1; i >= 0; --i)
        {
            auto sName = oClassList[i]->getName();
            std::wstring sIns = i != (oClassList.size() - 1) ? L"&#9492" : L"";
            std::wstring sParent = i == 0 ? sName : L"<a href = \"" + sName + L".html\">" + sName + L"</a>";
            out << sBlank << sIns << sParent << L"<br>";
            sBlank += L"&nbsp;&nbsp;";
        }

        for (int i = 0; i < pClass->getChildCount(); ++i)
        {
            auto sName = pClass->getChild(i)->getName();
            std::wstring sIns = i != pClass->getChildCount() - 1 ? L"&#9500;" : L"&#9492";
            out << sBlank << sIns << L"<a href = \"" << sName << L".html\">" << sName << L"</a><br>";
        }
    }
}

void CDocumentWriter::writeEnum(CEnumType * pEnumType, std::fstream& out)
{
    out << L"<div>枚举定义</div>";
    std::wstring s = pEnumType->getDocument();
    out << s;
//    out << L"<div>属性定义</div>";
    out << L"<table border=\"1\">";
    out << L"<tr>";
    out << L"<td>序号</td>";
    out << L"<td>枚举名称</td>";
    out << L"<td>中文解释</td>";
    out << L"</tr>";
    for (int i = 0; i < pEnumType->getEnumCount(); i++)
    {
        out << L"<tr>";
        out << L"<td>";
        out << (i + 1);
        out << L"</td>";
        out << L"<td>" << pEnumType->getEnum(i) << L"</td>";
        out << L"<td>" << pEnumType->getEnumDocument(i) << L"</td>";
        out << L"</tr>";
    }
}

void CDocumentWriter::writeHead(CTypeObject * pType, std::fstream & out)
{
    out << L"<html>\n";
    out << L"\t<head>\n";
    out << L"\t\t<meta charset=\"utf-8\">\n";
    out << L"\t\t<title>" << pType->getName() << L"</title>\n";
    out << L"\t</head>\n";
    out << L"\t<body>\n";
}

void CDocumentWriter::writeTail(std::fstream & out)
{
    out << L"\t</body>\n";
    out << L"</html>\n";
}

void CDocumentWriter::writeData(const std::vector<std::wstring>& oList, std::fstream & out)
{
    for (auto s : oList)
    {
        out << L"\"" << s << L"\",";
    }
}

int CDocumentWriter::writeAttributes(CClass * pClass, std::fstream & out)
{
    int nCount = 0;
    if (pClass->getParent())
    {
        nCount = writeAttributes(pClass->getParent(), out);
    }
    out << L"<tr>";
    out << L"<td colspan=\"5\">";
    out << pClass->getName();
    out << L"</td>";
    out << L"</tr>";
    for (int i = 0; i < pClass->getAttributeCount(); ++i)
    {
        CAttribute* pAttribute = pClass->getAttribute(i);
        out << L"<tr>";
        out << L"<td>";
        out << i + 1 + nCount;
        out << L"</td>";

        out << L"<td>";
        out << pAttribute->getName();
        out << L"</td>";

        out << L"<td>";
        out << pAttribute->getDocument();
        out << L"</td>";

        out << L"<td>";
        //out << pAttribute->getTypeName();
        std::wstring sType = pAttribute->getType()->getName();
        std::wstring sLinkType = L"<a href=\"" + sType + L".html\">" + sType + L"</a>";
        std::wstring sPrefix = pAttribute->getRepeatFlag() ? L"LIST [0:?] OF " : L"";
        out << sPrefix << sLinkType;
        out << L"</td>";

        out << L"<td>";
        out << (pAttribute->getOptionalFlag() || pAttribute->getRepeatFlag() ? L"" : L"√");
        out << L"</td>";
        out << L"</tr>";
    }
    return nCount + pClass->getAttributeCount();
}
