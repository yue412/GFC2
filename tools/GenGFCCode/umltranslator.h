#ifndef CUMLTRANSLATOR_H
#define CUMLTRANSLATOR_H

#include <string>
#include "GfcSchema/SchemaMacro.h"

struct CTranslateInfo
{
    std::wstring sUMLFile;
    std::wstring sHeadPath;
    std::wstring sCPPPath;  // GFC类存放路径
    //std::wstring sTextPath; // 文本序列化代码存放路径
    //std::wstring sBinPath;  // 二进制序列化代码存放路径
    std::wstring sNETPath;
    std::wstring sExpressFile;
    std::wstring sHtmlPath;
    std::wstring sVersion;
};

GFC_NAMESPACE_BEGIN
class CModel;
GFC_NAMESPACE_END

using namespace gfc::schema;

class CUMLTranslator
{
public:
    CUMLTranslator();
    ~CUMLTranslator();
    void done(CTranslateInfo& oInfo);
private:
    void loadModelData(CModel* pModel, const std::wstring& sFileName);
};

#endif