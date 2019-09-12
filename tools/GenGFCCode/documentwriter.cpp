#include "DocumentWriter.h"
#include <vector>
#include "typeobject.h"
#include "model.h"
#include "class.h"
#include "enumtype.h"
#include "type.h"
#include "attribute.h"
#include <algorithm>
#include <iostream>
#include "common.h"

CDocumentWriter::CDocumentWriter(CModel * pModel) : m_pModel(pModel)
{
}

CDocumentWriter::~CDocumentWriter()
{
}

void CDocumentWriter::write(const std::wstring & sPath)
{
    _ASSERT(m_pModel);
    if (sPath.empty())
    {
        _ASSERT(false);
        return;
    }

    int nCount = m_pModel->getTypeObjectCount();
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
        oFile.open(sPath + L"\\" + pTypeObject->getName() + L".html", std::ios::out);
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
        }
        else
        {
            CTypeDef* pTypeDef = dynamic_cast<CTypeDef*>(pTypeObject);
            if (pTypeDef)
            {
                writeTypedef(pTypeDef, oFile);
            }
            else
            {
                CEnumType* pEnumType = dynamic_cast<CEnumType*>(pTypeObject);
                if (pEnumType)
                {
                    writeEnum(pEnumType, oFile);
                }
            }
        }
        writeTail(oFile);
        oFile.close();
    }
}

void CDocumentWriter::writeTypedef(CTypeDef * pTypeDef, std::fstream& out)
{
}

void CDocumentWriter::writeClass(CClass * pClass, std::fstream& out)
{
    out << L"<div>实体定义</div>";
    out << pClass->getDocument();
    if (pClass->getAttributeCount() > 0)
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
        for (int i = 0; i < pClass->getAttributeCount(); ++i)
        {
            CAttribute* pAttribute = pClass->getAttribute(i);
            out << L"<tr>";
            out << L"<td>";
            out << i + 1;
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
            out << (pAttribute->getOptionalFlag() ? L"" : L"√");
            out << L"</td>";
            out << L"</tr>";
        }
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
