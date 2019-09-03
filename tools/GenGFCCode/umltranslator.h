#ifndef CUMLTRANSLATOR_H
#define CUMLTRANSLATOR_H

#include <string>

struct CTranslateInfo
{
    std::wstring sUMLFile;
    std::wstring sHeadPath;
    std::wstring sCPPPath;
    std::wstring sNETPath;
    std::wstring sExpressFile;
};

class CModel;

class CUMLTranslator
{
public:
    CUMLTranslator();
    ~CUMLTranslator();
    void done(CTranslateInfo& oInfo);
private:
    void initModel(CModel* pModel);
    void loadModelData(CModel* pModel, const std::wstring& sFileName);
};

#endif