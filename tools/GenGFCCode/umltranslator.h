#ifndef CUMLTRANSLATOR_H
#define CUMLTRANSLATOR_H

#include <string>
#include "SchemaMacro.h"

struct CTranslateInfo
{
    std::wstring sUMLFile;
    std::wstring sHeadPath;
    std::wstring sCPPPath;  // GFC类存放路径
    std::wstring sTextPath; // 文本序列化代码存放路径
    std::wstring sBinPath;  // 二进制序列化代码存放路径
    std::wstring sNETPath;
    std::wstring sExpressFile;
    std::wstring sHtmlPath;
};

GFC_NAMESPACE_BEGIN
class CModel;
GFC_NAMESPACE_END

using namespace gfc2::schema;

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