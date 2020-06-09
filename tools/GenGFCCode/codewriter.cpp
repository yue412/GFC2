#include "codewriter.h"
#include "GfcSchema/Model.h"
#include <assert.h>
#include "GfcSchema/BuildinType.h"
#include "GfcSchema/EnumType.h"
#include "GfcSchema/TypeDefine.h"
#include "GfcSchema/EntityClass.h"
#include <vector>
#include <algorithm>
#include "GfcSchema/EntityAttribute.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include "cppfile.h"
#include "cppclass.h"
#include "common.h"
#include <set>
//#include <google/protobuf/wire_format_lite.h>
//#include <google/protobuf/wire_format_lite_inl.h>

using namespace gfc::schema;

bool less_TypeObject(CTypeObject* type1, CTypeObject* type2)
{
    if (type1->getType() == type2->getType())
    {
        return type1->getName() < type2->getName();
    }
    else
    {
        return type1->getType() < type2->getType();
    }
}

CCodeWriter::CCodeWriter(CModel *pModel): m_pModel(pModel), m_bOutputHead(false), m_bOutputCpp(false), m_bOutputNet(false)
  //,m_pSchemaFile(NULL), m_pSchemaStream(NULL)
{
}

CCodeWriter::~CCodeWriter()
{

}

void CCodeWriter::writeClassFile(std::vector<CTypeObject *> &oObjectList)
{
    int nClassId = 2; // 1 for EntitySchema, 0 for stream eof

	// 固定classId,如果存在Id的话,那么使用已有的，如果没有，则根据序列创建新的Id
	//std::map<std::wstring,int> oClassIdMap;

	int nMaxClassId = 1;
	// 根据ini文件来确定Class的ID
    std::vector<std::pair<std::wstring, int>> strList;
    std::wfstream oFile;
    oFile.open("classID.ini", std::ios::in);
    if (oFile.good())
    {
        //oFile << sNew;
        //QSettings oClassIdSetting("classID.ini", QSettings::IniFormat);
        while (!oFile.eof())
        {
            wchar_t buffer[256];
            oFile.getline(buffer, 255);
            std::wstring sTemp = std::wstring(buffer);
            int nPos = sTemp.find(L'=');
            if (nPos != std::wstring::npos)
            {
                std::wstring sName = sTemp.substr(0, nPos);
                std::wstring sNum = sTemp.substr(nPos + 1);
                int nNum = std::stoi(sNum);
                strList.push_back(std::make_pair(sName, nNum));
            }
        }
        oFile.close();

        for (int m = 0; m < (int)strList.size(); m++)
        {
            int curId = strList[m].second;
            if (curId > nMaxClassId)
            {
                nMaxClassId = curId;
            }
        }
    }

    //bool bOutputText = !m_sTextPath.empty();
    //bool bOutputBin = !m_sBinPath.empty();
    int nCount = oObjectList.size();
    for(int i = 0; i < nCount; ++i)
    {
        CClass* pTypeObj = dynamic_cast<CClass*>(oObjectList[i]);
        if (pTypeObj)
        {
			// 没有找到，所以这里的ID是新建的，xuxp,2017-6-28
            auto itr = std::find_if(strList.begin(), strList.end(), 
                [pTypeObj](std::pair<std::wstring, int>& oItem) {return pTypeObj->getName() == oItem.first; });
			if (itr != strList.end())
			{
				nClassId = itr->second;
			}
			else
			{
				nClassId = ++nMaxClassId;
                strList.push_back(std::make_pair(pTypeObj->getName(), nClassId));
				//oClassIdMap.insert(std::make_pair(pTypeObj->getName(),nClassId));
			}

            CppClass* pClass = createCppClass(pTypeObj, nClassId);
            CppClass* pFactoryClass = NULL;
            CppClass* pFieldCacheClass = NULL;
//            if (!pTypeObj->getIsAbstract())
//            {
//                pFactoryClass = createFactoryClass(pTypeObj);
//            }

            if (pTypeObj->getAttributeCount() > 0)
            {
                pFieldCacheClass = createFieldCacheClass(pTypeObj);
            }

            if(m_bOutputHead)
                writeClassHeadFile(pTypeObj, pClass, pFactoryClass, nullptr);

            if(m_bOutputCpp)
                writeClassImpFile(pTypeObj, pClass, pFactoryClass, nullptr);
            delete pClass;

            //if (bOutputBin)
            //{
            //    CppClass* pBinarySerializerClass = createBinarySerializerClass(pTypeObj);
            //    writeBinarySerializerClassFile(pTypeObj, pBinarySerializerClass, pFieldCacheClass);
            //    delete pBinarySerializerClass;
            //}
            //delete pFieldCacheClass;
            //if (bOutputText)
            //{
            //    CppClass* pTextSerializerClass = createTextSerializerClass(pTypeObj);
            //    writeTextSerializerClassFile(pTypeObj, pTextSerializerClass);
            //    delete pTextSerializerClass;
            //}

            if(m_bOutputNet)
            {
                CppClass* pCliClass = createCppCliClass(pTypeObj, nClassId);
                writeCliClassHeadFile(pTypeObj, pCliClass);
                writeCliClassImpFile(pCliClass);
                delete pCliClass;
            }

            ++nClassId;
        }
    }

	// 统一写出,xuxp,2017-7-05
	//CppHeadFile oTypeConstsFile(L"TypeConsts");
	//for ( int m = 0;m < (int)strList.size();m++)
	//{
	//	std::wstring sName = strList.at(m).first;
	//	int curId = strList.at(m).second;
	//	oTypeConstsFile.body()->addLine(FormatWstring(L"#define %s_ID %d", 
 //           UpperString(sName).c_str(),
 //           curId
 //       ));
	//}
	//for (auto oIter = oClassIdMap.begin();oIter != oClassIdMap.end();oIter++)
	//{
	//	oTypeConstsFile.body()->addLine(FormatWstring(L"#define %s_ID %d", 
 //           UpperString(oIter->first), 
 //           oIter->second
 //       ));
	//}

    //if(m_bOutputHead)
    //{
    //    oTypeConstsFile.body()->addLine(L"");
    //    oTypeConstsFile.saveTo(m_sPath);
    //    updateProgressBar();
    //}
    updateProgressBar();

	
	// 保存ID为配置文件，xuxp,2017-6-28
    //oFile.open("classID.ini", std::ios::out);
    //if (oFile.good())
    //{
    //    for each (auto oPair in strList)
    //    {
    //        oFile << oPair.first << L"=" << oPair.second << std::endl;
    //    }
    //    oFile.close();
    //}
}

void CCodeWriter::writeClassHeadFile(CClass *pTypeObject, CppClass *pClass, CppClass *pFactoryClass, CppClass *pFieldCacheClass)
{
    CppHeadFile oFile(pTypeObject->getName());
    std::set<std::wstring> oIncludeSet;
    int nCount = pTypeObject->getAttributeCount();
    oFile.addInclude(L"GfcClasses.h");
    //oFile.addInclude(L"GfcEngine/EntityFactory.h");
//    if (nCount > 0)
//        oFile.addInclude(L"vector", true);
//    oFile.addInclude("google/protobuf/io/coded_stream.h", true);
    // include parent file
    if (pTypeObject->getParent())
    {
        oFile.addInclude(pTypeObject->getParent()->getName() + L".h");
        oIncludeSet.insert(pTypeObject->getParent()->getName());
    }
    // include attribute file
    bool bFlag = false;
    bool bTypeDef = false;
    for (int i = 0; i < nCount; ++i)
    {
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        if (pAttribute->getType()->getType() == TOE_TYPE)
        {
            bTypeDef = true;
        }
        if (getBaseType(pAttribute->getType()) == EBT_ENTITY)
        {
            if (pAttribute->getType()->getType() == TOE_CLASS )
            {
                if (oIncludeSet.find(pAttribute->getType()->getName()) == oIncludeSet.end())
                {
                    oFile.addInclude(pAttribute->getType()->getName() + L".h");
                    oIncludeSet.insert(pAttribute->getType()->getName());
                }
            }
            bFlag = true;
        }
    }
    if (bTypeDef)
        oFile.addInclude(L"TypeDef.h");
//    if (bFlag)
//        oFile.addInclude(L"GfcEngine/Document.h");
    oFile.addInclude(L"GfcEngine/Entity.h");
    //oFile.addInclude("GfcEngine/EntityFactory.h");
    
    oFile.body()->add(pClass->createDeclareCode());
    if (pFactoryClass)
    {
        oFile.body()->addLine(L"");
        oFile.body()->add(pFactoryClass->createDeclareCode());
    }
    if (pFieldCacheClass)
    {
        oFile.body()->addLine(L"");
        oFile.body()->add(pFieldCacheClass->createDeclareCode());
    }
    oFile.saveTo(m_sPath);
    updateProgressBar();
}

void CCodeWriter::writeClassImpFile(CClass* pTypeObject, CppClass *pClass, CppClass *pFactoryClass, CppClass *pFieldCacheClass)
{
    CppFile oFile(pClass->name(), false);
    /*
    oFile.addInclude(pClass->name() + L"BinarySerializer.h", false);
    oFile.addInclude(pClass->name() + L"TextSerializer.h", false);
    */
    oFile.addInclude(L"GfcSchema.h");
    oFile.addInclude(L"GfcEngine/PropValue.h");
    bool bFlag = false;
    bool bTypeDef = false;
    int nCount = pTypeObject->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        if (getBaseType(pAttribute->getType()) == EBT_ENTITY)
        {
            bFlag = true;
            break;
        }
    }
    if (bFlag)
        oFile.addInclude(L"GfcEngine/Container.h");
    oFile.body()->addLine(FormatWstring(L"GFCENGINE_IMP_OBJECT(%s,L\"%s\",0)", 
        pClass->name().c_str(),
        pClass->name().c_str()
    ));
    oFile.body()->addLine(L"");
    if(pFieldCacheClass)
    {
        oFile.body()->addLine(FormatWstring(L"GFCENGINE_IMP_OBJECT(%sFieldCacheInitializer,\"%s\",0)", 
            pClass->name().c_str(),
            pClass->name().c_str()
        ));
        oFile.body()->addLine(L"");
    }
    oFile.body()->add(pClass->createImpCode());
    if(pFactoryClass)
        oFile.body()->add(pFactoryClass->createImpCode());
    if(pFieldCacheClass)
        oFile.body()->add(pFieldCacheClass->createImpCode());

    oFile.saveTo(m_sCPPPath);
    updateProgressBar();
}

