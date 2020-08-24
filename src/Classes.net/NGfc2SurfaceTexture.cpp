#include "StdAfx.h"
#include "NGfc2SurfaceTexture.h"
NGfc2SurfaceTexture::NGfc2SurfaceTexture()
{
    m_pEntity = new Gfc2SurfaceTexture;
    m_bOwner = true;
}

NGfc2SurfaceTexture::NGfc2SurfaceTexture(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2SurfaceTexture::setRepeatS(NGfc2Boolean bValue)
{
    ((Gfc2SurfaceTexture*)m_pEntity)->setRepeatS(bValue);
}

NGfc2Boolean NGfc2SurfaceTexture::getRepeatS()
{
    return ((Gfc2SurfaceTexture*)m_pEntity)->getRepeatS();
}

bool NGfc2SurfaceTexture::hasRepeatS()
{
    return ((Gfc2SurfaceTexture*)m_pEntity)->hasRepeatS();
}

void NGfc2SurfaceTexture::setRepeatT(NGfc2Boolean bValue)
{
    ((Gfc2SurfaceTexture*)m_pEntity)->setRepeatT(bValue);
}

NGfc2Boolean NGfc2SurfaceTexture::getRepeatT()
{
    return ((Gfc2SurfaceTexture*)m_pEntity)->getRepeatT();
}

bool NGfc2SurfaceTexture::hasRepeatT()
{
    return ((Gfc2SurfaceTexture*)m_pEntity)->hasRepeatT();
}

void NGfc2SurfaceTexture::setImageFileName(NGfc2String sValue)
{
    ((Gfc2SurfaceTexture*)m_pEntity)->setImageFileName(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2SurfaceTexture::getImageFileName()
{
    return marshal_as<String^>(((Gfc2SurfaceTexture*)m_pEntity)->getImageFileName());
}

bool NGfc2SurfaceTexture::hasImageFileName()
{
    return ((Gfc2SurfaceTexture*)m_pEntity)->hasImageFileName();
}

void NGfc2SurfaceTexture::setTranfromsMatirx(gfc::engine::EntityRef nValue)
{
    ((Gfc2SurfaceTexture*)m_pEntity)->setTranfromsMatirx(nValue);
}

gfc::engine::EntityRef NGfc2SurfaceTexture::getTranfromsMatirx()
{
    return ((Gfc2SurfaceTexture*)m_pEntity)->getTranfromsMatirx();
}

bool NGfc2SurfaceTexture::hasTranfromsMatirx()
{
    return ((Gfc2SurfaceTexture*)m_pEntity)->hasTranfromsMatirx();
}

NGfc2Matrix^ NGfc2SurfaceTexture::getTranfromsMatirxPtr()
{
    return gcnew NGfc2Matrix(((Gfc2SurfaceTexture*)m_pEntity)->getTranfromsMatirxPtr(), false);
}

int NGfc2SurfaceTexture::getParameterCount()
{
    return ((Gfc2SurfaceTexture*)m_pEntity)->getParameterCount();
}

void NGfc2SurfaceTexture::clearParameter()
{
    ((Gfc2SurfaceTexture*)m_pEntity)->clearParameter();
}

void NGfc2SurfaceTexture::addParameter(NGfc2String sValue)
{
    ((Gfc2SurfaceTexture*)m_pEntity)->addParameter(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2SurfaceTexture::getParameter(int nIndex)
{
    return marshal_as<String^>(((Gfc2SurfaceTexture*)m_pEntity)->getParameter(nIndex));
}

