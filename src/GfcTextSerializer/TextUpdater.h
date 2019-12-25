#ifndef TEXTUPDATER_H
#define TEXTUPDATER_H

#include "SchemaMacro.h"
#include <string>

GFC_NAMESPACE_BEGIN

class CModel;
class CModelCompatibility;
class CClassCompatibility;
class CAttributeValue;

GFC_NAMESPACE_END

namespace glodon {
namespace objectbuf {

class TextUpdater
{
public:
    TextUpdater() : m_pDllModel(nullptr), m_pFileModel(nullptr), m_pModelCompatibility(nullptr) {}
    ~TextUpdater();
    void init(const std::string& sVersion);
    void update(std::string& sLine);
    void setSchemaPath(const std::string& sSchemaPath) { m_sSchemaPath = sSchemaPath; }
    void setRemote(const std::string& sRemote) { m_sRemote = sRemote; }
    // for test
    void transform(gfc2::schema::CClassCompatibility* pClassCompatibility, gfc2::schema::CAttributeValue* pParamList, std::string& sOutput);
private:
    void clear();
    void loadDllModel();
    void loadFileModel(const std::string& sFileSchema);
    gfc2::schema::CModel* m_pDllModel;
    gfc2::schema::CModel* m_pFileModel;
    std::string m_sSchemaPath;
    std::string m_sRemote;
    gfc2::schema::CModelCompatibility* m_pModelCompatibility;
};

}
}

#endif // !TEXTUPDATER_H