void CCodeWriter::writeCliClassHeadFile(CClass *pTypeObject, CppClass *pClass)
{
    CppHeadFile oFile(pClass->name());
    std::set<std::wstring> oIncludeSet;
    int nCount = pTypeObject->getAttributeCount();
    // include parent file
    if (pTypeObject->getParent())
    {
        oFile.addInclude(L"N" + pTypeObject->getParent()->getName() + L".h");
        oIncludeSet.insert(L"N" + pTypeObject->getParent()->getName());
    }
    // include attribute file
    //if (nCount > 0)
    {
        oFile.addInclude(pTypeObject->getName() + L".h");
        oIncludeSet.insert(pTypeObject->getName());
    }
    bool bFlag = false;
    bool bTypeDef = false;
    bool bStringFlag = false;
    for (int i = 0; i < nCount; ++i)
    {
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        if (getBaseType(pAttribute->getType()) == EBT_STRING)
            bStringFlag = true;
        if (pAttribute->getType()->getType() == TOE_TYPE || pAttribute->getType()->getType() == TOE_ENUM)
        {
            bTypeDef = true;
        }
        if (getBaseType(pAttribute->getType()) == EBT_ENTITY)
        {
            if (pAttribute->getType()->getType() == TOE_CLASS )
            {
                if (oIncludeSet.find(L"N" + pAttribute->getType()->getName()) == oIncludeSet.end())
                {
                    oFile.addInclude(L"N" + pAttribute->getType()->getName() + L".h");
                    //oFile.addInclude(pAttribute->getType()->getName() + ".h");
                    oIncludeSet.insert(L"N" + pAttribute->getType()->getName());
                }
            }
            bFlag = true;
        }
    }
    if (bTypeDef)
        oFile.addInclude(L"NTypeDef.h");
//    if (bFlag)
//        oFile.addInclude("GfcEngine/Document.h");
    oFile.addInclude(L"GfcEngine/Entity.h");
    //oFile.addInclude("GfcEngine/EntityFactory.h");
    //oFile.addInclude("GfcEngine/FieldCacheInitializer.h");
    if(bStringFlag)
    {
        oFile.addInclude(L"msclr/marshal_cppstd.h", true);
        oFile.body()->addLine(L"using namespace System;");
        oFile.body()->addLine(L"using namespace msclr::interop;");
        oFile.body()->addLine(L"");
    }
    oFile.body()->add(pClass->createDeclareCode(true));
    oFile.saveTo(m_sNETPath);
    updateProgressBar();
}

void CCodeWriter::writeCliClassImpFile(CppClass *pClass)
{
    CppFile oFile(pClass->name(), true);
//    oFile.addInclude("google/protobuf/wire_format_lite.h", true);
//    oFile.addInclude("google/protobuf/wire_format_lite_inl.h", true);
    //oFile.addInclude("msclr/marshal_cppstd.h", true);
    oFile.body()->add(pClass->createImpCode());

    oFile.saveTo(m_sNETPath);
    updateProgressBar();
}

void CCodeWriter::writeBinarySerializerClassFile(CClass *pTypeObject, CppClass *pClass, CppClass* pFieldCacheClass)
{
    //{
    //    CppHeadFile oFile(pClass->name());
    //    // include parent file
    //    if (pTypeObject->getParent())
    //        oFile.addInclude(pTypeObject->getParent()->getName() + L"BinarySerializer.h");
    //    else
    //        oFile.addInclude(L"EntityBinarySerializer.h");
    //    oFile.addInclude(L"FieldCacheInitializer.h");

    //    oFile.body()->add(pClass->createDeclareCode());

    //    if (pFieldCacheClass)
    //    {
    //        oFile.body()->addLine(L"");
    //        oFile.body()->add(pFieldCacheClass->createDeclareCode());
    //    }
    //    oFile.saveTo(m_sBinPath);
    //    updateProgressBar();
    //}
    //{
    //    CppFile oFile(pClass->name(), false);
    //    //oFile.addInclude("StdAfx.h");
    //    oFile.addInclude(L"google/protobuf/wire_format_lite.h", true);
    //    oFile.addInclude(L"google/protobuf/wire_format_lite_inl.h", true);
    //    oFile.addInclude(L"google/protobuf/stubs/common.h", true);
    //    oFile.addInclude(L"FieldCache.h", false);
    //    oFile.addInclude(pTypeObject->getName() + L".h", false);

    //    oFile.body()->addLine(FormatWstring(L"GFCENGINE_IMP_OBJECT(%s,\"%sB\",0)",
    //        pClass->name().c_str(),
    //        pTypeObject->getName().c_str()
    //    ));
    //    if (pFieldCacheClass)
    //    {
    //        oFile.body()->addLine(FormatWstring(L"GFCENGINE_IMP_OBJECT(%s,\"%s\",0)",
    //            pFieldCacheClass->name().c_str(),
    //            pTypeObject->getName().c_str()
    //        ));
    //    }
    //    oFile.body()->addLine(L"");
    //    oFile.body()->add(pClass->createImpCode());
    //    if (pFieldCacheClass)
    //        oFile.body()->add(pFieldCacheClass->createImpCode());
    //    oFile.saveTo(m_sBinPath);
    //    updateProgressBar();
    //}
}

void CCodeWriter::writeTextSerializerClassFile(CClass *pTypeObject, CppClass *pClass)
{
    //{
    //    CppHeadFile oFile(pClass->name());
    //    // include parent file
    //    if (pTypeObject->getParent())
    //        oFile.addInclude(pTypeObject->getParent()->getName() + L"TextSerializer.h");
    //    else
    //        oFile.addInclude(L"EntityTextSerializer.h");
    //    oFile.body()->add(pClass->createDeclareCode());
    //    oFile.saveTo(m_sTextPath);
    //    updateProgressBar();
    //}
    //{
    //    CppFile oFile(pClass->name(), true);
    //    //oFile.addInclude("StdAfx.h");
    //    //oFile.addInclude(L"FieldCache.h", false);
    //    oFile.addInclude(pTypeObject->getName() + L".h", false);

    //    oFile.body()->addLine(FormatWstring(L"GFCENGINE_IMP_OBJECT(%s,\"%sT\",0)", 
    //        pClass->name().c_str(),
    //        pTypeObject->getName().c_str()
    //    ));
    //    oFile.body()->addLine(L"");
    //    oFile.body()->add(pClass->createImpCode());
    //    oFile.saveTo(m_sTextPath);
    //    updateProgressBar();
    //}
}

void CCodeWriter::write(const std::wstring& sPathName, const std::wstring &sCPPPath, /*const std::wstring &sTextPath, const std::wstring &sBinPath,*/
    const std::wstring& sNETPath)
{
    assert(m_pModel);
    if (!m_pModel)
        return;
    m_sPath = sPathName;
    m_sCPPPath = sCPPPath;
    //m_sTextPath = sTextPath;
    //m_sBinPath = sBinPath;
    m_sNETPath = sNETPath;
    m_bOutputCpp = !sCPPPath.empty();
    m_bOutputHead = !sPathName.empty();
    m_bOutputNet = !sNETPath.empty();

    m_nCount = 0;
    //emit reset();
    //emit setRange(0, m_bOutputCpp ? getClassCount() * 5 + 1 : 0
    //               + m_bOutputHead ? getClassCount() * 1 + 3 : 0
    //               + m_bOutputNet ? getClassCount() * 2 + 1 : 0
    //                                 );
    // 排序
    std::vector<CTypeObject*> oTempList;
    m_pModel->getTypeObjectList(oTempList);
    std::sort(oTempList.begin(), oTempList.end(), less_TypeObject);

    if(m_bOutputHead)
        writeTypedefFile(oTempList);
    if(m_bOutputNet)
        writeCliTypedefFile(oTempList);
    writeClassFile(oTempList);
    if(m_bOutputHead)
        writeFieldCacheHeadFile();
    if(m_bOutputCpp)
        writeFieldCacheImpFile();
//    writeRegSchemaInfoHeadFile();
    //    writeRegSchemaInfoImpFile();
}

void CCodeWriter::updateProgressBar()
{
    //++m_nCount;
    //emit setValue(m_nCount);
}

int CCodeWriter::getClassCount()
{
    int nResult = 0;
    int nCount = m_pModel->getTypeObjectCount();
    for(int i = 0; i < nCount; ++i)
    {
        CClass* pTypeObj = dynamic_cast<CClass*>(m_pModel->getTypeObject(i));
        if (pTypeObj)
        {
            ++nResult;
        }
    }
    return nResult;
}

void CCodeWriter::writeFieldCacheHeadFile()
{
   // CppHeadFile oFile(L"FieldCache");

   // CppClass oClass(L"FieldCache");

   // CFunction* pFunc = oClass.addConstructor(AT_PUBLIC);
   // pFunc->setIsInline(true);

   // int nCount = m_pModel->getTypeObjectCount();
   // for(int i = 0; i < nCount; ++i)
   // {
   //     CTypeObject* pTypeObj = m_pModel->getTypeObject(i);
   //     if (pTypeObj->getType() == TOE_CLASS)
   //     {
   //         CClass* pClass = dynamic_cast<CClass*>(pTypeObj);
   //         int nAttribCount = pClass->getAttributeCount();
   //         for (int j = 0; j < nAttribCount; ++j)
   //         {
   //             std::wstring sField = FormatWstring(L"_%s_%s",
   //                 pClass->getName().c_str(),
   //                 pClass->getAttribute(j)->getName().c_str()
   //             );
   //             oClass.addData(AT_PUBLIC, L"int", sField);
   //             pFunc->addInitListItem(sField, L"0");
   //         }
   //     }
   // }

   //// oFile.addInclude(L"GfcClasses.h");
   // oFile.body()->add(oClass.createDeclareCode());
   // oFile.body()->addLine(L"");
   // oFile.body()->addLine(L"extern FieldCache* _FieldCache;");
   // oFile.body()->addLine(L"");
   // oFile.body()->addLine(L"void initFieldCache();");
   // oFile.body()->addLine(L"void freeFieldCache();");
   // oFile.body()->addLine(L"");

   // oFile.saveTo(m_sBinPath);
   // updateProgressBar();
}

void CCodeWriter::writeFieldCacheImpFile()
{
    //CppFile oFile(L"FieldCache", true);
    ////oFile.addInclude("StdAfx.h");
    //oFile.body()->addLine(L"");
    //oFile.body()->addLine(L"FieldCache* _FieldCache = 0;");
    //oFile.body()->addLine(L"");
    //oFile.body()->addLine(L"void initFieldCache()");
    //CppCode::createBlock(oFile.body())
    //        ->addLine(L"if (_FieldCache)")
    //        ->add((new CIndent)->addLine(L"freeFieldCache();"))
    //        ->addLine(L"_FieldCache = new FieldCache();");
    //oFile.body()->addLine(L"");
    //oFile.body()->addLine(L"void freeFieldCache()");
    //CppCode::createBlock(oFile.body())
    //        ->addLine(L"delete _FieldCache;")
    //        ->addLine(L"_FieldCache = 0;");
    //oFile.saveTo(m_sBinPath);
    //updateProgressBar();
}

