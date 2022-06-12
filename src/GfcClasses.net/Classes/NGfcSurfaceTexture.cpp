#include "NGfcSurfaceTexture.h"

using namespace gfc::classes::x3;

NGfcSurfaceTexture::NGfcSurfaceTexture()
{
    m_pEntity = new GfcSurfaceTexture;
    m_bOwner = true;
}

NGfcSurfaceTexture::NGfcSurfaceTexture(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcSurfaceTexture::setRepeatS(NGfcBoolean bValue)
{
    ((GfcSurfaceTexture*)m_pEntity)->setRepeatS(bValue);
}

NGfcBoolean NGfcSurfaceTexture::getRepeatS()
{
    return ((GfcSurfaceTexture*)m_pEntity)->getRepeatS();
}

bool NGfcSurfaceTexture::hasRepeatS()
{
    return ((GfcSurfaceTexture*)m_pEntity)->hasRepeatS();
}

void NGfcSurfaceTexture::setRepeatT(NGfcBoolean bValue)
{
    ((GfcSurfaceTexture*)m_pEntity)->setRepeatT(bValue);
}

NGfcBoolean NGfcSurfaceTexture::getRepeatT()
{
    return ((GfcSurfaceTexture*)m_pEntity)->getRepeatT();
}

bool NGfcSurfaceTexture::hasRepeatT()
{
    return ((GfcSurfaceTexture*)m_pEntity)->hasRepeatT();
}

void NGfcSurfaceTexture::setImageFileName(NGfcString sValue)
{
    ((GfcSurfaceTexture*)m_pEntity)->setImageFileName(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSurfaceTexture::getImageFileName()
{
    return marshal_as<String^>(((GfcSurfaceTexture*)m_pEntity)->getImageFileName());
}

bool NGfcSurfaceTexture::hasImageFileName()
{
    return ((GfcSurfaceTexture*)m_pEntity)->hasImageFileName();
}

void NGfcSurfaceTexture::setTranfromsMatirx(gfc::engine::EntityRef nValue)
{
    ((GfcSurfaceTexture*)m_pEntity)->setTranfromsMatirx(nValue);
}

gfc::engine::EntityRef NGfcSurfaceTexture::getTranfromsMatirx()
{
    return ((GfcSurfaceTexture*)m_pEntity)->getTranfromsMatirx();
}

bool NGfcSurfaceTexture::hasTranfromsMatirx()
{
    return ((GfcSurfaceTexture*)m_pEntity)->hasTranfromsMatirx();
}

int NGfcSurfaceTexture::getParameterCount()
{
    return ((GfcSurfaceTexture*)m_pEntity)->getParameterCount();
}

void NGfcSurfaceTexture::clearParameter()
{
    ((GfcSurfaceTexture*)m_pEntity)->clearParameter();
}

void NGfcSurfaceTexture::addParameter(NGfcString sValue)
{
    ((GfcSurfaceTexture*)m_pEntity)->addParameter(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSurfaceTexture::getParameter(int nIndex)
{
    return marshal_as<String^>(((GfcSurfaceTexture*)m_pEntity)->getParameter(nIndex));
}

