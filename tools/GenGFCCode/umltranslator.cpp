#include "umltranslator.h"
#include "GfcSchema/Model.h"
#include "umlreader.h"
#include "GfcSchema/BuildinType.h"
#include "codewriter.h"
#include "expresswriter.h"
#include <iostream>
#include <windows.h>
#include "common.h"
#include "DocumentWriter.h"

CUMLTranslator::CUMLTranslator()
{
}


CUMLTranslator::~CUMLTranslator()
{
}

void CUMLTranslator::done(CTranslateInfo & oInfo)
{
    std::wstring sCoreUML = getExePath() + L"\\GFC2Core.uml";
    CModel oModel;
    loadModelData(&oModel, oInfo.sUMLFile.empty() ? sCoreUML : oInfo.sUMLFile);
    /*
    CModel* pRefModel = nullptr;
    if (!oInfo.sUMLFile.empty())
    {
        pRefModel = new CModel();
        oModel.setRefModel(pRefModel);
        initModel(pRefModel);
        loadModelData(pRefModel, sCoreUML);
    }
    */

    if (!oInfo.sExpressFile.empty())
    {
        CExpressWriter oWriter(&oModel);
        oWriter.write(oInfo.sExpressFile, L"GFC3X0");
    }
    if (!oInfo.sHtmlPath.empty())
    {
        CDocumentWriter oWriter(&oModel);
        oWriter.write(oInfo.sHtmlPath);
    }
    if (!(oInfo.sCPPPath.empty() && /*oInfo.sTextPath.empty() && oInfo.sBinPath.empty() &&*/ oInfo.sHeadPath.empty() && oInfo.sNETPath.empty()))
    {
        CCodeWriter oCodeWriter(&oModel);
        oCodeWriter.write(oInfo.sHeadPath, 
            oInfo.sCPPPath, 
            //oInfo.sTextPath,
            //oInfo.sBinPath,
            oInfo.sNETPath);
    }
//    delete pRefModel;
    std::wcout << L"生成完成！" << std::endl;
}

void CUMLTranslator::loadModelData(CModel * pModel, const std::wstring & sFileName)
{
    CUMLReader reader(pModel);
    reader.load(sFileName);
}