void CCodeWriter::writeTypedefFile(std::vector<CTypeObject *> &oObjectList)
{
    std::set<std::wstring> oTypeDefIncludes;
    CppHeadFile oTypeDefHeadFile(L"TypeDef");
    oTypeDefHeadFile.addInclude(L"string", true);
    CppCode* pEnumGroup = NULL;
    CppCode* pEnumFuncGroup = NULL;
    int nCount = oObjectList.size();
    for(int i = 0; i < nCount; ++i)
    {
        CTypeObject* pTypeObj = oObjectList[i];
        switch (pTypeObj->getType()) {
        case TOE_TYPE:
            {
                CTypeDef* pTypeObject = dynamic_cast<CTypeDef*>(pTypeObj);
                if (!pTypeObject)
                    continue;
                CTypeObject* pType = pTypeObject->getRefType();
                if (pType && pType->getType() == TOE_CLASS && oTypeDefIncludes.find(pType->getName()) == oTypeDefIncludes.end())
                {
                    oTypeDefHeadFile.addInclude(FormatWstring(L"%s.h",
                        pType->getName().c_str()
                    ));
                    oTypeDefIncludes.insert(pType->getName());
                }

                std::wstring sRefTypeName = getTypeCode(pTypeObject->getRefType());
                oTypeDefHeadFile.body()->addLine(FormatWstring(L"typedef %s %s;", 
                    sRefTypeName.c_str(), 
                    pTypeObject->getName().c_str()
                ));
                oTypeDefHeadFile.body()->addLine(L"");
            }
            break;
        case TOE_ENUM:
            {
                CEnumType* pTypeObject = dynamic_cast<CEnumType*>(pTypeObj);
                if (!pTypeObject)
                    continue;

                if (pEnumGroup == NULL)
                    pEnumGroup = CppCode::createGroup(oTypeDefHeadFile.body());
                pEnumGroup->addLine(L"enum " + pTypeObject->getName());
                CppCode* pBlock = CppCode::createBlock(pEnumGroup, true);
                int nCount = pTypeObject->getEnumCount();
                for (int i = 0; i < nCount; ++i)
                {
                    std::wstring sTemp = pTypeObject->getEnum(i);
                    if (i != nCount - 1)
                    {
                        sTemp += L",";
                    }
                    pBlock->addLine(sTemp);
                }
                pEnumGroup->addLine(L"");

                if (pEnumFuncGroup == NULL)
                    pEnumFuncGroup = CppCode::createGroup(oTypeDefHeadFile.body());
                pEnumFuncGroup->addLine(FormatWstring(L"inline std::string %sToString(%s nValue)",
                    pTypeObject->getName().c_str(),
                    pTypeObject->getName().c_str()
                ));
                CppCode* pTemp = new CBlock(false);
                CppCode::createBlock(pEnumFuncGroup)
                        ->addLine(L"switch(nValue)")
                        ->add(pTemp);
                for (int i = 0; i < nCount; ++i)
                {
                    pTemp->addLine(FormatWstring(L"case %s::%s:", 
                        pTypeObject->getName().c_str(),
                        pTypeObject->getEnum(i).c_str()
                    ));
                    pTemp->add((new CIndent)
                                   ->addLine(FormatWstring(L"return \".%s.\";",
                                       pTypeObject->getEnum(i).c_str()
                                   ))
                                   ->addLine(L"break;"));
                }
                pTemp->addLine(L"default:");
                pTemp->add((new CIndent)
                      ->addLine(L"assert(false);")
                      ->addLine(L"return \"\";"));
                pEnumFuncGroup->addLine(L"");
                pEnumFuncGroup->addLine(FormatWstring(L"inline bool StringTo%s(const std::string& sValue, %s& nType)",
                    pTypeObject->getName().c_str(),
                    pTypeObject->getName().c_str()
                    ));
                CppCode* pBlock2 = CppCode::createBlock(pEnumFuncGroup);
                for (int i = 0; i < nCount; ++i)
                {
					pBlock2->addLine(FormatWstring(L"if(sValue.compare(\".%s.\") == 0)", 
                        pTypeObject->getEnum(i).c_str()
                    ));
					pBlock2->add((new CBlock(false))
                                 ->add((new CIndent())
                                    ->addLine(FormatWstring(L"nType = %s::%s;", 
                                        pTypeObject->getName().c_str(),
                                        pTypeObject->getEnum(i).c_str()
                                    ))
                                    ->addLine(L"return true;")));
                }
                pBlock2->addLine(L"return false;");
                pEnumFuncGroup->addLine(L"");
            }
            break;
        }
    }
    oTypeDefHeadFile.saveTo(m_sPath);
    updateProgressBar();
}

void CCodeWriter::writeCliTypedefFile(std::vector<CTypeObject *> &oObjectList)
{
    std::set<std::wstring> oTypeDefIncludes;
    CppHeadFile oTypeDefHeadFile(L"NTypeDef");
//    oTypeDefHeadFile.addInclude("TypeDef.h");
    CppCode* pEnumGroup = NULL;
    int nCount = oObjectList.size();
    for(int i = 0; i < nCount; ++i)
    {
        CTypeObject* pTypeObj = oObjectList[i];
        switch (pTypeObj->getType()) {
        case TOE_TYPE:
            {
                CTypeDef* pTypeObject = dynamic_cast<CTypeDef*>(pTypeObj);
                if (!pTypeObject)
                    continue;
                CTypeObject* pType = pTypeObject->getRefType();
                if (pType && pType->getType() == TOE_CLASS && oTypeDefIncludes.find(L"N" + pType->getName()) == oTypeDefIncludes.end())
                {
                    oTypeDefHeadFile.addInclude(FormatWstring(L"N%s.h", 
                        pType->getName().c_str()
                    ));
                    oTypeDefIncludes.insert(L"N" + pType->getName());
                }
                std::wstring sRefTypeName = getTypeCode(pTypeObject->getRefType());
                if (pType && pType->getType() == TOE_CLASS)
                    oTypeDefHeadFile.body()->addLine(FormatWstring(L"typedef N%s N%s;", 
                        sRefTypeName.c_str(), 
                        pTypeObject->getName().c_str()
                    ));
                else
                    oTypeDefHeadFile.body()->addLine(FormatWstring(L"typedef %s N%s;", 
                        sRefTypeName.c_str(), 
                        pTypeObject->getName().c_str()
                    ));
                oTypeDefHeadFile.body()->addLine(L"");
            }
            break;
        case TOE_ENUM:
            {
                CEnumType* pTypeObject = dynamic_cast<CEnumType*>(pTypeObj);
                if (!pTypeObject)
                    continue;

                if (pEnumGroup == NULL)
                    pEnumGroup = CppCode::createGroup(oTypeDefHeadFile.body());
                pEnumGroup->addLine(L"public enum class N" + pTypeObject->getName());
                CppCode* pBlock = CppCode::createBlock(pEnumGroup, true);
                int nCount = pTypeObject->getEnumCount();
                for (int i = 0; i < nCount; ++i)
                {
                    std::wstring sTemp = pTypeObject->getEnum(i);
                    if (i != nCount - 1)
                    {
                        sTemp += L",";
                    }
                    pBlock->addLine(sTemp);
                }
                pEnumGroup->addLine(L"");

            }
        }
    }
    oTypeDefHeadFile.saveTo(m_sNETPath);
    updateProgressBar();
}

//void CCodeWriter::writeClass(CClass *pTypeObject, int nTypeId)
//{
//    if (!pTypeObject)
//        return;
//    writeClassHead(pTypeObject);
//    writeClassImp(pTypeObject, nTypeId);
//}

CppClass* CCodeWriter::createFactoryClass(CClass *pTypeObject)
{
    std::wstring sName = pTypeObject->getName();
    CppClass* pClass = new CppClass(sName + L"Factory", AT_PUBLIC, L"gfc::engine::CEntityFactory");
    CFunction* pFunc = pClass->addFunc(AT_PUBLIC, L"gfc::engine::CEntity*", L"create", false, true);
    pFunc->body()->addLine(FormatWstring(L"return new %s();", 
        sName.c_str()
    ));
    return pClass;
}

void CCodeWriter::addConstructor(CClass *pTypeObject, CppClass* pClass)
{
    {
        CFunction* pFunc = pClass->addConstructor(AT_PUBLIC);
        pFunc->body()->addLine(L"setSchema(findSchema(L\"" + pClass->name() + L"\"));");
        if (pTypeObject->getParent())
            pFunc->addInitListItem(FormatWstring(L"%s(false)",
                getParentClassCode(pTypeObject).c_str()
            ));
    }
    {
        CFunction* pFunc = pClass->addConstructor(AT_PUBLIC);
        pFunc->addParam(L"bool", L"bSetSchema");
        if (pTypeObject->getParent())
            pFunc->addInitListItem(FormatWstring(L"%s(bSetSchema)",
                getParentClassCode(pTypeObject).c_str()
            ));
        pFunc->body()->addLine(L"if (bSetSchema)");
        CppCode::createBlock(pFunc->body())
            ->addLine(L"setSchema(findSchema(L\"" + pClass->name() + L"\"));");
    }
    //int nCount = pTypeObject->getAttributeCount();
    //for (int i = 0; i < nCount; ++i)
    //{
    //    CAttribute* pAttribute = pTypeObject->getAttribute(i);
    //    EnBaseType nType = getBaseType(pAttribute->getType());
    //    std::wstring sPrefix = getBaseTypePrefix(nType, true);//pAttribute->getRefFlag());
    //    std::wstring sDefault = getTypeDefaultValue(nType, pAttribute->getType()->getName(), true/*pAttribute->getRefFlag()*/);
    //    if (!pAttribute->getRepeatFlag() && nType != EBT_STRING)
    //    {
    //        pFunc->body()->addLine(FormatWstring(L"m_%s%s = %s;",
    //            sPrefix.c_str(),
    //            pAttribute->getName().c_str(),
    //            sDefault.c_str()
    //        ));
    //    }
    //}
    //if (!pTypeObject->getParent())
    //{
    //    pFunc->body()->addLine(L"memset(_has_bits_, 0, sizeof(_has_bits_));");
    //}
}

void CCodeWriter::addCliConstructor1(CClass *pTypeObject, CppClass *pClass)
{
    CFunction* pFunc = pClass->addConstructor(AT_PUBLIC);
    pFunc->body()->addLine(FormatWstring(L"m_pEntity = new %s;", 
        pTypeObject->getName().c_str()
    ));
    pFunc->body()->addLine(L"m_bOwner = true;");
}

void CCodeWriter::addCliConstructor2(CClass *pTypeObject, CppClass *pClass)
{
    CFunction* pFunc = pClass->addConstructor(AT_PUBLIC);
    pFunc->addParam(L"void*", L"pEntity");
    pFunc->addParam(L"bool", L"bOwner");
    pFunc->addInitListItem(FormatWstring(L"%s(pEntity, bOwner)", 
        getParentClassCode(pTypeObject, true).c_str()
    ));
}

void CCodeWriter::addByteSizeFunc(CClass *pTypeObject, CppClass* pClass)
{
    int nCount = pTypeObject->getAttributeCount();
    CFunction* pFunc = pClass->addFunc(AT_PUBLIC, L"int", L"byteSize", true);
    pFunc->addParam(L"gfc::engine::CEntity*", L"pEntity");
    pFunc->body()->addLine(FormatWstring(L"%s* pEnt = (%s*)pEntity;", 
        pTypeObject->getName().c_str(),
        pTypeObject->getName().c_str()
    ));
    pFunc->body()->addLine(FormatWstring(L"int total_size = %s::byteSize(pEnt);", 
        (getParentClassCode(pTypeObject) + L"BinarySerializer").c_str()
    ));
    pFunc->body()->addLine(L"");
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        int nTagSize = getAttributeIndex(pTypeObject, i) < 15 ? 1: 2;
        std::wstring sSizeCode = getSizeCode(pAttribute);
        if (pAttribute->getRepeatFlag())
        {
            //*****
            pFunc->body()->addLine(FormatWstring(L"if (pEnt->get%sCount() > 0)", 
                pAttribute->getName().c_str()
            ));
            pFunc->body()->add((new CIndent)
                               ->addLine(FormatWstring(L"total_size += %d + ::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->get%sCount());", 
                                   nTagSize,
                                   pAttribute->getName().c_str()                                   
                               )));
            //*****
            pFunc->body()->addLine(FormatWstring(L"for (int i = 0; i < pEnt->get%sCount(); i++)", 
                pAttribute->getName().c_str()
            ));
            CppCode::createBlock(pFunc->body())
                    ->addLine(FormatWstring(L"total_size += %s;", 
                        sSizeCode.c_str()
                    ));
        }
        else
        {
            pFunc->body()->addLine(FormatWstring(L"if (pEnt->has%s())", 
                pAttribute->getName().c_str()
            ));
            CppCode::createBlock(pFunc->body())
                    ->addLine(FormatWstring(L"total_size += %d + %s;", 
                        nTagSize, 
                        sSizeCode.c_str()
                    ));
        }
        pFunc->body()->addLine(L"");
    }
    pFunc->body()->addLine(L"return total_size;");
}

