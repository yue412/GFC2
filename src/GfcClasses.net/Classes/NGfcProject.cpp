#include "NGfcProject.h"

using namespace gfc::classes::x3;

NGfcProject::NGfcProject()
{
    m_pEntity = new GfcProject;
    m_bOwner = true;
}

NGfcProject::NGfcProject(bool bNoCreate):
    NGfcObject(bNoCreate)
{
}

