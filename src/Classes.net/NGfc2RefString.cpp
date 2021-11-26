#include "NGfc2RefString.h"

using namespace gfc::classes::x3;

NGfc2RefString::NGfc2RefString()
{
    m_pEntity = new Gfc2RefString;
    m_bOwner = true;
}

NGfc2RefString::NGfc2RefString(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2RefString::setVal(System::String^ sValue)
{
    ((Gfc2RefString*)m_pEntity)->setVal(marshal_as<std::wstring>(sValue));
}

System::String^ NGfc2RefString::getVal()
{
    return marshal_as<String^>(((Gfc2RefString*)m_pEntity)->getVal());
}

bool NGfc2RefString::hasVal()
{
    return ((Gfc2RefString*)m_pEntity)->hasVal();
}