void CCodeWriter::addIsInitializedFunc(CClass *pTypeObject, CppClass* pClass)
{
    CFunction* pFunc = pClass->addFunc(AT_PUBLIC, L"bool", L"isInitialized", true);
    std::vector<int> oFlagList;
    getRequireFlag(pTypeObject, oFlagList);
    for (int i = 0; i < (int)oFlagList.size(); ++i)
    {
        if (oFlagList[i] > 0)
            pFunc->body()->addLine(FormatWstring(L"if ((_has_bits_[%d] & 0x%x) != 0x%x) return false;", 
                i, 
                oFlagList[i],
                oFlagList[i]
            ));
    }
    pFunc->body()->addLine(L"");
    pFunc->body()->addLine(L"return true;");
}

void CCodeWriter::addEntityNameFunc(CClass *pTypeObject, CppClass *pClass)
{
    CFunction* pFunc = pClass->addFunc(AT_PUBLIC, L"std::string", L"entityName", true, true);
    pFunc->body()->addLine(FormatWstring(L"return \"%s\";", 
        pTypeObject->getName().c_str()
    ));
}

void CCodeWriter::addSerializeWithCachedSizesFunc(CClass *pTypeObject, CppClass* pClass)
{
    CFunction* pFunc = pClass->addFunc(AT_PROTECTED, L"void", L"serializeWithCachedSizes", true, true);
    pFunc->addParam(L"google::protobuf::io::CodedOutputStream*", L"output");
    pFunc->addParam(L"gfc::engine::CEntity*", L"pEntity");
    pFunc->body()->addLine(FormatWstring(L"%s* pEnt = (%s*)pEntity;", 
        pTypeObject->getName().c_str(),
        pTypeObject->getName().c_str()
    ));
    pFunc->body()->addLine(FormatWstring(L"%s::serializeWithCachedSizes(output, pEnt);", 
        (getParentClassCode(pTypeObject) + L"BinarySerializer").c_str()
    ));
    pFunc->body()->addLine(L"");
    int nCount = pTypeObject->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        int nId = getAttributeIndex(pTypeObject, i) + 1;
        EnBaseType nType = getBaseType(pAttribute->getType());
        if (pAttribute->getRepeatFlag())
        {
            std::wstring sCode = getTypeWriteCodeNoTag(nType, pAttribute->getRepeatFlag(), true/*pAttribute->getRefFlag()*/);
            pFunc->body()->addLine(FormatWstring(L"if (pEnt->get%sCount() > 0)", 
                pAttribute->getName().c_str()
            ));
            CppCode::createBlock(pFunc->body())
                    ->addLine(FormatWstring(L"::google::protobuf::internal::WireFormatLite::WriteTag(%d, %s, output);", 
                        nId, 
                        L"google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED"
                    ))
                    ->addLine(FormatWstring(L"::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->get%sCount(), output);",
                        pAttribute->getName().c_str()
                    ))
                    ->addLine(FormatWstring(L"for (int i = 0; i < pEnt->get%sCount(); i++)", 
                        pAttribute->getName().c_str()
                    ))
                    ->add((new CBlock(false))->add((new CIndent())
                            ->addLine(FormatWstring(sCode.c_str(),
                                pAttribute->getName().c_str()
                            ))));
        }
        else
        {
            std::wstring sCode = getTypeWriteCode(nType, pAttribute->getRepeatFlag(), true/*pAttribute->getRefFlag()*/);
            pFunc->body()->addLine(FormatWstring(L"if (pEnt->has%s())", 
                pAttribute->getName().c_str()
            ));
            CppCode::createBlock(pFunc->body())->addLine(FormatWstring(sCode.c_str(), 
                nId, 
                pAttribute->getName().c_str()
            ));
        }
        pFunc->body()->addLine(L"");
    }
}

void CCodeWriter::addSerializeWithCachedSizesToArrayFunc(CClass *pTypeObject, CppClass* pClass)
{
    CFunction* pFunc = pClass->addFunc(AT_PROTECTED, L"google::protobuf::uint8*", L"serializeWithCachedSizesToArray", true, true);
    pFunc->addParam(L"google::protobuf::uint8*", L"target");
    pFunc->addParam(L"gfc::engine::CEntity*", L"pEntity");

    pFunc->body()->addLine(FormatWstring(L"%s* pEnt = (%s*)pEntity;", 
        pTypeObject->getName().c_str(),
        pTypeObject->getName().c_str()
    ));

    pFunc->body()->addLine(FormatWstring(L"target = %s::serializeWithCachedSizesToArray(target, pEnt);", 
        (getParentClassCode(pTypeObject) + L"BinarySerializer").c_str()
    ));
    pFunc->body()->addLine(L"");
    int nCount = pTypeObject->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        int nId = getAttributeIndex(pTypeObject, i) + 1;
        EnBaseType nType = getBaseType(pAttribute->getType());
        if (pAttribute->getRepeatFlag())
        {
            std::wstring sCode = getTypeWriteToArrayCodeNoTag(nType, pAttribute->getRepeatFlag(), true/*pAttribute->getRefFlag()*/);
            pFunc->body()->addLine(FormatWstring(L"if (pEnt->get%sCount() > 0)", 
                pAttribute->getName().c_str()
            ));
            CppCode::createBlock(pFunc->body())->addLine(FormatWstring(L"target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(%d, %s, target);",
                nId, 
                L"google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED"
            ))
                    ->addLine(FormatWstring(L"target = ::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->get%sCount(), target);",
                        pAttribute->getName().c_str()
                    ))
                    ->addLine(FormatWstring(L"for (int i = 0; i < pEnt->get%sCount(); i++)", 
                        pAttribute->getName().c_str()
                    ))
                    ->add((new CBlock(false))->add((new CIndent())
                            ->addLine(FormatWstring((L"target = " + sCode).c_str(), 
                                pAttribute->getName().c_str()
                            ))));
        }
        else
        {
            std::wstring sCode = getTypeWriteToArrayCode(nType, pAttribute->getRepeatFlag(), true/*pAttribute->getRefFlag()*/);
            pFunc->body()->addLine(FormatWstring(L"if (pEnt->has%s())", 
                pAttribute->getName().c_str()
            ));
            CppCode::createBlock(pFunc->body())->addLine(FormatWstring((L"target = " + sCode).c_str(),
                nId, 
                pAttribute->getName().c_str()
            ));
        }
        pFunc->body()->addLine(L"");
    }
    pFunc->body()->addLine(L"return target;");
}

void CCodeWriter::addParseField1(CClass *pTypeObject, CppClass* pClass)
{
    CFunction* pFunc = pClass->addFunc(AT_PROTECTED, L"gfc::engine::EnParseFieldState", L"parseField", false, true);
    pFunc->addParam(L"google::protobuf::io::CodedInputStream*", L"input");
    pFunc->addParam(L"int", L"nFieldNum");
    pFunc->addParam(L"gfc::engine::CEntity*", L"pEntity");

    pFunc->body()->addLine(L"#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure", true);
    pFunc->body()->addLine(FormatWstring(L"%s* pEnt = (%s*)pEntity;", 
        pTypeObject->getName().c_str(),
        pTypeObject->getName().c_str()
    ));

    pFunc->body()->addLine(FormatWstring(L"gfc::engine::EnParseFieldState nState = %s::parseField(input, nFieldNum, pEnt);", 
        (getParentClassCode(pTypeObject) + L"BinarySerializer").c_str()
    ));
    pFunc->body()->addLine(L"if (nState != gfc::engine::PFS_IGNORE)");
    CppCode::createBlock(pFunc->body())->addLine(L"return nState;");
    pFunc->body()->addLine(L"");

    std::wstring sName = pTypeObject->getName();
    int nCount = pTypeObject->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttrib = pTypeObject->getAttribute(i);
        EnBaseType nType = getBaseType(pAttrib->getType());
        std::wstring sCode = getTypeReadCode(nType, true/*pAttrib->getRefFlag()*/);
        pFunc->body()->addLine(FormatWstring(L"if (nFieldNum == _FieldCache->_%s_%s)", 
            sName.c_str(),
            pAttrib->getName().c_str()
        ));
        CppCode* pBlock = CppCode::createBlock(pFunc->body());

        if (pAttrib->getRepeatFlag())
        {
            pBlock->addLine(L"int nSize = 0;");
            pBlock->addLine(L"DO_((google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>(input, &nSize)));");
            pBlock->addLine(L"for(int i = 0; i < nSize; ++i)");
            CppCode* pBlock2 = CppCode::createBlock(pBlock);
            if (nType == EBT_STRING)
                pBlock2->addLine(L"std::string value;");
            else
                pBlock2->addLine(FormatWstring(L"%s value;", 
                    getStoreTypeCode(pAttrib->getType(), true/*pAttrib->getRefFlag()*/).c_str()
                ));
            pBlock2->addLine(FormatWstring((L"DO_((" + sCode + L"));").c_str(), L"value"));
//             if (nType == EBT_STRING)
//                 pBlock2->addLine(QString("pEnt->add%1(value);").arg(pAttrib->getName()));
//             else
            pBlock2->addLine(FormatWstring(L"pEnt->add%s(value);", 
                pAttrib->getName().c_str()
            ));
            pBlock->addLine(L"goto success;");
        }
        else
        {
            if (nType == EBT_STRING)
            {
                pBlock->addLine(L"std::string value;");
                pBlock->addLine(FormatWstring((L"DO_((" + sCode + L"));").c_str(),
                    L"value"));
                pBlock->addLine(FormatWstring(L"pEnt->set%s(value);", 
                    pAttrib->getName().c_str()
                ));
            }
            else
            {
                pBlock->addLine(FormatWstring(L"%s value;", 
                    getStoreTypeCode(pAttrib->getType(), true).c_str()
                ));
                pBlock->addLine(FormatWstring((L"DO_((" + sCode + L"));").c_str(), 
                    L"value"
                ));
                           //.arg(/*pAttrib->getRefFlag() ? */getClassFieldCode(pAttrib)/* : "mutable_" + pAttrib->getName() + "()"*/));
                pBlock->addLine(FormatWstring(L"pEnt->set%s(value);", 
                    pAttrib->getName().c_str()
                ));
            }
            pBlock->addLine(L"goto success;");
        }
        pFunc->body()->addLine(L"");
    }
    pFunc->body()->addLine(L"return gfc::engine::PFS_IGNORE;");
    pFunc->body()->addLine(L"success:", true);
    pFunc->body()->addLine(L"return gfc::engine::PFS_SUCCESS;");
    pFunc->body()->addLine(L"failure:", true);
    pFunc->body()->addLine(L"return gfc::engine::PFS_FAIL;");
    pFunc->body()->addLine(L"#undef DO_", true);
}

