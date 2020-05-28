#include <assert.h>
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\EntityFactory.h"
#include "Model.h"
#include "Common.h"
#include "Parser.h"
#include "Scanner.h"

GFCENGINE_NAMESPACE_BEGIN

EntityFactory * GfcEngineUtils::createFactory(const std::string & sFileName)
{
    auto pModel = new gfc2::schema::CModel();
    if (loadSchema(sFileName, pModel))
        return new EntityFactory(pModel);
    else {
        delete pModel;
        return nullptr;
    }
}

EntityFactory * GfcEngineUtils::createFactory(const char * buf, int len)
{
    auto pModel = new gfc2::schema::CModel();
    if (loadSchema(buf, len, pModel))
        return new EntityFactory(pModel);
    else {
        delete pModel;
        return nullptr;
    }
}

bool GfcEngineUtils::loadSchema(const std::string & sFileName, gfc2::schema::CModel * pModel)
{
    auto sFile = toWstring(sFileName);
    if (!fileExists(sFile))
        return false;
    std::ifstream in(sFileName, std::ios::in);
    if (in)
    {
        // get length of file:
        in.seekg(0, in.end);
        int length = (int)in.tellg();
        in.seekg(0, in.beg);

        char * buffer = new char[length];

        // read data as a block:
        in.read(buffer, length);
        in.close();

        return loadSchema(buffer, (int)in.gcount(), pModel);
    }
    return false;
}

bool GfcEngineUtils::loadSchema(const char * buf, int len, gfc2::schema::CModel * pModel)
{
    assert(pModel);
    Scanner oScanner((const unsigned char *)buf, len);
    Parser oParser(&oScanner);
    gfc2::schema::CModel oTempModel;
    oParser.m_pModel = pModel;
    oParser.m_pTempModel = &oTempModel;
    try
    {
        oParser.Parse();
    }
    catch (...)
    {
        pModel->clear();
        return false;
    }

    if (oParser.errors->count > 0)
    {
        pModel->clear();
        return false;
    }
    return true;
}

GFCENGINE_NAMESPACE_END
