#include "NGfcProject.h"

using namespace gfc::classes::x3;

NGfcProject::NGfcProject()
{
    m_pEntity = new GfcProject;
    m_bOwner = true;
}

NGfcProject::NGfcProject(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcObject(pEntity, bOwner)
{
}