void CCodeWriter::addSerializeFunc(CClass *pTypeObject, CppClass* pClass)
{
    CFunction* pFunc = pClass->addFunc(AT_PUBLIC, L"std::string", L"serialize", true, true);
    pFunc->addParam(L"gfc::engine::CEntity*", L"pEntity");

    pFunc->body()->addLine(FormatWstring(L"%s* pEnt = (%s*)pEntity;", 
        pTypeObject->getName().c_str(),
        pTypeObject->getName().c_str()
    ));
    pFunc->body()->addLine(FormatWstring(L"std::string sResult = %s::serialize(pEnt);", 
        (getParentClassCode(pTypeObject) + L"TextSerializer").c_str()
    ));
    pFunc->body()->addLine(L"");

	// 定义流化的字符串
	pFunc->body()->addLine(L"std::stringstream stream;");
	pFunc->body()->addLine(L"stream.precision(numeric_limits<double>::digits10);");


    int nCount = pTypeObject->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        EnBaseType nType = getBaseType(pAttribute->getType());
        std::wstring sBaseType = pAttribute->getType()->getBaseType()->getName();
        if (pAttribute->getRepeatFlag())
        {
            std::wstring sCode = getTypeWriteTextCode(nType, pAttribute->getName(), sBaseType, true);

            CppCode::createBlock(pFunc->body())
					->addLine(L"stream<<\",(\";")
					->addLine(FormatWstring(L"for (int i = 0; i < pEnt->get%sCount(); i++)",
                        pAttribute->getName().c_str()
                    ))
					->add((new CBlock(false))
					->add((new CIndent())->addLine(L"if(0==i)")
					->add((new CIndent())->addLine((sCode + L";").erase(sCode.find(L','),1))))
					->add((new CIndent())->addLine(L"else")
                    ->add((new CIndent())->addLine(sCode + L";"))))
					->addLine(L"stream<<\")\";");
        }
        else
        {
            pFunc->body()->addLine(FormatWstring(L"if (pEnt->has%s())", 
                pAttribute->getName().c_str()
            ));
			CppCode::createIndent(pFunc->body())->addLine(getTypeWriteTextCode(nType, pAttribute->getName(), sBaseType, false) + L";");
            pFunc->body()->addLine(L"else");
			CppCode::createIndent(pFunc->body())->addLine(L"stream<<\",$\";");
        }
        pFunc->body()->addLine(L"");
    }
	pFunc->body()->addLine(L"sResult += stream.str();");
    pFunc->body()->addLine(L"if(sResult[0] == ',')");
    CppCode::createIndent(pFunc->body())->addLine(L"sResult = sResult.substr(1,sResult.length() - 1);");
	pFunc->body()->addLine(L"return sResult;");

}

void CCodeWriter::addParseField2(CClass *pTypeObject, CppClass* pClass)
{
    CFunction* pFunc = pClass->addFunc(AT_PROTECTED, L"gfc::engine::EnParseFieldState", L"parseField", false, true);
    pFunc->addParam(L"const std::string&", L"input");
    pFunc->addParam(L"int", L"nFieldNum");
    pFunc->addParam(L"gfc::engine::CEntity*", L"pEntity");

    pFunc->body()->addLine(L"#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure", true);
    pFunc->body()->addLine(FormatWstring(L"%s* pEnt = (%s*)pEntity;",
        pTypeObject->getName().c_str(),
        pTypeObject->getName().c_str()
    ));
    pFunc->body()->addLine(FormatWstring(L"gfc::engine::EnParseFieldState nState = %s::parseField(input, nFieldNum, pEnt);", 
        (getParentClassCode(pTypeObject) + L"TextSerializer").c_str()
    ));
    pFunc->body()->addLine(L"if (nState != gfc::engine::PFS_IGNORE)");
    CppCode::createBlock(pFunc->body())->addLine(L"return nState;");
    pFunc->body()->addLine(L"");

    int nIndexCount = getAttributeIndex(pTypeObject, 0);
    pFunc->body()->addLine(L"switch(nFieldNum)");
    CppCode* pBlock = CppCode::createBlockOnly(pFunc->body());
    int nCount = pTypeObject->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttrib = pTypeObject->getAttribute(i);
        EnBaseType nType = getBaseType(pAttrib->getType());
        std::wstring sCode = getTypeTextReadCode(nType, pAttrib->getType()->getBaseType()->getName());

        pBlock->addLine(FormatWstring(L"case %d:", 
            nIndexCount+i
        ));
        CppCode* pIndent = CppCode::createIndent(pBlock);

        CppCode* pBlock2 = CppCode::createBlock(pIndent);
        if (pAttrib->getRepeatFlag())
        {
            pBlock2->addLine(FormatWstring(L"%s value;", 
                getStoreTypeCode(pAttrib->getType(), true).c_str()
            ));
            pBlock2->addLine(FormatWstring(L"DO_((" + sCode + L"));", L"value"));
            pBlock2->addLine(FormatWstring(L"pEnt->add%s(value);", 
                pAttrib->getName().c_str()
            ));
        }
        else
        {
            pBlock2->addLine(FormatWstring(L"%s value;", 
                getStoreTypeCode(pAttrib->getType(), true).c_str()
            ));
            pBlock2->addLine(FormatWstring(L"DO_((" + sCode + L"));", 
                L"value"/*getClassFieldCode(pAttrib)*/
            ));
            pBlock2->addLine(FormatWstring(L"pEnt->set%s(value);", 
                pAttrib->getName().c_str()
            ));
        }
        pIndent->addLine(L"break;");
    }
    pBlock->addLine(L"default:");
    CppCode::createIndent(pBlock)->addLine(L"return gfc::engine::PFS_IGNORE;");
    //oStream << L"success:\n";
    pFunc->body()->addLine(L"return gfc::engine::PFS_SUCCESS;");
    pFunc->body()->addLine(L"failure:", true);
    pFunc->body()->addLine(L"return gfc::engine::PFS_FAIL;");
    pFunc->body()->addLine(L"#undef DO_", true);
}

void CCodeWriter::addTypeIdFunc(CppClass* pClass, int nTypeId)
{
    CFunction* pFunc = pClass->addFunc(AT_PUBLIC, L"int", L"typeId");
    pFunc->setIsConst(true);
    pFunc->body()->addLine(FormatWstring(L"return %d;", 
        nTypeId
    ));
}

void CCodeWriter::addCreateSchemaFunc(CClass *pTypeObject, CppClass* pClass, int nTypeId)
{
    std::wstring sName = pTypeObject->getName();
    CFunction* pFunc = pClass->addFunc(AT_PUBLIC, L"gfc::engine::EntitySchema*", L"createSchema", true, true);
    pFunc->body()->addLine(FormatWstring(L"if (gfc::engine::EntitySchema* pSchema = m_pDocument->findSchemaByID(%d))", 
        nTypeId
    ));
    pFunc->body()->addLine(L"    return pSchema;");
    pFunc->body()->addLine(L"");
    pFunc->body()->addLine(L"gfc::engine::EntitySchema* pSchema = new gfc::engine::EntitySchema();");
    pFunc->body()->addLine(FormatWstring(L"pSchema->setParent(%s::createSchema());", 
        getParentClassCode(pTypeObject).c_str()
    ));
    pFunc->body()->addLine(FormatWstring(L"pSchema->setName(\"%s\");", 
        sName.c_str()
    ));
    pFunc->body()->addLine(FormatWstring(L"pSchema->setId(%d);", 
        nTypeId
    ));
    pFunc->body()->addLine(FormatWstring(L"m_pDocument->addSchema(pSchema, %d);", 
        nTypeId
    ));
    pFunc->body()->addLine(L"");

    int nCount = pTypeObject->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttrib = pTypeObject->getAttribute(i);
        pFunc->body()->addLine(FormatWstring(L"pSchema->addAttribNames(\"%s\");", 
            pAttrib->getName().c_str()
        ));
        pFunc->body()->addLine(FormatWstring(L"pSchema->addAttribIds(%d);", 
            getAttributeIndex(pTypeObject, i) + 1
        ));
        pFunc->body()->addLine(L"");
    }
    pFunc->body()->addLine(L"return pSchema;");
}

CppClass *CCodeWriter::createCppClass(CClass *pTypeObject, int nTypeId)
{
    std::wstring sName = pTypeObject->getName();
    CppClass* pClass = new CppClass(sName, AT_PUBLIC, getParentClassCode(pTypeObject));
    pClass->setExportFlag(L"GFCCLASSES_API");
    pClass->setMarcoCode(FormatWstring(L"GFCENGINE_DEC_OBJECT(%s, gfc::engine::CEntity)", 
        sName.c_str()
    ));
//    CFunction* pFunc = NULL;

    //if (hasConstructor(pTypeObject))
    {
        addConstructor(pTypeObject, pClass);
    }
    int nCount = pTypeObject->getAttributeCount();
    if (nCount > 0)
    {
        //addByteSizeFunc(pTypeObject, pClass);
        //addIsInitializedFunc(pTypeObject, pClass);

        //addSerializeFunc(pTypeObject, pClass);

        //addSerializeWithCachedSizesFunc(pTypeObject, pClass);
        //addSerializeWithCachedSizesToArrayFunc(pTypeObject, pClass);
        //addParseField1(pTypeObject, pClass);
        //addParseField2(pTypeObject, pClass);
    }

    //addTypeIdFunc(pClass, nTypeId);
    //addCreateSchemaFunc(pTypeObject, pClass, nTypeId);
    //addEntityNameFunc(pTypeObject, pClass);

    // attribute
    for (int i = 0; i < nCount; ++i)
    {
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        if (pAttribute->getRepeatFlag())
            initRepeatAttributeCode(pTypeObject, i, pAttribute, pClass);
        else
            initAttributeCode(pTypeObject, i, pClass);
    }
    // bit
    //if (!pTypeObject->getParent())
    //{
    //    //_has_bits put in root class
    //    int nMax = getMaxAttributeCount(pTypeObject);
    //    pClass->addData(AT_PROTECTED, L"unsigned", FormatWstring(L"_has_bits_[%d]", 
    //        nMax / 32 + 1
    //    ));
    //}

    return pClass;
}

CppClass *CCodeWriter::createCppCliClass(CClass *pTypeObject, int nTypeId)
{
    std::wstring sName = pTypeObject->getName();
    CppClass* pClass = new CppClass(L"N" + sName, AT_PUBLIC, getParentClassCode(pTypeObject, true));

    //if (hasConstructor(pTypeObject))
    {
        addCliConstructor1(pTypeObject, pClass);
        addCliConstructor2(pTypeObject, pClass);
    }
    int nCount = pTypeObject->getAttributeCount();
//    if (nCount > 0)
//    {
//        addIsInitializedFunc(pTypeObject, pClass);
//    }

//    addTypeIdFunc(pClass, nTypeId);
//    addCreateSchemaFunc(pTypeObject, pClass, nTypeId);
//    addEntityNameFunc(pTypeObject, pClass);

    // attribute
    for (int i = 0; i < nCount; ++i)
    {
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        if (pAttribute->getRepeatFlag())
            initCliRepeatAttributeCode(pTypeObject, pAttribute, pClass);
        else
            initCliAttributeCode(pTypeObject, i, pClass);
    }
//    // bit
//    if (!pTypeObject->getParent())
//    {
//        //_has_bits put in root class
//        int nMax = getMaxAttributeCount(pTypeObject);
//        pClass->addData(AT_PROTECTED, L"unsigned", FormatWstring("_has_bits_[%1]").arg(nMax / 32 + 1));
//    }

    return pClass;
}

CppClass* CCodeWriter::createFieldCacheClass(CClass* pTypeObject)
{
    std::wstring sName = pTypeObject->getName();
    CppClass* pClass = new CppClass(sName + L"FieldCacheInitializer", AT_PUBLIC, L"gfc::engine::FieldCacheInitializer");
    //pClass->setExportFlag(L"GFCCLASSES_API");
    pClass->setMarcoCode(FormatWstring(L"GFCENGINE_DEC_OBJECT(%sFieldCacheInitializer,gfc::engine::FieldCacheInitializer)", 
        sName.c_str()
    ));
    CFunction* pFunc = pClass->addFunc(AT_PUBLIC, L"void", L"init", false, true);
    pFunc->addParam(L"const std::map<std::string, int>&", L"oFieldIdMap");
    int nCount = pTypeObject->getAttributeCount();
    for (int i = 0; i < nCount; ++i)
    {
        //
        CAttribute* pAttribute = pTypeObject->getAttribute(i);
        pFunc->body()->addLine(FormatWstring(L"_FieldCache->_%s_%s = getFieldId(oFieldIdMap, \"%s::%s\");", 
            sName.c_str(), 
            pAttribute->getName().c_str(),
            sName.c_str(),
            pAttribute->getName().c_str()
        ));
    }
    return pClass;
}

