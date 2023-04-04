#include "NGfcSurfaceTexture.h"

using namespace gfc::classes::x3;

NGfcSurfaceTexture::NGfcSurfaceTexture()
{
    m_pEntity = new GfcSurfaceTexture;
    m_bOwner = true;
}

NGfcSurfaceTexture::NGfcSurfaceTexture(bool bNoCreate):
    NGfcRoot(bNoCreate)
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

void NGfcSurfaceTexture::setImageURL(NGfcString sValue)
{
    ((GfcSurfaceTexture*)m_pEntity)->setImageURL(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSurfaceTexture::getImageURL()
{
    return marshal_as<String^>(((GfcSurfaceTexture*)m_pEntity)->getImageURL());
}

bool NGfcSurfaceTexture::hasImageURL()
{
    return ((GfcSurfaceTexture*)m_pEntity)->hasImageURL();
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

void NGfcSurfaceTexture::setTextureType(NGfcTextureType nValue)
{
    ((GfcSurfaceTexture*)m_pEntity)->setTextureType((GfcTextureType)nValue);
}

NGfcTextureType NGfcSurfaceTexture::getTextureType()
{
    return (NGfcTextureType)((GfcSurfaceTexture*)m_pEntity)->getTextureType();
}

bool NGfcSurfaceTexture::hasTextureType()
{
    return ((GfcSurfaceTexture*)m_pEntity)->hasTextureType();
}

