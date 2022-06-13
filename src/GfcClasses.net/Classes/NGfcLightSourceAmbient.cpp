#include "NGfcLightSourceAmbient.h"

using namespace gfc::classes::x3;

NGfcLightSourceAmbient::NGfcLightSourceAmbient()
{
    m_pEntity = new GfcLightSourceAmbient;
    m_bOwner = true;
}

NGfcLightSourceAmbient::NGfcLightSourceAmbient(bool bNoCreate):
    NGfcLightSource(bNoCreate)
{
}