CppClass *CCodeWriter::createTextSerializerClass(CClass *pTypeObject)
{
    std::wstring sName = pTypeObject->getName() + L"TextSerializer";
    CppClass* pClass = new CppClass(sName, AT_PUBLIC, getParentClassCode(pTypeObject) + L"TextSerializer");
    pClass->setMarcoCode(FormatWstring(L"GFCENGINE_DEC_OBJECT(%s,gfc::engine::EntitySerializer)", sName.c_str()));

    int nCount = pTypeObject->getAttributeCount();
    if (nCount > 0)
    {
        addSerializeFunc(pTypeObject, pClass);
        addParseField2(pTypeObject, pClass);
    }

    return pClass;
}

CppClass *CCodeWriter::createBinarySerializerClass(CClass *pTypeObject)
{
    std::wstring sName = pTypeObject->getName() + L"BinarySerializer";
    CppClass* pClass = new CppClass(sName, AT_PUBLIC, getParentClassCode(pTypeObject) + L"BinarySerializer");
    pClass->setMarcoCode(FormatWstring(L"GFCENGINE_DEC_OBJECT(%s,gfc::engine::EntitySerializer)", sName.c_str()));

    int nCount = pTypeObject->getAttributeCount();
    if (nCount > 0)
    {
        addByteSizeFunc(pTypeObject, pClass);
        addSerializeWithCachedSizesFunc(pTypeObject, pClass);
        addSerializeWithCachedSizesToArrayFunc(pTypeObject, pClass);
        addParseField1(pTypeObject, pClass);
    }

    return pClass;
}

std::wstring CCodeWriter::getTypeCode(CTypeObject *pTypeObject, bool b4cli)
{
    assert(pTypeObject);
    if (pTypeObject->getType() == TOE_BUILDIN)
        return getBaseTypeCode(pTypeObject, b4cli);
    else
        if (b4cli /*&& pTypeObject->getType() != TOE_ENUM*/)
            return L"N" + pTypeObject->getName();
        else
            return pTypeObject->getName();
}

std::wstring CCodeWriter::getBaseTypeCode(CTypeObject *pTypeObject, bool b4cli)
{
    assert(pTypeObject);
    if (pTypeObject)
    {
        EnBaseType nType = getBaseType(pTypeObject);
        switch (nType) {
        case EBT_ENTITY:
        case EBT_ENUM:
            return pTypeObject->getName();
        case EBT_STRING:
            if (b4cli )
                return L"String^";
            else
                return L"std::wstring";
        case EBT_INT:
            return L"int";
        case EBT_DOUBLE:
            return L"double";
        case EBT_BOOL:
            return L"bool";
        default:
            assert(false);
        }
    }
    return L"";
}

std::wstring CCodeWriter::getDataTypeName(CTypeObject * pTypeObject)
{
    switch (pTypeObject->getDataType())
    {
    case EDT_BOOLEAN: return L"Boolean";
    case EDT_INTEGER: return L"Integer";
    case EDT_DOUBLE: return L"Double";
    case EDT_STRING: return L"String";
    case EDT_ENUM: return L"Integer";
    case EDT_ENTITY: return L"EntityRef";
    default:
        assert(false);
        break;
    }
    return std::wstring();
}

std::wstring CCodeWriter::getStoreTypeCode(CTypeObject *pTypeObject, bool bIsRef, bool b4cli)
{
    assert(pTypeObject);
    if (getBaseType(pTypeObject) == EBT_ENTITY && bIsRef)
        return L"gfc::engine::EntityRef";
    else
        return getTypeCode(pTypeObject, b4cli);
}

EnBaseType CCodeWriter::getBaseType(CTypeObject *pTypeObject)
{
    assert(pTypeObject);
    switch (pTypeObject->getType()) {
    case TOE_BUILDIN:
        if (pTypeObject->getName().compare(L"REAL") == 0)
            return EBT_DOUBLE;

        if (pTypeObject->getName().compare(L"STRING") == 0)
            return EBT_STRING;

        if (pTypeObject->getName().compare(L"INTEGER") == 0)
            return EBT_INT;

        if (pTypeObject->getName().compare(L"BOOLEAN") == 0)
            return EBT_BOOL;

        assert(false);
        break;
    case TOE_TYPE:
    {
        CTypeDef* pTypedef = dynamic_cast<CTypeDef*>(pTypeObject);
        assert(pTypedef);
        return getBaseType(pTypedef->getRefType());
    }
    case TOE_ENUM:
        return EBT_ENUM;
    case TOE_CLASS:
        return EBT_ENTITY;
    default:
        assert(false);
    }
    return EBT_ENTITY;
}

std::wstring CCodeWriter::getBaseTypePrefix(EnBaseType nType, bool bIsRefType)
{
    std::wstring sResult = L"n";
    switch (nType) {
    case EBT_ENTITY:
        if (bIsRefType)
            sResult = L"n";
        else
            sResult = L"p";
        break;
    case EBT_STRING:
        sResult = L"s";
        break;
    case EBT_ENUM:
    case EBT_INT:
        sResult = L"n";
        break;
    case EBT_DOUBLE:
        sResult = L"d";
        break;
    case EBT_BOOL:
        sResult = L"b";
        break;
    default:
        assert(false);
    }
    return sResult;
}

std::wstring CCodeWriter::getTypeDefaultValue(EnBaseType nType, const std::wstring &sTypeName, bool bIsRef)
{
    std::wstring sResult = L"0";
    switch (nType) {
    case EBT_ENTITY:
        if (bIsRef)
            sResult = L"0";
        else
            sResult = L"NULL";
        break;
    case EBT_STRING:
        sResult = L"";
        break;
    case EBT_ENUM:
        sResult = FormatWstring(L"(%s)0", sTypeName.c_str());
        break;
    case EBT_INT:
        sResult = L"0";
        break;
    case EBT_DOUBLE:
        sResult = L"0.0";
        break;
    case EBT_BOOL:
        sResult = L"false";
        break;
    default:
        assert(false);
    }
    return sResult;
}

int CCodeWriter::getAttributeIndex(CClass *pTypeObject, int nIndex)
{
    int nCount = 0;
    CClass* pParent = pTypeObject->getParent();
    while(pParent)
    {
        nCount += pParent->getAttributeCount();
        pParent = pParent->getParent();
    }
    return nCount + nIndex;
}

int CCodeWriter::getMaxAttributeCount(CClass *pTypeObject)
{
    int nCount = pTypeObject->getChildCount();
    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        nMax = std::max(nMax, getMaxAttributeCount(pTypeObject->getChild(i)));
    }
    return nMax + pTypeObject->getAttributeCount();
}

void CCodeWriter::initRepeatAttributeCode(CClass* pTypeObject, int nAttributeIndex, CAttribute *pAttribute, CppClass *pClass)
{
    EnBaseType nType = getBaseType(pAttribute->getType());
    int nIndex = getAttributeIndex(pTypeObject, nAttributeIndex);
    std::wstring sAttributeName = pAttribute->getName();
    std::wstring sTypeName = getStoreTypeCode(pAttribute->getType(), true/*pAttribute->getRefFlag()*/);
    std::wstring sPrefix = getBaseTypePrefix(nType, true/*pAttribute->getRefFlag()*/);
    CFunction* pFunc = NULL;
    //
    pFunc = pClass->addFunc(AT_PUBLIC, L"int", FormatWstring(L"get%sCount", sAttributeName.c_str()));
    pFunc->setIsConst(true);
    pFunc->setIsInline(false);
    pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
    pFunc->body()->addLine(L"assert(pProp);");
    pFunc->body()->addLine(L"return pProp->value()->getCount();");

    pFunc = pClass->addFunc(AT_PUBLIC, L"void", L"clear"+ sAttributeName);
    pFunc->setIsInline(false);
    pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
    pFunc->body()->addLine(L"assert(pProp);");
    pFunc->body()->addLine(L"pProp->value()->clear();");

    pFunc = pClass->addFunc(AT_PUBLIC, L"void", L"add" + sAttributeName);
    pFunc->setIsInline(false);
    pFunc->addParam(FormatWstring(L"const %s&", sTypeName.c_str()), sPrefix + L"Value");
    pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
    pFunc->body()->addLine(L"assert(pProp);");
    pFunc->body()->addLine(FormatWstring(L"pProp->value()->add(new gfc::engine::C%sValue(%sValue));", 
        getDataTypeName(pAttribute->getType()).c_str(),
        sPrefix.c_str()));

    pFunc = pClass->addFunc(AT_PUBLIC, sTypeName, L"get" + sAttributeName);
    pFunc->setIsConst(true);
    pFunc->setIsInline(false);
    pFunc->addParam(L"int", L"nIndex");
    pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
    pFunc->body()->addLine(L"assert(pProp);");
    pFunc->body()->addLine(L"auto pValue = pProp->value()->getItems(nIndex);");
    pFunc->body()->addLine(L"assert(pValue);");
    if (nType == EBT_ENUM)
        pFunc->body()->addLine(FormatWstring(L"return (%s)pValue->as%s();",
            sTypeName.c_str(),
            getDataTypeName(pAttribute->getType()).c_str()));
    else
        pFunc->body()->addLine(FormatWstring(L"return pValue->as%s();",
            getDataTypeName(pAttribute->getType()).c_str()));

    if (nType == EBT_ENTITY)
    {
        std::wstring sType = pAttribute->getType()->getName();
        pFunc = pClass->addFunc(AT_PUBLIC, L"std::shared_ptr<" + sType + L">", FormatWstring(L"get%sPtr", sAttributeName.c_str()));
        pFunc->setIsConst(false);
        pFunc->setIsInline(false);
        pFunc->addParam(L"int", L"nIndex");
        pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
        pFunc->body()->addLine(L"assert(pProp);");
        pFunc->body()->addLine(L"auto pValue = pProp->value()->getItems(nIndex);");
        pFunc->body()->addLine(L"assert(pValue);");
        pFunc->body()->addLine(FormatWstring(L"return std::dynamic_pointer_cast<%s>(getContainer()->getEntity(pValue->asEntityRef()));", sType.c_str()));
    }
    //pClass->addData(AT_PRIVATE, FormatWstring(L"std::vector<%s>", sTypeName.c_str()), L"m_o" + sAttributeName);
}

