#include "NGfcRefString.h"

using namespace gfc::classes::x3;

NGfcRefString::NGfcRefString()
{
    m_pEntity = new GfcRefString;
    m_bOwner = true;
}

NGfcRefString::NGfcRefString(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcRefString::setVal(System::String^ sValue)
{
    ((GfcRefString*)m_pEntity)->setVal(marshal_as<std::wstring>(sValue));
}

System::String^ NGfcRefString::getVal()
{
    return marshal_as<String^>(((GfcRefString*)m_pEntity)->getVal());
}

bool NGfcRefString::hasVal()
{
    return ((GfcRefString*)m_pEntity)->hasVal();
}