void CCodeWriter::initCliRepeatAttributeCode(CClass* pTypeObject, CAttribute *pAttribute, CppClass *pClass)
{
    EnBaseType nType = getBaseType(pAttribute->getType());
    std::wstring sAttributeName = pAttribute->getName();
    std::wstring sTypeName = getStoreTypeCode(pAttribute->getType(), true/*pAttribute->getRefFlag()*/, true);
    std::wstring sPrefix = getBaseTypePrefix(nType, true/*pAttribute->getRefFlag()*/);
    CFunction* pFunc = NULL;
    //
    pFunc = pClass->addFunc(AT_PUBLIC, L"int", FormatWstring(L"get%sCount", sAttributeName.c_str()));
    //pFunc->setIsConst(true);
    //pFunc->setIsInline(true);
    pFunc->body()->addLine(FormatWstring(L"return ((%s*)m_pEntity)->%s();",
        pTypeObject->getName().c_str(), 
        pFunc->name().c_str()
    ));

    pFunc = pClass->addFunc(AT_PUBLIC, L"void", L"clear"+ sAttributeName);
    //pFunc->setIsInline(true);
    pFunc->body()->addLine(FormatWstring(L"((%s*)m_pEntity)->%s();",
        pTypeObject->getName().c_str(),
        pFunc->name().c_str()
    ));

    pFunc = pClass->addFunc(AT_PUBLIC, L"void", L"add" + sAttributeName);
    //pFunc->setIsInline(true);
    pFunc->addParam(sTypeName, sPrefix + L"Value");
    if(nType == EBT_STRING)
        pFunc->body()->addLine(FormatWstring(L"((%s*)m_pEntity)->%s(marshal_as<std::string>(%s));", 
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str(),
            pFunc->params(0)->name().c_str()
        ));
    else if (nType == EBT_ENUM)
        pFunc->body()->addLine(FormatWstring(L"((%s*)m_pEntity)->%s((%s)%s);", 
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str(), 
            pAttribute->getType()->getName().c_str(), 
            pFunc->params(0)->name().c_str()
        ));
    else
        pFunc->body()->addLine(FormatWstring(L"((%s*)m_pEntity)->%s(%s);", 
            pTypeObject->getName().c_str(),
            pFunc->name().c_str(),
            pFunc->params(0)->name().c_str()
        ));

    pFunc = pClass->addFunc(AT_PUBLIC, sTypeName, L"get" + sAttributeName);
    //pFunc->setIsConst(true);
    //pFunc->setIsInline(true);
    pFunc->addParam(L"int", L"nIndex");
    if(nType == EBT_STRING)
        pFunc->body()->addLine(FormatWstring(L"return marshal_as<String^>(((%s*)m_pEntity)->%s(%s));",
            pTypeObject->getName().c_str(),
            pFunc->name().c_str(), 
            pFunc->params(0)->name().c_str()
        ));
    else if(nType == EBT_ENUM)
        pFunc->body()->addLine(FormatWstring(L"return (%s)((%s*)m_pEntity)->%s(%s);", 
            sTypeName.c_str(), 
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str(),
            pFunc->params(0)->name().c_str()
        ));
    else
        pFunc->body()->addLine(FormatWstring(L"return ((%s*)m_pEntity)->%s(%s);",
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str(), 
            pFunc->params(0)->name().c_str()
        ));

    if (nType == EBT_ENTITY)
    {
        std::wstring sType = pAttribute->getType()->getName();
        pFunc = pClass->addFunc(AT_PUBLIC, L"N" + sType + L"^", FormatWstring(L"get%sPtr", sAttributeName.c_str()));
        //pFunc->setIsConst(true);
        //pFunc->setIsInline(true);
        pFunc->addParam(L"int", L"nIndex");
        pFunc->body()->addLine(FormatWstring(L"return gcnew %s(((%s*)m_pEntity)->%s(%s), false);",
            (L"N" + sType).c_str(),
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str(),
            pFunc->params(0)->name().c_str()
        ));
    }
}

void CCodeWriter::initAttributeCode(CClass *pTypeObject, int nAttributeIndex, CppClass *pClass)
{
    CAttribute* pAttribute = pTypeObject->getAttribute(nAttributeIndex);
    int nIndex = getAttributeIndex(pTypeObject, nAttributeIndex);
    int n = nIndex / 32;
    int m = 1 << (nIndex % 32);
    EnBaseType nType = getBaseType(pAttribute->getType());
    std::wstring sAttributeName = pAttribute->getName();
    std::wstring sTypeName = getStoreTypeCode(pAttribute->getType(), true/*pAttribute->getRefFlag()*/);
    std::wstring sPrefix = getBaseTypePrefix(nType, true/*pAttribute->getRefFlag()*/);

    CFunction* pFunc = NULL;
    //
    pFunc = pClass->addFunc(AT_PUBLIC, L"void", L"set" + sAttributeName);
    pFunc->setIsInline(false);
    pFunc->addParam(L"const " + sTypeName + L"&", sPrefix + L"Value");
    pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
    pFunc->body()->addLine(L"assert(pProp);");
    pFunc->body()->addLine(FormatWstring(L"pProp->value()->setAs%s(%sValue);", getDataTypeName(pAttribute->getType()).c_str(), sPrefix.c_str()));
    //    pFunc->body()->addLine(FormatWstring(L"m_%s%s = %sValue;", sPrefix.c_str(), sAttributeName.c_str(), sPrefix.c_str()));
//    pFunc->body()->addLine(FormatWstring(L"setHas%s();", sAttributeName.c_str()));
    //
    pFunc = pClass->addFunc(AT_PUBLIC, sTypeName, L"get" + sAttributeName);
    pFunc->setIsConst(true);
    pFunc->setIsInline(false);
    pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
    pFunc->body()->addLine(L"assert(pProp);");
    if (nType == EBT_ENUM)
        pFunc->body()->addLine(FormatWstring(L"return (%s)pProp->value()->as%s();", sTypeName.c_str(), getDataTypeName(pAttribute->getType()).c_str()));
    else
        pFunc->body()->addLine(FormatWstring(L"return pProp->value()->as%s();", getDataTypeName(pAttribute->getType()).c_str()));

    //
    pFunc = pClass->addFunc(AT_PUBLIC, L"bool", L"has" + sAttributeName);
    pFunc->setIsConst(true);
    pFunc->setIsInline(false);
    pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
    pFunc->body()->addLine(L"assert(pProp);");
    pFunc->body()->addLine(L"return !pProp->value()->isNull();");

    //pClass->addData(AT_PRIVATE, sTypeName, FormatWstring(L"m_%s%s", sPrefix.c_str(), sAttributeName.c_str()));

    if (nType == EBT_ENTITY)
    {
        std::wstring sType = pAttribute->getType()->getName();
        pFunc = pClass->addFunc(AT_PUBLIC, L"std::shared_ptr<" + sType + L">", L"get" + sAttributeName + L"Ptr");
        pFunc->setIsConst(false);
        pFunc->setIsInline(false);
        pFunc->body()->addLine(FormatWstring(L"auto pProp = this->getProps(%d);", nIndex));
        pFunc->body()->addLine(L"assert(pProp);");
        pFunc->body()->addLine(FormatWstring(L"return std::dynamic_pointer_cast<%s>(getContainer()->getEntity(pProp->value()->asEntityRef()));", sType.c_str()));
    }
}

void CCodeWriter::initCliAttributeCode(CClass *pTypeObject, int nAttributeIndex, CppClass *pClass)
{
    CAttribute* pAttribute = pTypeObject->getAttribute(nAttributeIndex);
    //int nIndex = getAttributeIndex(pTypeObject, nAttributeIndex);
    //int n = nIndex / 32;
    //int m = 1 << (nIndex % 32);
    EnBaseType nType = getBaseType(pAttribute->getType());
    std::wstring sAttributeName = pAttribute->getName();
    std::wstring sTypeName = getStoreTypeCode(pAttribute->getType(), true/*pAttribute->getRefFlag()*/, true);
    std::wstring sPrefix = getBaseTypePrefix(nType, true/*pAttribute->getRefFlag()*/);

    CFunction* pFunc = NULL;
    //
    pFunc = pClass->addFunc(AT_PUBLIC, L"void", L"set" + sAttributeName);
    //pFunc->setIsInline(true);
    pFunc->addParam(/*"const " + */sTypeName/* + "&"*/, sPrefix + L"Value");
    if (nType == EBT_STRING)
        pFunc->body()->addLine(FormatWstring(L"((%s*)m_pEntity)->%s(marshal_as<std::string>(%s));",
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str(), 
            pFunc->params(0)->name().c_str()
        ));
    else if (nType == EBT_ENUM)
        pFunc->body()->addLine(FormatWstring(L"((%s*)m_pEntity)->%s((%s)%s);", 
            pTypeObject->getName().c_str(),
            pFunc->name().c_str(), 
            pAttribute->getType()->getName().c_str(), 
            pFunc->params(0)->name().c_str()
        ));
    else
        pFunc->body()->addLine(FormatWstring(L"((%s*)m_pEntity)->%s(%s);", 
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str(), 
            pFunc->params(0)->name().c_str()
        ));
    //
    pFunc = pClass->addFunc(AT_PUBLIC, sTypeName, L"get" + sAttributeName);
    //pFunc->setIsConst(true);
    //pFunc->setIsInline(true);
    if (nType == EBT_STRING)
        pFunc->body()->addLine(FormatWstring(L"return marshal_as<String^>(((%s*)m_pEntity)->%s());",
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str()
        ));
    else if (nType == EBT_ENUM)
        pFunc->body()->addLine(FormatWstring(L"return (%s)((%s*)m_pEntity)->%s();",
            sTypeName.c_str(), 
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str()
        ));
    else
        pFunc->body()->addLine(FormatWstring(L"return ((%s*)m_pEntity)->%s();", 
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str()
        ));
    //
    pFunc = pClass->addFunc(AT_PUBLIC, L"bool", L"has" + sAttributeName);
    //pFunc->setIsConst(true);
    //pFunc->setIsInline(true);
    pFunc->body()->addLine(FormatWstring(L"return ((%s*)m_pEntity)->%s();", 
        pTypeObject->getName().c_str(), 
        pFunc->name().c_str()
    ));

//    pFunc = pClass->addFunc(AT_PRIVATE, "void", "setHas" + sAttributeName);
//    pFunc->setIsInline(true);
//    pFunc->body()->addLine(QString(L"((%1*)m_pEntity)->%2();")
//                           .arg(pTypeObject->getName())
//                           .arg(pFunc->name())
//                           );

    if (nType == EBT_ENTITY)
    {
        std::wstring sType = pAttribute->getType()->getName();
        pFunc = pClass->addFunc(AT_PUBLIC, L"N" + sType + L"^", L"get" + sAttributeName + L"Ptr");
        //pFunc->setIsConst(true);
        //pFunc->setIsInline(true);
        pFunc->body()->addLine(FormatWstring(L"return gcnew %s(((%s*)m_pEntity)->%s(), false);", 
            (L"N" + sType).c_str(), 
            pTypeObject->getName().c_str(), 
            pFunc->name().c_str()
        ));
    }
}

std::wstring CCodeWriter::getClassFieldCode(CAttribute *pAttrib)
{
    std::wstring sResult = L"";
    if (pAttrib)
    {
        EnBaseType nType = getBaseType(pAttrib->getType());
        std::wstring sAttributeName = pAttrib->getName();
        std::wstring sPrefix = getBaseTypePrefix(nType, true/*pAttrib->getRefFlag()*/);
        sResult = FormatWstring(L"m_%s%s", sPrefix.c_str(), sAttributeName.c_str());
    }
    return sResult;
}

std::wstring CCodeWriter::getSizeCode(CAttribute *pAttribute)
{
    std::wstring sResult = L"0";
    std::wstring sIndex = pAttribute->getRepeatFlag() ? L"i" : L"";
    std::wstring sAttributeName = pAttribute->getName();
    EnBaseType nType = getBaseType(pAttribute->getType());
    switch (nType) {
    case EBT_ENTITY:
//        if (!pAttribute->getRefFlag())
//        {
////            sResult = QString(L"::google::protobuf::internal::WireFormatLite::LengthDelimitedSize(this->get%1(%2).byteSize())")
////                    .arg(sAttributeName).arg(sIndex);
//            sResult = QString(L"this->get%1(%2).byteSize()")
//                    .arg(sAttributeName).arg(sIndex);
//            break;
//        }
    case EBT_INT:
        sResult = FormatWstring(L"::google::protobuf::internal::WireFormatLite::Int32Size(pEnt->get%s(%s))", sAttributeName.c_str(), sIndex.c_str());
        break;
    case EBT_STRING:
        sResult = FormatWstring(L"::google::protobuf::internal::WireFormatLite::StringSize(pEnt->get%s(%s))", sAttributeName.c_str(), sIndex.c_str());
        break;
    case EBT_ENUM:
        sResult = FormatWstring(L"::google::protobuf::internal::WireFormatLite::Int32Size((int)pEnt->get%s(%s))", sAttributeName.c_str(), sIndex.c_str());;
        break;
    case EBT_DOUBLE:
        sResult = L"8";
        break;
    case EBT_BOOL:
        sResult = L"1";
        break;
    default:
        assert(false);
    }
    return sResult;

}

std::wstring CCodeWriter::getTypeWriteCode(EnBaseType nType, bool bIsRepeat, bool bIsRef)
{
    std::wstring sResult = L"";
    std::wstring sIndex = bIsRepeat ? L"i" : L"";
    std::wstring sEnd = L"), output);";
    switch (nType) {
    case EBT_ENTITY:
        if (!bIsRef)
        {
            sResult = L"WriteEntityMaybeToArray(%d, pEnt->get%s(";
            break;
        }
    case EBT_INT:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteInt32(%d, pEnt->get%s(";
        break;
    case EBT_STRING:
        if (!bIsRepeat)
            sResult = L"::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(%d, pEnt->get%s(";
        else
            sResult = L"::google::protobuf::internal::WireFormatLite::WriteString(%d, pEnt->get%s(";
		sEnd = L"), output);";
        break;
    case EBT_ENUM:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteInt32(%d, (int)pEnt->get%s(";
        break;
    case EBT_DOUBLE:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteDouble(%d, pEnt->get%s(";
        break;
    case EBT_BOOL:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteBool(%d, pEnt->get%s(";
        break;
    default:
        assert(false);
    }
    return sResult + sIndex + sEnd;
}

std::wstring CCodeWriter::getTypeWriteCodeNoTag(EnBaseType nType, bool bIsRepeat, bool bIsRef)
{
    std::wstring sResult = L"";
    std::wstring sIndex = bIsRepeat ? L"i" : L"";
    std::wstring sEnd = L"), output);";
    switch (nType) {
    case EBT_ENTITY:
        if (!bIsRef)
        {
            sResult = L"WriteEntityMaybeToArrayNoTag(pEnt->get%s(";
            break;
        }
    case EBT_INT:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(pEnt->get%s(";
        break;
    case EBT_STRING:
        sResult = L"WriteStringNoTag(pEnt->get%s(";
        sEnd = L"), output);";
        break;
    case EBT_ENUM:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteInt32NoTag((int)pEnt->get%s(";
        break;
    case EBT_DOUBLE:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteDoubleNoTag(pEnt->get%s(";
        break;
    case EBT_BOOL:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteBoolNoTag(pEnt->get%s(";
        break;
    default:
        assert(false);
    }
    return sResult + sIndex + sEnd;
}

std::wstring CCodeWriter::getTypeWriteTextCode(EnBaseType nType, const std::wstring& sAttributeName, const std::wstring& sAttributeType, bool bIsRepeat)
{
    std::wstring sResult = L"";
    std::wstring sIndex = bIsRepeat ? L"i" : L"";
    std::wstring sEnd = L"(" + sIndex + L")";
    switch (nType) {
    case EBT_ENTITY:
 		sResult = L"stream<<\",#\"<<" + FormatWstring(L"pEnt->get%s", sAttributeName.c_str());
        break;
    case EBT_INT:
		sResult = L"stream<<\",\"<<" + FormatWstring(L"pEnt->get%s", sAttributeName.c_str());
        break;
    case EBT_DOUBLE:
		sResult = L"stream<<\",\"<<" + FormatWstring(L"pEnt->get%s", sAttributeName.c_str());
        break;
    case EBT_STRING:
		sResult = L"stream<<\",'\"<<" + FormatWstring(L"pEnt->get%s", sAttributeName.c_str()) +sEnd + L"<<\"'\"";
		sEnd = L"";
        break;
    case EBT_ENUM:
		sResult = L"stream<<\",\"<<" + FormatWstring(L"%s", sAttributeType.c_str()) + L"ToString(pEnt->get" + sAttributeName;
        sEnd = L"(" + sIndex + L"))";
        break;
    case EBT_BOOL:
        sResult = L"stream<<" + FormatWstring(L"(pEnt->get%s%s ? \",.T.\" : \",.F.\")", sAttributeName.c_str(), (L"(" + sIndex + L")").c_str());
        sEnd = L"";
        break;
    default:
        assert(false);
    }
    return sResult + sEnd;
}

std::wstring CCodeWriter::getTagTypeCode(EnBaseType nType, bool bIsRef)
{
    std::wstring sResult = L"";
    switch (nType) {
    case EBT_ENTITY:
        if (!bIsRef)
        {
            sResult = L"WIRETYPE_LENGTH_DELIMITED";
            break;
        }
    case EBT_INT:
        sResult = L"WIRETYPE_VARINT";
        break;
    case EBT_STRING:
        sResult = L"WIRETYPE_LENGTH_DELIMITED";
        break;
    case EBT_ENUM:
        sResult = L"WIRETYPE_VARINT";
        break;
    case EBT_DOUBLE:
        sResult = L"WIRETYPE_FIXED64";
        break;
    case EBT_BOOL:
        sResult = L"WIRETYPE_VARINT";
        break;
    default:
        assert(false);
    }
    return sResult;
}

std::wstring CCodeWriter::getTypeReadCode(EnBaseType nType, bool bIsRef)
{
    std::wstring sResult = L"";
    std::wstring sEnd = L"(input, &%s)";
    switch (nType) {
    case EBT_ENTITY:
        if (!bIsRef)
        {
            sResult = L"ReadEntityNoVirtual";
            sEnd = L"(input, %s)";
            break;
        }
    case EBT_INT:
        sResult = L"google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>";
        break;
    case EBT_STRING:
        sResult = L"google::protobuf::internal::WireFormatLite::ReadString";
        break;
    case EBT_ENUM:
        sResult = L"google::protobuf::internal::WireFormatLite::ReadPrimitive<google::protobuf::int32, google::protobuf::internal::WireFormatLite::TYPE_INT32>";
        sEnd = L"(input, (google::protobuf::int32*)&%s)";
        break;
    case EBT_DOUBLE:
        sResult = L"google::protobuf::internal::WireFormatLite::ReadPrimitive<double, google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>";
        break;
    case EBT_BOOL:
        sResult = L"google::protobuf::internal::WireFormatLite::ReadPrimitive<bool, google::protobuf::internal::WireFormatLite::TYPE_BOOL>";
        break;
    default:
        assert(false);
    }
    return sResult + sEnd;
}

std::wstring CCodeWriter::getTypeTextReadCode(EnBaseType nType, const std::wstring &sAttributeType)
{
    std::wstring sResult = L"";
    std::wstring sEnd = L"(input, %s)";
    switch (nType) {
    case EBT_ENTITY:
        sResult = L"readEntityField";
        break;
    case EBT_INT:
        sResult = L"readIntField";
        break;
    case EBT_STRING:
        sResult = L"readStringField";
        break;
    case EBT_ENUM:
        sResult = L"StringTo" + sAttributeType;
        break;
    case EBT_DOUBLE:
        sResult = L"readFloatField";
        break;
    case EBT_BOOL:
        sResult = L"readBooleanField";
        break;
    default:
        assert(false);
    }
    return sResult + sEnd;
}

std::wstring CCodeWriter::getTypeWriteToArrayCode(EnBaseType nType, bool bIsRepeat, bool bIsRef)
{
    std::wstring sResult = L"";
    std::wstring sIndex = bIsRepeat ? L"i" : L"";
    std::wstring sEnd = L"), target);";
    switch (nType) {
    case EBT_ENTITY:
        if (!bIsRef)
        {
            sResult = L"WriteEntityNoVirtualToArray(%d, pEnt->get%s(";
            break;
        }
    case EBT_INT:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(%d, pEnt->get%s(";
        break;
    case EBT_STRING:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteStringToArray(%d, pEnt->get%s(";
        sEnd = L"), target);";
        break;
    case EBT_ENUM:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(%d, (int)pEnt->get%s(";
        break;
    case EBT_DOUBLE:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(%d, pEnt->get%s(";
        break;
    case EBT_BOOL:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteBoolToArray(%d, pEnt->get%s(";
        break;
    default:
        assert(false);
    }
    return sResult + sIndex + sEnd;
}

std::wstring CCodeWriter::getTypeWriteToArrayCodeNoTag(EnBaseType nType, bool bIsRepeat, bool bIsRef)
{
    std::wstring sResult = L"";
    std::wstring sIndex = bIsRepeat ? L"i" : L"";
    std::wstring sEnd = L"), target);";
    switch (nType) {
    case EBT_ENTITY:
        if (!bIsRef)
        {
            sResult = L"WriteEntityNoVirtualNoTagToArray(pEnt->get%s(";
            break;
        }
    case EBT_INT:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray(pEnt->get%s(";
        break;
    case EBT_STRING:
        sResult = L"::google::protobuf::io::CodedOutputStream::WriteStringWithSizeToArray(pEnt->get%s(";
        sEnd = L"), target);";
        break;
    case EBT_ENUM:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteInt32NoTagToArray((int)pEnt->get%s(";
        break;
    case EBT_DOUBLE:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteDoubleNoTagToArray(pEnt->get%s(";
        break;
    case EBT_BOOL:
        sResult = L"::google::protobuf::internal::WireFormatLite::WriteBoolNoTagToArray(pEnt->get%s(";
        break;
    default:
        assert(false);
    }
    return sResult + sIndex + sEnd;
}

std::wstring CCodeWriter::getParentClassCode(CClass *pClass, bool b4cli)
{
    if (pClass->getParent())
        if (b4cli)
            return L"N" + pClass->getParent()->getName();
        else
            return pClass->getParent()->getName();
    else
        if (b4cli)
            return L"glodon::objectbufnet::Entity";
        else
            return L"gfc::engine::CEntity";
}

bool CCodeWriter::hasConstructor(CClass *pTypeObject)
{
    return pTypeObject->getAttributeCount() > 0 || !pTypeObject->getParent();
}

void CCodeWriter::getRequireFlag(CClass *pClass, int& nCount, int& nFlag, std::vector<int> &oFlagList)
{
    if (pClass->getParent())
    {
        getRequireFlag(pClass->getParent(), nCount, nFlag, oFlagList);
    }
    for (int i = 0; i < pClass->getAttributeCount(); ++i)
    {
        CAttribute* pAttribute = pClass->getAttribute(i);
        if (!pAttribute->getRepeatFlag() && !pAttribute->getOptionalFlag())
            nFlag |= 1 << nCount;
        ++nCount;
        if (nCount >= 32)
        {
            oFlagList.push_back(nFlag);
            nFlag = 0;
            nCount = 0;
        }
    }
}

void CCodeWriter::getRequireFlag(CClass *pClass, std::vector<int> &oFlagList)
{
    int nCount = 0;
    int nFlag = 0;
    getRequireFlag(pClass, nCount, nFlag, oFlagList);
    if (nCount > 0)
        oFlagList.push_back(nFlag);
}
